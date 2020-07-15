////以有向无环图的顺序建立函数
//
//
///**
//* 联合概率分布:P(1st WB,2nd WB,1st PosB,2nd PosB,1st WM,2nd WM,1st WS,2nd WS,1st PosS,2nd PosS,TWB,TWM,TWS)
//*			   P(1st WB)P(2ndWB)P(1stPosB)P(2ndPosB)   * P(TWB |1st WB,2nd WB,1st PosB,2nd PosB)
//*		       P(1st WM|1st WB)P(2nd WM|2nd WB)        * P(TWM |1st WM,2nd WM)
//*		       P(1st WS|1st WM)P(2nd WS|2nd WM)P(1st PosS)P(2nd PosS)* P(TWS |1st WS,2nd WS,1st PosS,2nd PosS)
//*/
//
///**
//* 各属性概率:
//* 1：P(1st WB);
//* 2：P(2nd WB);
//* 3：P(1st PosB);
//* 4：P(2nd PosB);
//* 5：P(TWB)= P(TWB |1st WB,2nd WB,1st PosB,2nd PosB)*P(1stWB)*P(2ndWB)*P(1stPosB)*P(2ndPosB)
//* 6：P(1st WM)= P(1st WM|1st WB)*P(1st WB)
//* 7：P(2nd WM)= P(2nd WM|2nd WB)*P(2nd WB)
//* 8：P(TWM) = P(TWM |1st WM,2nd WM)*P(1st WM)*P(2nd WM)
//* 9：P(1st WS) = P(1st WS|1st WM)*P(1st WM)
//* 10：P(2nd WS) = P(2nd WS|2nd WM)*P(2nd WM)
//* 11：P(1st PosS)
//* 12：P(2nd PosS)
//* 13：P(TWS) = P(TWS |1st WS,2nd WS,1st PosS,2nd PosS)*P(1st WS)*P(2nd WS)*P(1st PosS)*P(2nd PosS)
//*/
//
//
////JOcpp
////#include<bits/stdc++.h>
//
//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#include<fstream>
//#include<sstream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<string>
//#include<cstring>
//#include<map>
//#include<unordered_map>
//#include<set>
//#include<unordered_set>
//#include<ctime>
//
//using namespace std;
//
//
///*******************************************数据结构 ST*************************************************************************************************/
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
//vector<vector<string>> trainingset;//训练集
//int trainingsetsize;
//map< int, set<string> > av;//属性取值
//
///*条件概率表定义 ST*/
////二级表项
//struct CPtableI
//{
//	int cnt;
//	double pro;
//	int boxsum;
//	CPtableI() {}
//	CPtableI(int _cnt)
//	{
//		cnt = _cnt;
//	}
//
//	CPtableI(int _cnt, int _boxsum)
//	{
//		cnt = _cnt;
//		pro = _boxsum;
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
///*条件概率表定义 ED*/
//
//
//
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
//	vector<Node> parent;
//	//属性的孩子属性
//	vector<Node> child;
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
//
//
//const int INF = 0x3f3f3f3f;//无穷大
//
////贝叶斯网络中最多可能的属性个数
//const int maxn = 1005;
//
////邻接矩阵存储贝叶斯网络(只存储关系)
//int G[maxn][maxn];
////目标数组
//vector<int> tar;
////标记数组
//bool visited[maxn];
////距离数组
//int d[maxn];
//
//
///*******************************************数据结构 ED*************************************************************************************************/
//
//
//
///********************************************数据预处理 ST**********************************************************************************************/
//void initProblem()
//{
//	//初始化属性标记
//	feature["temp"] = 0;
//	feature["1stWB"] = 1; feature["2ndWB"] = 2;
//	feature["1stPosB"] = 3; feature["2ndPosB"] = 4;
//	feature["TWB"] = 5;
//
//	feature["1stWM"] = 6; feature["2ndWM"] = 7;
//	feature["TWM"] = 8;
//
//	feature["1stWS"] = 9; feature["2ndWS"] = 10;
//	feature["1stPosS"] = 11; feature["2ndPosS"] = 12;
//	feature["TWS"] = 13;
//
//	for (map<string, int>::iterator it = feature.begin(); it != feature.end(); it++)
//	{
//		Name[it->second] = it->first;
//	}
//}
//
//
////利用数据集获取数据的特性(数据预处理)
//void get_dataset()
//{
//
//	ifstream fin;
//	fin.open("d:\\datasetG\\trainingdataset.txt", ios::in);
//
//	if (fin)//读取到数据集
//	{
//		string line;//定义读取一行文本的变量
//		vector<string> invec;//获取切割后的字符串序列
//		int count = 0;
//		map<string, int> cnt;
//		cnt.clear();
//
//		//按行读取
//		while (getline(fin, line))
//		{
//			if (line == "")
//				continue;
//			//cout << line << endl;
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
//				/******************************************/
//				//当in为空时,赋一个特殊值标记(词性小类为空时)
//				if (in == "")
//				{
//					in = "e";
//				}
//				/*****************************************/
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
//		}
//
//
//		//测试输出
//
//		for (map<int, set<string> >::iterator it = av.begin(); it != av.end(); it++)
//		{
//			cout << "当前属性id：" << it->first;// << "当前属性: " << BN[it->first].name;
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
//
///********************************construct_BN  ST*******************************************************************************************************/
///*****************construct_CPtable ST*********************/
////获得当前属性的马尔可夫毯(基于MSWT)(基于图可以使用set去重)
//vector<int> get_condition_id(int id)
//{
//	vector<int> condition;
//	
//	if(id!=13)
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//
//	for (vector<Node>::iterator it = BN[id].child.begin(); it != BN[id].child.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//
//	return condition;
//}
//
//
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
//			curCPtable[curcon].curCPtableI[*it] = CPtableI(0,0);
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
//
////总构建函数
//void construct_CPtable(int id)
//{
//	vector<int> condition = get_condition_id(id);
//
//
//	//建立CPtable:
//	//条件为空
//	if (condition.size() == 0)
//	{
//		return;
//	}
//	//条件不为空
//	else
//	{
//		int index = 0;//下标控制访问
//		vector<string> curcon;//当前路径上的条件取值
//		curcon.clear();
//
//		cout << id << "\t" << Name[id] << "条件概率表表项生成:";
//
//		//dfs建表
//		build_CPtable(id, condition, index, curcon, BN[id].CPtable);
//
//		cout << " \t条件概率表大小: " << BN[id].CPtable.size() << endl;
//
//	}
//
//}
///*****************construct_CPtable ED*********************/
//
//
////构建贝叶斯网络
//void construct_BayesianNW()
//{
//	//建立结点
//	Node temp(0, "temp");
//	Node WB1(1, "1stWB");Node WB2(2, "2ndWB");
//	Node PosB1(3, "1stPosB");Node PosB2(4, "2ndPosB");
//	Node TWB(5, "TWB");
//	
//	Node WM1(6, "1stWM");Node WM2(7, "2ndWM");
//	Node TWM(8, "TWM");
//	
//	Node WS1(9, "1stWS");Node WS2(10, "2ndWS");
//	Node PosS1(11, "1stPosS");Node PosS2(12, "2ndPosS");
//	Node TWS(13, "TWS");
//
//	//建立结点间关系
//	
//	//MWST关系：
//	PosB1.parent.push_back(WB1); WB1.child.push_back(PosB1);
//	WM1.parent.push_back(WS1); WS1.child.push_back(WM1);
//	PosS2.parent.push_back(WS1); WS1.child.push_back(PosS2);
//	PosB2.parent.push_back(WB2); WB2.child.push_back(PosB2);
//	TWB.parent.push_back(WB2); WB2.child.push_back(TWB);
//	WB2.parent.push_back(WM2); WM2.child.push_back(WB2);
//	WM2.parent.push_back(TWS); TWS.child.push_back(WM2);
//	TWM.parent.push_back(TWS); TWS.child.push_back(TWM);
//	WS2.parent.push_back(TWS); TWS.child.push_back(WS2);
//	PosS1.parent.push_back(TWS); TWS.child.push_back(PosS1);
//	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
//	WB1.child.push_back(WS1); WS1.parent.push_back(WB1);
//	
//
//	//结点加入贝叶斯网络(以后按序号访问+处理)
//	BN.push_back(temp);
//	BN.push_back(WB1); BN.push_back(WB2);
//	BN.push_back(PosB1); BN.push_back(PosB2);
//	BN.push_back(TWB);
//	//
//	BN.push_back(WM1); BN.push_back(WM2);
//	BN.push_back(TWM);
//	//
//	BN.push_back(WS1); BN.push_back(WS2);
//	BN.push_back(PosS1); BN.push_back(PosS2);
//	BN.push_back(TWS);
//
//	//建立:
//	//方法一: 每个结点的条件概率表,边缘分布表(只开空间不输入数据)
//	for (int id = 1; id <= 13; id++)
//	{
//		construct_CPtable(id);
//	}
//	
//}
///*****************************construct_BN ED***********************************************************************************************************/
//
//
//
///********************************get_Trainingset  ST****************************************************************************************************/
////计数函数
//void count_CPtable(int id, vector<string> invec)
//{
//	//从样例中提取当前点的条件->条件概率表
//
//	vector<string> com;
//
//	if (id != 13)
//		for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//		{
//			com.push_back(invec[it->id]);
//		}
//
//	for (vector<Node>::iterator it = BN[id].child.begin(); it != BN[id].child.end(); it++)
//	{
//		com.push_back(invec[it->id]);
//	}
//
//
//	//输出测试
//	cout << "表项是否存在: " << BN[id].CPtable.count(com) << "\t";
//	
//
//	cout << "sumcnt:" << BN[id].CPtable[com].sumcnt << "\t";
//	++BN[id].CPtable[com].sumcnt;
//	cout << "Gsumcnt:" << BN[id].CPtable[com].sumcnt << "\t";
//
//	cout << "cnt:" << BN[id].CPtable[com].curCPtableI[invec[id]].cnt << "\t";
//	++BN[id].CPtable[com].curCPtableI[invec[id]].cnt;
//	cout << "Gcnt:" << BN[id].CPtable[com].curCPtableI[invec[id]].cnt << "\t";
//	
//	cout << endl;
//
//
//}
//
//
////获取训练集
//void get_trainingset()
//{
//	trainingset.clear();
//	//读训练集(先读.txt文件)
//	ifstream fin;
//	fin.open("d:\\datasetG\\trainingdataset.txt", ios::in);
//
//	if (fin)//读取到数据集
//	{
//		string line;//定义读取一行文本的变量
//		vector<string> invec;//获取切割后的字符串序列
//		int count = 0;
//		map<string, int> cnt;
//		cnt.clear();
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
//			//进行数据计数
//			for (int id = 1; id <= 13; id++)
//			{
//				//TODO
//				count_CPtable(id, invec);
//
//			}
//			//读入训练集
//			
//			trainingset.push_back(invec);
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
///********************************get_Trainingset  ED****************************************************************************************************/
//
//
//
///**************************************************train_CPtable ST*************************************************************************************/
////进行概率计算
//void train_CPtable(int id)
//{
//	//条件概率
//	if (BN[id].parent.size() != 0)
//	{
//
//		for (map<vector<string>, CPtableH>::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//
//			for (map<string, CPtableI>::iterator secondit = it->second.curCPtableI.begin(); secondit != it->second.curCPtableI.end(); secondit++)
//			{
//
//				if (it->second.sumcnt != 0)
//				{
//		
//					secondit->second.pro = (double)secondit->second.cnt / (double)it->second.sumcnt;
//					
//				}
//				else
//				{
//					secondit->second.pro = (double)1 / (double)av[id].size();
//				}
//
//
//			}
//		}
//	}
//
//
//}
//
//
////总训练函数
//void trainBN()
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		cout << "计算相关概率\t" << id << endl;
//		train_CPtable(id);
//		cout << "***************************************" << endl;
//	}
//}
///**************************************************train_CPtable ED*************************************************************************************/
//
//
//
////双音节词问题总函数
//void BN_CP_construct()
//{
//	cout << "*************************精确推理:枚举推理**************************************" << endl << endl;
//	//数据预处理
//	initProblem();
//	cout << "--------------------数据预处理 当前属性的取值:----------------------------------" << endl;
//	get_dataset();
//
//
//	//构建有向无环图+表项
//	cout << "---------------------构建贝叶斯网络建立表项-------------------------------------" << endl;
//	
//	construct_BayesianNW();
//
//
//	//训练(精确推理:枚举推理)
//	cout << "-----------------------------训练相关条件概率表-------------------------------------" << endl;
//	//(对条件概率表+边缘分布表进行计数)
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	cout << "训练集大小:\t" << trainingsetsize << endl;
//	
//	//训练概率
//	trainBN();
//
//	
//}
//
//
//
///*******************************************************RRtest ST***************************************************************************************/
////证据变量结构体
//struct Evi {
//	int E;
//	string e;
//	Evi() {}
//	Evi(int _E, string _e)
//	{
//		E = _E;
//		e = _e;
//	}
//};
//
//
////获取第一个样本
//vector<string> get_randomsample(vector<Evi> evidence)
//{
//	vector<string> temp;
//	for (vector<vector<string>>::iterator it = trainingset.begin(); it != trainingset.end(); it++)
//	{
//		vector<Evi>::iterator secondit;
//		for (secondit = evidence.begin(); secondit != evidence.end(); secondit++)
//		{
//			if ((*it)[secondit->E] != secondit->e)
//			{
//				break;
//			}
//		}
//		if (secondit == evidence.end())
//		{
//			temp = (*it);
//			(*it) = trainingset[0];
//			trainingset[0] = temp;
//
//			break;
//		}
//		/*
//		if ((*it)[E] == e)
//		{
//			temp = (*it);
//			(*it) = trainingset[0];
//			trainingset[0] = temp;
//
//			break;
//		}
//		*/
//	}
//	return trainingset[0];
//}
//
//
////获取抽样的变量
//vector<int> get_feature(vector<Evi> evidence)
//{
//	vector<int> feature;
//
//	for (int i = 1; i <= 13; i++)
//	{
//		vector<Evi>::iterator it;
//		for (it = evidence.begin(); it != evidence.end(); it++)
//		{
//			if (i == it->E)
//				break;
//		}
//		if (it == evidence.end())
//		{
//			feature.push_back(i);
//		}
//	}
//	return feature;
//}
//
//
////用于轮盘赌
//struct CValue {
//	string value;
//	int boxsum;
//	CValue(){}
//	CValue(string _value,int _boxsum)
//	{
//		value = _value;
//		boxsum = _boxsum;
//	}
//};
//
//
//bool cmp(CValue a, CValue b)
//{
//	return a.boxsum < b.boxsum;
//}
//
//
////抽样函数
//void Sampling(int id, vector<string> &cur)
//{
//	cout << "**********************************" << endl;
//	vector<int> curcondition = get_condition_id(id);
//	vector<string> com;
//
//	for (vector<int>::iterator it = curcondition.begin(); it != curcondition.end(); it++)
//	{
//		com.push_back(cur[*it]);
//	}
//
//	//TODO：更改为轮盘赌
//	//查找：只能取一个值
//	string maxvalue = "";
//	int maxpro = -1;
//	/*
//	for (map<string, CPtableI>::iterator it = BN[id].CPtable[com].curCPtableI.begin(); it != BN[id].CPtable[com].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxpro = it->second.pro;
//			maxvalue = it->first;
//			
//		}
//	}
//	*/
//	
//
//
//	//构建轮盘赌
//	vector<CValue> box;
//	
//	int boxsum = 0;
//	for (map<string, CPtableI>::iterator it = BN[id].CPtable[com].curCPtableI.begin(); it != BN[id].CPtable[com].curCPtableI.end(); it++)
//	{
//		boxsum += it->second.cnt;
//		it->second.boxsum = boxsum;
//		box.push_back(CValue(it->first, boxsum));
//	}
//
//	sort(box.begin(), box.end(), cmp);
//
//	if (boxsum != 0)
//	{
//		int randomchose = rand() % boxsum + 1;
//		for (vector<CValue>::iterator it = box.begin(); it != box.end(); it++)
//		{
//			if (randomchose <= it->boxsum)
//			{
//				maxvalue = it->value;
//				break;
//			}
//		}
//		//赋值
//		cout << Name[id] << "更改的值" << maxvalue << endl;
//		cur[id] = maxvalue;
//	}
//	
//	
//}
//
//
////随机推理
//void RRtest()
//{
//	cout << "进行随机推理：" << endl;
//
//	int Q, E;
//	string q, e;
//	cout << "输入查询变量标号 查询变量取值：" << endl;
//	cin >> Q >> q;
//
//	cout << "输入证据变量标号 证据变量取值：" << endl;
//	vector<Evi> evidence;
//	while (cin >> E >> e)
//	{
//		evidence.push_back(Evi(E, e));
//	}
//	
//	//生成表项
//	unordered_map<string,int> valuecount;
//	for (set<string>::iterator it = av[Q].begin(); it != av[Q].end(); it++)
//	{
//		valuecount[*it] = 0;
//	}
//
//	
//	int mq = 0;
//
//	vector<int> feature = get_feature(evidence);
//
//	vector<string> head = get_randomsample(evidence);
//	
//	for (unordered_map<string, int>::iterator it = valuecount.begin(); it != valuecount.end(); it++)
//	{
//		if (head[Q] == it->first)
//		{
//			it->second++;
//			break;
//		}
//		
//	}
//
//	if (head[Q] == q)
//	{
//		mq++;
//	}
//
//	for (int i = 1; i < trainingset.size(); i++)
//	{
//		cout << endl << "第" << i + 1 << "个样例---------------------------------" << endl;
//		vector<string> cur = head;
//		for (vector<int>::iterator it = feature.begin(); it != feature.end(); it++)
//		{
//			Sampling(*it, cur);
//		}
//
//		//测试输出
//		cout << Name[Q] << ": " << q << "==" << cur[Q] << endl;
//
//		if (cur[Q] == q)
//		{
//			mq++;
//			cout << "mq更新";
//		}
//
//		for (unordered_map<string, int>::iterator it = valuecount.begin(); it != valuecount.end(); it++)
//		{
//			if (cur[Q] == it->first)
//			{
//				it->second++;
//				break;
//			}
//
//		}
//
//		head = cur;
//		cout << endl;
//	}
//
//
//
//	//最后输出
//	double pro = (double)mq / (double)trainingsetsize;
//	cout << "///////////////////////////////////////////////////" << endl;
//	cout << "推断结果：" << endl;
//	cout << "P(" << Name[Q] << "=" << q << "|"; 
//	for (vector<Evi>::iterator secondit = evidence.begin(); secondit != evidence.end(); secondit++)
//	{
//		cout << Name[secondit->E] << "=" << secondit->e << " ";
//	}
//	cout << ")=" << pro << endl;
//	
//	
//	cout << "表输出：" << endl;
//	int outsum = 0;
//	for (unordered_map<string, int>::iterator it = valuecount.begin(); it != valuecount.end(); it++)
//	{
//		cout << it->second << "\t";
//		//outsum += it->second;
//		pro = (double)it->second / (double)trainingsetsize;
//		cout << "P(" << Name[Q] << "=" << it->first << "|";
//		for (vector<Evi>::iterator secondit = evidence.begin(); secondit != evidence.end(); secondit++)
//		{
//			cout << Name[secondit->E] << "=" << secondit->e << " ";
//		}
//		cout<<")=" << pro << endl;
//
//	}
//	cout << "SUM：" << outsum << endl;
//}
///*******************************************************RRtest ED***************************************************************************************/
//int main()
//{
//	
//	srand(time(NULL));//随机种子
//	BN_CP_construct();
//	RRtest();
//	
//	return 0;
//}
//
