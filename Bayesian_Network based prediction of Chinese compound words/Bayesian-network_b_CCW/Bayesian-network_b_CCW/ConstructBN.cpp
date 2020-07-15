#include"ConstructBN.h"
#include"TreeEncode.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

extern map<string, int> feature;//属性-》标号
extern map<int, string> Name;//标号-》属性

extern map< int, set<string> > av;//属性取值
extern vector<Code> HASH;//属性取值的编码

extern vector<Node> BN;//贝叶斯网络
extern vector<int> tar;//最终搜索的目标属性结点

/**************************************************************建立表 ST********************************************************************************/
//构建边缘分布函数
void construct_MD(int id)
{
	//建立MD:循环遍历目标属性取值
	for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
	{
		BN[id].MD[*it] = CPtableI(0, 0);
	}

}

//获得当棋属性+条件属性编号
vector<int> get_condition_id(int id)
{
	vector<int> condition;
	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		condition.push_back(it->id);
	}
	return condition;
}

//dfs函数生成条件概率表表项
void build_CPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable)
{
	if (index == condition.size())
	{
		curCPtable[curcon] = CPtableH(0);

		//建立第二级表项
		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
		{
			curCPtable[curcon].curCPtableI[*it] = CPtableI(0);
		}

		return;
	}

	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
	{
		curcon.push_back(*it);
		build_CPtable(id, condition, index + 1, curcon, curCPtable);
		curcon.pop_back();
	}
}

//构建条件概率表项
void construct_CPT(int id)
{
	vector<int> condition = get_condition_id(id);
	
	int index = 0;//下标控制访问
	vector<string> curcon;//当前路径上的条件取值
	curcon.clear();

	cout <<" 条件概率表表项生成:";

	//dfs建表
	build_CPtable(id, condition, index, curcon, BN[id].CPtable);

	cout << "\t条件概率表大小: " << BN[id].CPtable.size() << endl;
}

//dfs函数生成条件概率表表项
void build_JPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &curJPtable)
{
	if (index == condition.size())
	{
		curJPtable[curcon] = CPtableI(0);

		return;
	}

	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
	{
		curcon.push_back(*it);
		build_JPtable(id, condition, index + 1, curcon, curJPtable);
		curcon.pop_back();
	}
}

//构建联合分布表项
void construct_JPT(int id)
{
	vector<int> condition = get_condition_id(id);
	condition.push_back(id);

	int index = 0;//下标控制访问
	vector<string> curcon;//当前路径上的条件取值
	curcon.clear();

	cout << " 联合概率分布表表项生成:";

	//dfs建表
	build_JPtable(id, condition, index, curcon, BN[id].JPtable);

	cout << "\t联合概率分布表大小: " << BN[id].JPtable.size() << endl;

}

//统一构建******************************************************************************************
void build_CPtable_JPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable, map<vector<string>, CPtableI> &curJPtable)
{
	if (index == condition.size())
	{
		curCPtable[curcon] = CPtableH(0);

		
		vector<string> curj = curcon;
		//建立第二级表项
		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
		{
			//条件概率表第二级表项
			curCPtable[curcon].curCPtableI[*it] = CPtableI(0);
			

			//联合概率分布表项
			curj.push_back(*it);
			curJPtable[curj] = CPtableI(0);
			curj.pop_back();

		}

		return;
	}

	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
	{
		curcon.push_back(*it);
		build_CPtable_JPtable(id, condition, index + 1, curcon, curCPtable, curJPtable);
		curcon.pop_back();
	}


}

void construct_JPT_CPT(int id)
{
	vector<int> condition = get_condition_id(id);
	//condition.push_back(id);

	//建立条件概率表*******************************************
	int index = 0;//下标控制访问
	vector<string> curcon;//当前路径上的条件取值
	curcon.clear();

	cout << " 条件概率表表项生成\t联合概率分布表表项生成";
	//dfs建表
	build_CPtable_JPtable(id, condition, index, curcon, BN[id].CPtable, BN[id].JPtable);

	cout << "\t条件概率表大小: " << BN[id].CPtable.size() << endl; cout << "\t联合概率分布表大小: " << BN[id].JPtable.size() << endl;

	
	
}
/**************************************************************建立表 ED********************************************************************************/



/**************************************************************建立条件概率树 ST************************************************************************/
void build_CPtree(int id, vector<int> condition, int index, vector<string> curcon, Treenode &curCPtree, int &cnt)
{
	if (index == condition.size())//概率结点
	{
		curCPtree.sumcnt = 0;
		curCPtree.cnt = 0;
		curCPtree.pro = 0;
		curCPtree.child = NULL;

		cnt++;
		//测试输出
		/*
		//if(id==13)
		//{
			cout << "表项生成：";
			for (vector<string>::iterator it = curcon.begin(); it != curcon.end(); it++)
			{
				cout << *it << "\t";
			}
			cout << endl;	
		//}
		*/

		return;
	}
	else//建立分支结点
	{
		curCPtree.id = condition[index];
		if (index == condition.size())//叶子结点
			curCPtree.flag = true;
		else//叶子结点以上
			curCPtree.flag = false;
		curCPtree.sumcnt = 0;
		curCPtree.cnt = 0;
		curCPtree.pro = 0;
		curCPtree.child = new Treenode[105];
		
		for (int i = 0; i < 75; i++)
		{
			if (HASH[curCPtree.id].sti[i] != "")
			{
				Treenode childnode;
				childnode.value = HASH[curCPtree.id].sti[i];
				childnode.valueid = i;

				curcon.push_back(childnode.value);
				build_CPtree(id, condition, index + 1, curcon, childnode, cnt);
				//回溯
				//TODO
				curCPtree.child[i] = childnode;
				curcon.pop_back();
			}
			
		}

	}

}

void construct_CPtree(int id)
{
	vector<int> condition = get_condition_id(id);
	condition.push_back(id);

	//建立条件概率树*******************************************
	int index = 0;//下标控制访问
	vector<string> curcon;//当前路径上的条件取值
	curcon.clear();
	int cnt = 0;

	cout << Name[id] << "\t条件概率树生成：" << endl;

	//dfs建表
	build_CPtree(id, condition, index, curcon, BN[id].CPtree, cnt);

	//cout << BN[id].CPtree.id << endl;
	cout << "条件概率表建立完成！底层表项大小：" << cnt << endl;
}
/**************************************************************建立条件概率树 ED************************************************************************/


//构建贝叶斯网络
void construct_BayesianNW()
{
	//建立结点
	Node temp(0, "temp");

	Node WB1(1, "1stWB");
	Node WB2(2, "2ndWB");
	Node PosB1(3, "1stPosB");
	Node PosB2(4, "2ndPosB");
	Node TWB(5, "TWB");
	Node WM1(6, "1stWM");
	Node WM2(7, "2ndWM");
	Node TWM(8, "TWM");
	Node WS1(9, "1stWS");
	Node WS2(10, "2ndWS");
	Node PosS1(11, "1stPosS");
	Node PosS2(12, "2ndPosS");
	Node TWS(13, "TWS");

	//MWST关系：
	/*
	PosB1.parent.push_back(WB1); WB1.child.push_back(PosB1);
	WM1.parent.push_back(WS1); WS1.child.push_back(WM1);
	PosS2.parent.push_back(WS1); WS1.child.push_back(PosS2);
	PosB2.parent.push_back(WB2); WB2.child.push_back(PosB2);
	TWB.parent.push_back(WB2); WB2.child.push_back(TWB);
	WB2.parent.push_back(WM2); WM2.child.push_back(WB2);
	WM2.parent.push_back(TWS); TWS.child.push_back(WM2);
	TWM.parent.push_back(TWS); TWS.child.push_back(TWM);
	WS2.parent.push_back(TWS); TWS.child.push_back(WS2);
	PosS1.parent.push_back(TWS); TWS.child.push_back(PosS1);
	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
	WB1.child.push_back(WS1); WS1.parent.push_back(WB1);
	*/	

	
	//建立结点间关系
	WB1.child.push_back(TWB); TWB.parent.push_back(WB1);
	WB2.child.push_back(TWB); TWB.parent.push_back(WB2);
	PosB1.child.push_back(TWB); TWB.parent.push_back(PosB1);
	PosB2.child.push_back(TWB); TWB.parent.push_back(PosB2);

	WB1.child.push_back(WM1); WM1.parent.push_back(WB1);
	WB2.child.push_back(WM2); WM2.parent.push_back(WB2);
	TWB.child.push_back(TWM); TWM.parent.push_back(TWB);
	WM1.child.push_back(TWM); TWM.parent.push_back(WM1);
	WM2.child.push_back(TWM); TWM.parent.push_back(WM2);

	WM1.child.push_back(WS1); WS1.parent.push_back(WM1);
	WM2.child.push_back(WS2); WS2.parent.push_back(WM2);

	
	//TWM.child.push_back(TWS); TWS.parent.push_back(TWM);
	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
	WS2.child.push_back(TWS); TWS.parent.push_back(WS2);
	PosS1.child.push_back(TWS); TWS.parent.push_back(PosS1);
	PosS2.child.push_back(TWS); TWS.parent.push_back(PosS2);
	


	//结点加入贝叶斯网络(以后按序号访问+处理)
	BN.push_back(temp);
	BN.push_back(WB1); BN.push_back(WB2);
	BN.push_back(PosB1); BN.push_back(PosB2);
	BN.push_back(TWB);
	//
	BN.push_back(WM1); BN.push_back(WM2);
	BN.push_back(TWM);
	//
	BN.push_back(WS1); BN.push_back(WS2);
	BN.push_back(PosS1); BN.push_back(PosS2);
	BN.push_back(TWS);

	//建立边缘分布表:
	
	//方法一: 每个结点的条件概率表,边缘分布表(只开空间不输入数据)
	/*
	for (int id = 1; id <= 13; id++)
	{
		cout << "id: " << id << "属性名称: " << BN[id].name << "\t边缘概率分布表表项生成: "<<endl;
		construct_MD(id);
	}
	
	//建立要最终推断的联合分布表+条件分布表
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		cout << BN[*it].name << endl;
		//construct_JPT(*it);
		//construct_CPT(*it);
		construct_JPT_CPT(*it);
	}
	*/

	//方法二:建立条件概率树
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		construct_CPtree(*it);
	}
}