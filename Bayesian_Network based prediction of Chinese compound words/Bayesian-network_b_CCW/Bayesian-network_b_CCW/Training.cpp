#include"GetDataset.h"
#include"TreeEncode.h"
#include"ConstructBN.h"
#include"Training.h"

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


extern vector< vector<string> > trainingset;//训练集
extern int trainingsetsize;//训练集的大小

extern map< int, set<string> > av;//属性取值
extern int r[];//属性取值数量
extern vector<Code> HASH;//属性取值的编码


extern vector<int> tar;//最终搜索的目标属性结点
extern vector<Node> BN;//贝叶斯网络


//对条件概率树进行计数
void count_CPtree(int id, vector<string> invec)
{
	vector<int> curcondition;
	vector<string> com;

	cout << "当前样本的取值编号（相应于" << Name[id] << "）：";
	cout << "当前取值：";
	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		curcondition.push_back(it->id);
		com.push_back(invec[it->id]);

		cout << invec[it->id] << "\t";
	}


	Treenode* curnode = &BN[id].CPtree;
	
	for (int i = 0; i < com.size(); i++)
	{
		int index = find(curcondition[i], com[i]);
		//cout << index << "\t";
		curnode = &(curnode->child[index]);
	}
	(curnode->sumcnt)++;

	cout << invec[id];
	Treenode* leafnode = &(curnode->child[find(id, invec[id])]);
	leafnode->sumcnt = curnode->sumcnt;
	(leafnode->cnt)++;

	cout << "\t\t\t\t";
	cout << "SUMCNT：" << leafnode->sumcnt << "  CNT：" << leafnode->cnt;
	cout << endl;
}

//计算条件概率树的概率
void cal_CPtree(int id, int depth, Treenode &curCPtree)
{
	if (depth == BN[id].parent.size() + 1)
	{
		if (curCPtree.sumcnt != 0)
		{
			curCPtree.pro = (double)curCPtree.cnt / (double)curCPtree.sumcnt;
			cout << "当前概率：" << curCPtree.pro << endl;
		}
		else if (curCPtree.sumcnt == 0)
		{
			curCPtree.pro = 1 / (double)r[id];
		}
		
		return;
	}
	else
	{
		for (int i = 0; i < 75; i++)
		{
			if (HASH[curCPtree.id].sti[i] != "")
			{
				cal_CPtree(id, depth + 1, curCPtree.child[i]);
			}
			
		}
	}
}

//对联合概率分布表进行计数
void count_JPtable(int id, vector<string> invec)
{
	
	
	//从样例中提取当前点的条件->条件概率表
	vector<string> com;

	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		com.push_back(invec[it->id]);
	}
	com.push_back(invec[id]);


	//输出测试
	cout << "表项是否存在: " << BN[id].JPtable.count(com) << "\t";
	cout << "初值:" << BN[id].JPtable[com].cnt << "\t";

	++BN[id].JPtable[com].cnt;
	
	cout << "更改后:" << BN[id].JPtable[com].cnt << "\t";
	cout << endl;

}

//获取训练集
void get_trainingset()
{
	trainingset.clear();
	//读训练集(先读.txt文件)
	ifstream fin;

	fin.open("d:\\datasetG\\trainingdataset.txt", ios::in);

	//TODO
	//cout << "联合概率表计数: " << endl;

	if (fin)//读取到数据集
	{
		string line;//定义读取一行文本的变量
		vector<string> invec;//获取切割后的字符串序列
		int count = 0;
		map<string, int> cnt;
		cnt.clear();

		//按行读取
		while (getline(fin, line))
		{
			//判断
			if (line == "")
				continue;

			invec.clear();
			int i = 0;

			//按'\t'切割二进制流
			while (i < line.size())
			{
				int j = i;
				string in;
				in.clear();
				while (line[j] != '\t' && j < line.size())
				{
					in += line[j];
					j++;
				}
				//当in为空时,赋一个特殊值标记(词性小类为空时)
				if (in == "")
				{
					in = "e";
				}

				//读入
				invec.push_back(in);
				i = j + 1;
			}


			//进行数据计数
			for (int id = 1; id <= 13; id++)
			{
				//边缘分布表计数
				//TODO
				//BN[id].MD[invec[id]].cnt++;

				//联合概率分布表计数
				if (id == 5 || id == 8 || id == 13)
				{
					//TODO
					//count_JPtable(id, invec);

					cout << "条件概率树计数：" << endl;
					count_CPtree(id, invec);
					
				}
				//cout << endl;
			}
			
			//读入训练集
			vector<string> instance;
			for (int i = 0; i <= 14; i++)
			{
				instance.push_back(invec[i]);
			}
			trainingset.push_back(instance);
			
		}


		trainingsetsize = trainingset.size();
		cout << "训练集大小:\t" << trainingsetsize << endl;
		fin.close();

	}
	else
		cout << "dataset doesn't exist!" << endl;

}

//计算边缘概率分布表的概率
void cal_MDpro(int id)
{
	for (map<string, CPtableI>::iterator it = BN[id].MD.begin(); it != BN[id].MD.end(); it++)
	{
		it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
		if (it->second.pro != 0)
		{
			//输出测试
			cout << Name[id] << ": " << it->first << "\tEP: " << it->second.pro << endl;
		}
			
	}
	
}

void cal_MD()
{
	cout << "训练边缘概率表: **************************************************" << endl;

	for (int id = 1; id <= 13; id++)
	{
		cal_MDpro(id);
	}

}

//计算联合概率分布
void cal_JPpro(int id)
{
	for (map<vector<string>, CPtableI>::iterator it = BN[id].JPtable.begin(); it != BN[id].JPtable.end(); it++)
	{
		it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
		if (it->second.pro != 0)
		{
			vector<string> out = it->first;
			for (vector<string>::iterator secondit = out.begin(); secondit != out.end(); secondit++)
			{
				cout << *secondit << "\t";
			}
			cout << "\tJP: " << it->second.pro << endl;
		}
			
	}
}

void cal_JPtable()
{
	cout << "训练联合概率表: **************************************************" << endl;
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		cout << Name[*it] <<"\t"<< endl;
		cal_JPpro(*it);
	}
}

//计算条件概率
double cal_mulJP(int id, vector<string> con)
{
	double mulJP = 1;

	int index = 0;//con的访问标记

	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
	{
		if (BN[it->id].MD[con[index]].pro == 0)
		{
			return 0.0;
		}
		//cout << BN[it->id].MD[con[index]].pro << "\t";
		mulJP *= BN[it->id].MD[con[index]].pro;

		index++;
	}

	return mulJP;
}

void cal_CPpro(int id)
{
	for (map<vector<string>, CPtableI>::iterator it = BN[id].JPtable.begin(); it != BN[id].JPtable.end(); it++)
	{
		
		vector<string> convalue = it->first;

		string tarvalue = convalue.back();
		convalue.pop_back();
		//输出测试
		/*
		cout << endl << "条件取值：\t";
		for (vector<string>::iterator it = convalue.begin(); it != convalue.end(); it++)
		{
			cout << *it << "\t";
		}
		//cout << endl;
		cout << "目标\t" << Name[id] << "\t" << tarvalue << endl;
		*/

		
		//获取分子联合概率
		double factor1 = it->second.pro;
		//输出
		/*
		if(factor1 != 0)
			cout << "第一因子: " << factor1 << endl;
		*/
		

		//获取分母边缘概率连乘
		double factor2 = cal_mulJP(id, convalue);
		//输出
		/*
		cout << endl;
		if(factor2 != 0)
			cout << "第二因子: " << factor2 << "\t";
		*/
		
		//条件概率计算+输入到对应表项

		//对零值的处理
		if (factor2 == 0)
		{
			//输出测试
			//cout << "\tr" << id << "  " << r[id] << endl;
			
			BN[id].CPtable[convalue].curCPtableI[tarvalue].pro = (1 / (double)r[id]);
			//cout << " *0*\tCP: " << BN[id].CPtable[convalue].curCPtableI[tarvalue].pro << endl;
		}
		else
		{
			BN[id].CPtable[convalue].curCPtableI[tarvalue].pro = (factor1 / factor2);
			
			//输出测试
			//cout << " *jisuan*\tCP: " << BN[id].CPtable[convalue].curCPtableI[tarvalue].pro << endl;
		}


		//输出测试
		/*
		if (BN[id].CPtable[convalue].curCPtableI[tarvalue].pro != 0)
		{
			cout << "CP: " << BN[id].CPtable[convalue].curCPtableI[tarvalue].pro << endl;
		}
		*/
		
	}
}

void cal_CPtable()
{
	cout << "训练条件概率表: **************************************************" << endl;
	for (vector<int>::iterator it=tar.begin(); it != tar.end(); it++)
	{
		cal_CPpro(*it);
	}
}


//总训练函数
void train()
{
	/*
	cal_MD();
	cal_JPtable();
	cal_CPtable();
	*/

	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++)
	{
		cal_CPtree(*it, 0, BN[*it].CPtree);
	}
	
}