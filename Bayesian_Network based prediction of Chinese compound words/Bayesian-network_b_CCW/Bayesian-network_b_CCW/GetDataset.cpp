#include"GetDataset.h"
#include"ConstructBN.h"
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


extern map< int, set<string> > av;//属性取值


//利用数据集获取数据的特性(数据预处理)
void get_dataset()
{

	ifstream fin;
	fin.open("d:\\datasetG\\dataset.txt", ios::in);

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
			if (line == "")
				continue;
			//cout << line << endl;
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
				/******************************************/
				//当in为空时,赋一个特殊值标记(词性小类为空时)
				if (in == "")
				{
					in = "e";
				}
				/*****************************************/
				invec.push_back(in);
				i = j + 1;
			}

			//获取每个属性结点的取值
			for (int i = 1; i <= 14; i++)
			{
				if (invec[i].size() <= 2)
					av[i].insert(invec[i]);
			}

		}


		//测试输出

		for (map<int, set<string> >::iterator it = av.begin(); it != av.end(); it++)
		{
			cout << "当前id：" << it->first;// << "当前属性: " << BN[it->first].name;
			cout << "当前大小：" << it->second.size() << endl;
			for (set<string>::iterator itset = it->second.begin(); itset != it->second.end(); itset++)
			{
				cout << *itset << " ";
			}
			cout << endl;
			cout << endl;
		}


		fin.close();

	}
	else
		cout << "dataset doesn't exist!" << endl;

}


