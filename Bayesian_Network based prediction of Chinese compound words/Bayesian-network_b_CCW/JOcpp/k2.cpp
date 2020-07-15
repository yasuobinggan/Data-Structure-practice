///*
//	k2:
//		基于结构的概率
//	思考:
//		优化评分
//*/
//
////#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<string>
//#include<cstring>
//#include<map>
//#include<unordered_map>
//#include<set>
//#include<fstream>
//#include<sstream>
//
//using namespace std;
//
///*******************************************数据结构 ST*************************************************************************************************/
//
//const int INF = 0x3f3f3f3f;//无穷大
//
////贝叶斯网络中最多可能的属性个数
//const int maxn = 1005;
//
////当前问题的贝叶斯网络的属性数量
//int n = 13;
//
////邻接矩阵存储贝叶斯网络(只存储关系)
//int G[maxn][maxn];
////标记数组
//bool visited[maxn];
//
//
//map<string, int> feature;
//map<int, string> Name;
//
//struct sample {
//	string s_word;//训练词汇
//	string s_1stWB;//第一语素义大类
//	string s_2ndWB;//第二语素义大类
//	string s_1stPosB;//第一词性大类
//	string s_2ndPosB;//第二词性大类
//	string s_TWB;//目标词汇大类
//	string s_1stWM;//第一语素义中类
//	string s_2ndWM;//第二语素义中类
//	string s_TWM;//目标词汇中类
//	string s_1stWS;//第一语素义小类
//	string s_2ndWS;//第二语素义小类
//	string s_1stPosS;//第一词性小类
//	string s_2ndPosS;//第二词性小类
//	string s_TWS;//目标词汇小类
//	string mode;//构词方式类别
//
//	sample() {}
//	sample(string input, string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l, string m, string n)
//	{
//		s_word = input;
//		s_1stWB = a; s_2ndWB = b;
//		s_1stPosB = c; s_2ndPosB = d;
//		s_TWB = e;
//		s_1stWM = f; s_2ndWM = g;
//		s_TWM = h;
//		s_1stWS = i; s_2ndWS = j;
//		s_1stPosS = k; s_2ndPosS = l;
//		s_TWS = m;
//		mode = n;
//	}
//};
//
//
////二级表项
//struct CPtableI
//{
//	int cnt;
//	double pro;
//	CPtableI() {}
//	CPtableI(int _cnt)
//	{
//		cnt = _cnt;
//	}
//	CPtableI(int _cnt, double _pro)
//	{
//		cnt = _cnt;
//		pro = _pro;
//	}
//};
//
////二级表头
//struct  CPtableH
//{
//	int sumcnt;
//	map<string, CPtableI> curCPtableI;
//
//	CPtableH() {}
//	CPtableH(int _sumcnt)
//	{
//		sumcnt = _sumcnt;
//	}
//	CPtableH(int _sumcnt, map<string, CPtableI> _curCPtableI)
//	{
//		sumcnt = _sumcnt;
//		curCPtableI = _curCPtableI;
//	}
//};
//
////建立贝叶斯网络结点:一个结点一个条件概率树(表)
//struct Node {
//	int id;//属性标号
//	string name;//属性名
//
//	//条件概率表
//	map<vector<string>, CPtableH> CPtable;
//
//	//边缘分布表
//	map<string, CPtableI> MD;
//
//	//既为属性的条件属性
//	vector<int> parent;
//	//属性的孩子属性
//	vector<int> child;
//
//	Node() {}
//	Node(int _id, string _name)
//	{
//		id = _id;
//		name = _name;
//	}
//};
//
////贝叶斯网络
//vector<Node> BN;
//
////训练集
//vector<vector<string>> trainingset;
//int trainingsetsize;
//
////属性取值
//map<int, set<string>> av;
//
//
////属性取值数量
//int r[maxn];
//
////属性父结点的取值数量
//vector<int> q[maxn];
//
////前驱数组
//set<int> Pre[maxn];
//
////父属性结点数组
//set<int> Pa[maxn];
//
///*******************************************数据结构 ED*************************************************************************************************/
//
//
//
///********************************************数据预处理 ST**********************************************************************************************/
//void get_dataset()
//{
//	//读训练集(先读.txt文件)
//	ifstream fin;
//	fin.open("d:\\dataset\\dataset.txt", ios::in);
//
//	if (fin)//读取到数据集
//	{
//		string line;//定义读取一行文本的变量
//		vector<string> invec;//获取切割后的字符串序列
//
//		//按行读取
//		while (getline(fin, line))
//		{
//			//判断
//			if (line == "")
//				continue;
//
//			//按'\t'切割二进制流
//			invec.clear();
//			int i = 0;
//			while (i < line.size())
//			{
//				int j = i;
//				string in;
//				in.clear();
//				while (line[j] != '\t' && j < line.size())
//				{
//					in += line[j];
//					j++;
//				}
//				//当in为空时,赋一个特殊值标记(词性小类为空时)
//				if (in == "")
//				{
//					in = "e";
//				}
//
//				invec.push_back(in);
//				i = j + 1;
//			}
//
//			//获取每个属性结点的取值
//			for (int i = 1; i <= 14; i++)
//			{
//				if (invec[i].size() <= 2)
//					av[i].insert(invec[i]);
//			}
//
//
//		}
//
//		//测试输出
//		for (map<int, set<string>>::iterator it = av.begin(); it != av.end(); it++)
//		{
//			cout << "当前属性id：" << it->first;
//			cout << "当前属性取值数量：" << it->second.size() << endl;
//			for (set<string>::iterator itset = it->second.begin(); itset != it->second.end(); itset++)
//			{
//				cout << *itset << " ";
//			}
//			cout << endl;
//			cout << endl;
//		}
//
//
//		fin.close();
//
//	}
//	else
//		cout << "dataset doesn't exist!" << endl;
//
//}
///********************************************数据预处理 ED**********************************************************************************************/
//
//
///********************************************读入训练集 ST**********************************************************************************************/
////利用数据集获取数据的特性(数据预处理)
//void get_trainingset()
//{
//	trainingset.clear();
//	//读训练集(先读.txt文件)
//	ifstream fin;
//	fin.open("d:\\dataset\\dataset.txt", ios::in);
//
//	if (fin)//读取到数据集
//	{
//		string line;//定义读取一行文本的变量
//		vector<string> invec;//获取切割后的字符串序列
//
//		//按行读取
//		while (getline(fin, line))
//		{
//			//判断
//			if (line == "")
//				continue;
//
//			//按'\t'切割二进制流
//			invec.clear();
//			int i = 0;
//			while (i < line.size())
//			{
//				int j = i;
//				string in;
//				in.clear();
//				while (line[j] != '\t' && j < line.size())
//				{
//					in += line[j];
//					j++;
//				}
//				//当in为空时,赋一个特殊值标记(词性小类为空时)
//				if (in == "")
//				{
//					in = "e";
//				}
//
//				invec.push_back(in);
//				i = j + 1;
//			}
//
//
//
//			//读入训练集
//			//sample s = sample(invec[0], invec[1], invec[2], invec[3], invec[4], invec[5], invec[6], invec[7], invec[8], invec[9], invec[10], invec[11], invec[12], invec[13], invec[14]);
//			
//			vector<string> instance;
//			for (int i = 0; i <= 14; i++)
//			{
//				instance.push_back(invec[i]);
//			}
//			trainingset.push_back(instance);
//
//		}
//
//		fin.close();
//
//	}
//	else
//		cout << "dataset doesn't exist!" << endl;
//
//}
///********************************************读入训练集 ED**********************************************************************************************/
//
//
//
///********************************************k2 ST******************************************************************************************************/
////dfs函数生成条件概率表表项
//void build_CPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable)
//{
//	if (index == condition.size())
//	{
//		curCPtable[curcon] = CPtableH(0);
//
//		//建立第二级表项
//		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//		{
//			curCPtable[curcon].curCPtableI[*it] = CPtableI(0);
//		}
//
//		return;
//	}
//
//	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//	{
//		curcon.push_back(*it);
//		build_CPtable(id, condition, index + 1, curcon, curCPtable);
//		curcon.pop_back();
//	}
//}
//
////反复的读取数据
//void generate_nij_nijk(int id,vector<int> condition, map<vector<string>, CPtableH> &curCPtable)
//{
//	//先生成表项
//	int index = 0;//下标控制访问
//	vector<string> curcon;//当前路径上的条件取值
//	curcon.clear();
//
//	//cout << "当前条件概率表表项生成: "<<id<<endl;
//	//dfs建表
//	build_CPtable(id, condition, index, curcon, curCPtable);
//
//
//	//读数据进行(计数)
//	for (vector<vector<string>>::iterator it = trainingset.begin(); it != trainingset.end(); it++)
//	{
//		vector<string> value = *it;
//		vector<string> convalue;
//		for (vector<int>::iterator secondit = condition.begin(); secondit != condition.end(); secondit++)
//		{
//			convalue.push_back(value[*secondit]);
//		}
//		
//		//cout << "SCNT更改前："<< curCPtable[convalue].sumcnt;
//		curCPtable[convalue].sumcnt++;
//		//cout << "\tSCNT更改后：" << curCPtable[convalue].sumcnt;
//		
//		//cout << "\tCNT更改前：" << curCPtable[convalue].curCPtableI[value[id]].cnt;
//		curCPtable[convalue].curCPtableI[value[id]].cnt++;
//		//cout << "\tCNT更改后：" << curCPtable[convalue].curCPtableI[value[id]].cnt;
//
//		//cout << endl;
//
//	}
//
//}
//
//double cal_factor_1(int nij,int ri)
//{
//	double factor = 1;
//	
//	int st = nij + ri - 1;
//	while (nij > 0)
//	{
//		factor *= st;
//		--st;
//		--nij;
//	}
//
//	return factor;
//}
//
//int cal_factor_2(int nijk)
//{
//		
//	double factor = 1;
//	
//	while (nijk > 0)
//	{
//		factor *= nijk;
//		--nijk;
//	}
//
//	return factor;
//}
//
////先生成表项+再计算
//double getscore(int id,set<int> curPa)
//{	
//	vector<int> condition;
//	
//	for (set<int>::iterator it = curPa.begin(); it != curPa.end(); it++)
//	{
//		condition.push_back(*it);
//	}
//
//	//条件概率表
//	map<vector<string>, CPtableH> CPtable;
//
//	//对计算进行预处理
//	generate_nij_nijk(id, condition, CPtable);
//
//	
//
//	cout << Name[id] << endl;
//	int flag1 = 0;//判断输出是否正确
//	int flag2 = 0;//判断输出是否正确
//
//
//	//计算
//	double score = 0;
//	//计算(二层循环)
//	for (map<vector<string>, CPtableH>::iterator it = CPtable.begin(); it != CPtable.end(); it++)
//	{
//		
//		double curscore = 1;
//		for (map<string, CPtableI>::iterator secondit = it->second.curCPtableI.begin(); secondit != it->second.curCPtableI.end(); secondit++)
//		{			
//			
//			
//			double factor2 = cal_factor_2(secondit->second.cnt);
//			if (factor2 != 0)
//			{
//				//curscore += log(cal_factor_2(secondit->second.cnt));
//				curscore *= factor2;
//			}
//
//		}
//		
//		if (it->second.sumcnt != 0)
//		{
//			//flag2 += it->second.sumcnt;
//			//cout << it->second.sumcnt << endl;
//		}
//
//		//curscore *= log(1 / cal_factor_1(it->second.sumcnt, r[id]));
//		curscore *= 1 / cal_factor_1(it->second.sumcnt, r[id]);
//		
//		
//		score += log(curscore);
//
//	}
//	
//
//	//cout << "flag1:" << flag1 << "\t" << "flag2:" << flag2 << endl;
//
//	return score;
//}
//void k2(int limit)
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		Pa[id].clear();
//		//父属性结点为空的特殊处理
//		cout << id << " old评分 ";
//		//double Pold = getscore(id, Pa[id]);
//		double Pold = -INF;
//		cout << Pold << endl;
//
//		bool OKToProcced = true;
//		set<int> curPa = Pa[id];
//
//		while (OKToProcced == true && Pa[id].size() < limit && !Pre[id].empty())
//		{
//
//			
//			set<int>::iterator it = Pre[id].begin();
//			curPa.insert(*it);
//			
//			//输出测试
//			cout << endl << "生成curPa：" << endl;
//			for (set<int>::iterator it = curPa.begin(); it != curPa.end(); it++)
//			{
//				cout << Name[*it] << "\t";
//			}
//			//cout << endl;
//
//			Pre[id].erase(it);
//
//			double Pnew = getscore(id, curPa);
//			//输出
//			cout << id << " new评分 "<< Pnew << endl;
//
//
//			if (Pnew > Pold)
//			{
//				Pold = Pnew;
//
//				Pa[id] = curPa;
//			}
//			else
//				OKToProcced = false;
//
//		}
//		//输出
//		cout << "--------" << endl;
//		cout << "最后评分：" << Pold << endl;
//		cout << endl;
//		cout << Name[id] << "的父结点" << endl;
//		for (set<int>::iterator it = Pa[id].begin(); it != Pa[id].end(); it++)
//		{
//			cout << Name[*it] << "\t\t";
//		}
//		cout << endl;
//		cout << endl;
//		cout << "******************************************" << endl;
//			
//	
//	}
//}
///********************************************k2 ED******************************************************************************************************/
//
//
//int main()
//{
//	//初始化数据
//	//初始化属性取值数量上限
//	memset(r, 0, sizeof(r));
//	//初始化属性标记
//	feature["temp"] = 0;
//	feature["1stWB"] = 1;feature["2ndWB"] = 2;
//	feature["1stPosB"] = 3;feature["2ndPosB"] = 4;
//	feature["TWB"] = 5;
//
//	feature["1stWM"] = 6;feature["2ndWM"] = 7;
//	feature["TWM"] = 8;
//
//	feature["1stWS"] = 9;feature["2ndWS"] = 10;
//	feature["1stPosS"] = 11;feature["2ndPosS"] = 12;
//	feature["TWS"] = 13;
//	
//	for (map<string, int>::iterator it = feature.begin(); it != feature.end(); it++)
//	{
//		Name[it->second] = it->first;
//	}
//	
//
//	//数据预处理
//	cout << endl;
//	cout << "--------------------------------------数据预处理---------------------------------------------" << endl;
//	get_dataset();
//
//
//	//预设初始结点顺序
//	cout << "--------------------------------------预设顺序-----------------------------------------------" << endl;
//	cout << "输入属性结点顺序(1<=&&<=" << n << ")：" << endl;
//
//	vector<int> order;
//	order.push_back(0);
//	//1 2 3 4 5 6 7 8 9 10 11 12 13
//
//	for (int i = 1; i <= n; i++)
//	{
//		int id;
//		cin >> id;
//		order.push_back(id);
//		
//		for (int pi = 1; pi < i; pi++)
//		{
//			Pre[id].insert(order[pi]);
//		}
//	}
//
//	//输出测试
//	for (int i = 1; i <= n; i++)
//	{
//		for (set<int>::iterator it = Pre[i].begin(); it != Pre[i].end(); it++)
//		{
//			cout << *it << "\t";
//		}
//		cout << endl;
//	}
//
//
//
//	//预设属性取值上限
//	for (int id = 1; id <= 13; id++)
//	{
//		r[id] = av[id].size();
//	}
//
//
//	//读入训练集
//	cout << "--------------------------------------读入训练集---------------------------------------------" << endl;
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//
//
//	//k2生成
//	cout << "--------------------------------------k2生成-------------------------------------------------" << endl;
//	int limit;
//	cout << "输入每个属性结点的父结点数量上限：" << endl;
//	cin >> limit;
//	cout << "******************************************" << endl;
//	k2(limit);
//
//
//	//获得贝叶斯网络
//	cout << "--------------------------------------观察贝叶斯网络------------------------------------------" << endl;
//	//get_BN();
//	//最终输出
//	cout << "////////////////////////////////////////////////////////////" << endl;
//	cout << "/////////////////////////最终输出///////////////////////////" << endl;
//	cout << "////////////////////////////////////////////////////////////" << endl;
//	for (int id = 1; id <= 13; id++)
//	{
//		cout << Name[id] << " 父属性结点：" << endl;
//		for (set<int>::iterator it = Pa[id].begin(); it != Pa[id].end(); it++)
//		{
//			cout << Name[*it] << "\t\t";
//		}
//		cout << endl << "******************************************************" << endl;
//	}
//
//	return 0;
//}
