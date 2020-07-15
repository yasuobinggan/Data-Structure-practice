#include"TreeEncode.h"
#include"ConstructBN.h"
#include"Inferencing.h"


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


extern vector<Node> BN;//贝叶斯网络
extern vector<int> tar;//最终搜索的目标属性结点

extern vector<Code> HASH;//属性取值的编码

vector<string> testsampleCPtree(vector<string> invec)
{
	vector<string> hypo;//假设

	//匹配词汇大类
	//进入到叶子结点
	vector<string> comTWB;

	Treenode curnode = BN[5].CPtree;
	for (vector<Node>::iterator it = BN[5].parent.begin(); it != BN[5].parent.end(); it++)
	{
		int index = find(it->id, invec[it->id]);
		curnode = curnode.child[index];
	}
	
	//匹配
	string maxvalue;
	double maxpro = -1.0;

	for (int i = 0; i < 105; i++)
	{
		if (curnode.child[i].pro > maxpro)
		{
			maxvalue = curnode.child[i].value;
			maxpro = curnode.child[i].pro;
		}
	}
	
	hypo.push_back(maxvalue);


	//匹配词汇中类
	//记录
	vector<string> comTWM;

	curnode = BN[8].CPtree;
	for (vector<Node>::iterator it = BN[8].parent.begin(); it != BN[8].parent.end(); it++)
	{
		int index = find(it->id, invec[it->id]);
		curnode = curnode.child[index];
	}

	//匹配
	maxvalue = "";
	maxpro = -1.0;

	for (int i = 0; i < 105; i++)
	{
		if (curnode.child[i].pro > maxpro)
		{
			maxvalue = curnode.child[i].value;
			maxpro = curnode.child[i].pro;
		}
	}

	hypo.push_back(maxvalue);


	//匹配词汇小类
	//记录
	vector<string> comTWS;

	curnode = BN[13].CPtree;
	for (vector<Node>::iterator it = BN[13].parent.begin(); it != BN[13].parent.end(); it++)
	{
		int index = find(it->id, invec[it->id]);
		curnode = curnode.child[index];
	}

	//匹配
	maxvalue = "";
	maxpro = -1.0;

	for (int i = 0; i < 105; i++)
	{
		if (curnode.child[i].pro > maxpro)
		{
			maxvalue = curnode.child[i].value;
			maxpro = curnode.child[i].pro;
		}
	}

	hypo.push_back(maxvalue);


	return hypo;
}


vector<string> testsample(vector<string> invec)
{
	vector<string> hypo;//假设

	//匹配词汇大类
	//记录
	vector<string> comTWB;

	for (vector<Node>::iterator it = BN[5].parent.begin(); it != BN[5].parent.end(); it++)
	{
		comTWB.push_back(invec[it->id]);
	}
	//匹配
	string maxvalue;
	double maxpro = -1.0;

	for (map<string, CPtableI>::iterator it = BN[5].CPtable[comTWB].curCPtableI.begin(); it != BN[5].CPtable[comTWB].curCPtableI.end(); it++)
	{
		if (it->second.pro > maxpro)
		{
			maxvalue = it->first;
			maxpro = it->second.pro;
		}
	}

	hypo.push_back(maxvalue);


	//匹配词汇中类
	//记录
	vector<string> comTWM;

	for (vector<Node>::iterator it = BN[8].parent.begin(); it != BN[8].parent.end(); it++)
	{
		comTWM.push_back(invec[it->id]);
	}

	//匹配
	maxvalue = "";
	maxpro = -1.0;

	for (map<string, CPtableI>::iterator it = BN[8].CPtable[comTWM].curCPtableI.begin(); it != BN[8].CPtable[comTWM].curCPtableI.end(); it++)
	{
		if (it->second.pro > maxpro)
		{
			maxvalue = it->first;
			maxpro = it->second.pro;
		}
	}

	hypo.push_back(maxvalue);


	//匹配词汇小类
	//记录
	vector<string> comTWS;

	for (vector<Node>::iterator it = BN[13].parent.begin(); it != BN[13].parent.end(); it++)
	{
		comTWS.push_back(invec[it->id]);
	}

	//匹配
	maxvalue = "";
	maxpro = -1.0;

	for (map<string, CPtableI>::iterator it = BN[13].CPtable[comTWS].curCPtableI.begin(); it != BN[13].CPtable[comTWS].curCPtableI.end(); it++)
	{
		if (it->second.pro > maxpro)
		{
			maxvalue = it->first;
			maxpro = it->second.pro;
		}
	}

	hypo.push_back(maxvalue);



	return hypo;
}


void test()
{

	//查询目标结点的条件概率表
	ifstream fin;
	fin.open("d:\\datasetG\\testdataset.txt", ios::in);



	if (fin)//读取到数据集
	{
		int testsize = 0;//训练集大小

		string line;//定义读取一行文本的变量
		vector<string> invec;//获取切割后的字符串序列

							 //记录准确率
		int sumcount = 0;

		double expection = 0;


		//按行读取
		while (getline(fin, line))
		{
			//判断
			if (line == "")
				continue;

			//按'\t'切割二进制流
			invec.clear();
			int i = 0;
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
				invec.push_back(in);
				i = j + 1;
			}

			//推断+推断结果
			vector<string> hypo = testsampleCPtree(invec);


			//词汇大类
			cout << "词汇大类标准取值: " << invec[5] << " ";
			cout << "推断词汇大类取值" << hypo[0] << "\t|\t";


			//词汇中类
			cout << "词汇中类标准取值: " << invec[8] << " ";
			cout << "推断词汇中类取值" << hypo[1] << "\t|\t";

			//词汇小类
			cout << "词汇小类标准取值: " << invec[13] << " ";
			cout << "推断词汇小类取值" << hypo[2] << endl;



			//计算期望
			double curexpection = 0;
			if (invec[5] == hypo[0])
			{
				curexpection += 1;
			}
			if (invec[8] == hypo[1])
			{
				curexpection += 1;
			}
			if (invec[13] == hypo[2])
			{
				curexpection += 1;
			}

			curexpection /= 3;
			expection += curexpection;


			//匹配计数
			if (invec[5] == hypo[0] && invec[8] == hypo[1] && invec[13] == hypo[2])
			{
				sumcount++;
			}


			++testsize;
		}

		//输出模型的准确率,期望
		cout << endl << "********************************************************************" << endl;
		cout << "当前模型的完全准确率: " << (double)sumcount / (double)testsize << endl;
		cout << "当前模型的期望: " << ((double)1 / (double)testsize) * expection << endl;

		fin.close();

	}
	else
		cout << "dataset doesn't exist!" << endl;
}

