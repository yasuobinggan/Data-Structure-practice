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
//vector<sample> trainingset;//训练集
//int trainingsetsize;
//map< int, set<string> > av;//属性取值
//
//						   /*条件概率表定义 ST*/
//						   //二级表项
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
//				//条件概率表
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
//						   //贝叶斯网络中最多可能的属性个数
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
////利用数据集获取数据的特性(数据预处理)
//void get_dataset()
//{
//
//	ifstream fin;
//	fin.open("d:\\datasetG\\dataset.txt", ios::in);
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
//			cout << "当前id：" << it->first;// << "当前属性: " << BN[it->first].name;
//			cout << "当前大小：" << it->second.size() << endl;
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
////获得当棋属性+条件属性编号
//vector<int> get_condition_id(int id)
//{
//	vector<int> condition;
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
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
//		cout << "条件概率表表项生成:";
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
//	Node WB1(1, "1stWB");
//	Node WB2(2, "2ndWB");
//	Node PosB1(3, "1stPosB");
//	Node PosB2(4, "2ndPosB");
//	Node TWB(5, "TWB");
//	Node WM1(6, "1stWM");
//	Node WM2(7, "2ndWM");
//	Node TWM(8, "TWM");
//	Node WS1(9, "1stWS");
//	Node WS2(10, "2ndWS");
//	Node PosS1(11, "1stPosS");
//	Node PosS2(12, "2ndPosS");
//	Node TWS(13, "TWS");
//
//	//建立结点间关系
//	/*
//	MWST关系：
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
//	*/
//
//	WB1.child.push_back(TWB); TWB.parent.push_back(WB1);
//	WB2.child.push_back(TWB); TWB.parent.push_back(WB2);
//	PosB1.child.push_back(TWB); TWB.parent.push_back(PosB1);
//	PosB2.child.push_back(TWB); TWB.parent.push_back(PosB2);
//
//	WB1.child.push_back(WM1); WM1.parent.push_back(WB1);
//	WB2.child.push_back(WM2); WM2.parent.push_back(WB2);
//	TWB.child.push_back(TWM); TWM.parent.push_back(TWB);
//	WM1.child.push_back(TWM); TWM.parent.push_back(WM1);
//	WM2.child.push_back(TWM); TWM.parent.push_back(WM2);
//
//
//	//TWM.child.push_back(TWS); TWS.parent.push_back(TWM);
//	WM1.child.push_back(WS1); WS1.parent.push_back(WM1);
//	WM2.child.push_back(WS2); WS2.parent.push_back(WM2);
//	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
//	WS2.child.push_back(TWS); TWS.parent.push_back(WS2);
//	PosS1.child.push_back(TWS); TWS.parent.push_back(PosS1);
//	PosS2.child.push_back(TWS); TWS.parent.push_back(PosS2);
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
//		cout << "id: " << id << "属性名称: " << BN[id].name << endl;
//		if (id == 5 || id == 8 || id == 13)
//		{
//			construct_CPtable(id);
//		}
//		//建立MD:循环遍历目标属性取值
//		for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//		{
//			BN[id].MD[*it] = CPtableI(0, 0);
//		}
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
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		//cout << invec[it->id] << " ";
//		com.push_back(invec[it->id]);
//	}
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
//				//边缘分布表计数
//				BN[id].MD[invec[id]].cnt++;
//
//				//条件概率表计数
//				if (BN[id].parent.size() != 0)
//				{
//					if (id == 5 || id == 8 || id == 13)
//					{
//						count_CPtable(id, invec);
//					}
//
//
//				}
//
//			}
//			//读入训练集
//			sample s = sample(invec[0], invec[1], invec[2], invec[3], invec[4], invec[5], invec[6], invec[7], invec[8], invec[9], invec[10], invec[11], invec[12], invec[13], invec[14]);
//			trainingset.push_back(s);
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
//void train_CPtable_MD(int id)
//{
//	//边缘分布概率
//	for (map<string, CPtableI>::iterator it = BN[id].MD.begin(); it != BN[id].MD.end(); it++)
//	{
//		it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
//		//cout << " " << id << " " << it->second.pro<<endl;
//	}
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
//					//cout << secondit->second.cnt << "\t" << it->second.sumcnt << endl;
//					secondit->second.pro = (double)secondit->second.cnt / (double)it->second.sumcnt;
//					//cout << "cur: " << secondit->second.pro << endl;
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
//		cout << "计算概率\t" << id << endl;
//		train_CPtable_MD(id);
//		cout << "***************************************" << endl;
//	}
//}
///**************************************************train_CPtable ED*************************************************************************************/
//
//
//
///**************************************************test(推断) ST****************************************************************************************/
//vector<string> testsample(vector<string> invec)
//{
//	vector<string> hypo;//假设
//
//						//匹配词汇大类
//						//记录
//	vector<string> comTWB;
//
//	for (vector<Node>::iterator it = BN[5].parent.begin(); it != BN[5].parent.end(); it++)
//	{
//		comTWB.push_back(invec[it->id]);
//	}
//	//匹配
//	string maxvalue;
//	double maxpro = -1.0;
//
//	for (map<string, CPtableI>::iterator it = BN[5].CPtable[comTWB].curCPtableI.begin(); it != BN[5].CPtable[comTWB].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxvalue = it->first;
//			maxpro = it->second.pro;
//		}
//	}
//
//	hypo.push_back(maxvalue);
//
//	//匹配词汇中类
//	//记录
//	vector<string> comTWM;
//
//	for (vector<Node>::iterator it = BN[8].parent.begin(); it != BN[8].parent.end(); it++)
//	{
//		comTWM.push_back(invec[it->id]);
//	}
//
//	//匹配
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (map<string, CPtableI>::iterator it = BN[8].CPtable[comTWM].curCPtableI.begin(); it != BN[8].CPtable[comTWM].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxvalue = it->first;
//			maxpro = it->second.pro;
//		}
//	}
//
//	hypo.push_back(maxvalue);
//
//	//匹配词汇小类
//	//记录
//	vector<string> comTWS;
//
//	for (vector<Node>::iterator it = BN[13].parent.begin(); it != BN[13].parent.end(); it++)
//	{
//		comTWS.push_back(invec[it->id]);
//	}
//
//	//匹配
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (map<string, CPtableI>::iterator it = BN[13].CPtable[comTWS].curCPtableI.begin(); it != BN[13].CPtable[comTWS].curCPtableI.end(); it++)
//	{
//		if (it->second.pro > maxpro)
//		{
//			maxvalue = it->first;
//			maxpro = it->second.pro;
//		}
//	}
//
//	hypo.push_back(maxvalue);
//
//	return hypo;
//}
//
//
//void test()
//{
//
//	//查询目标结点的条件概率表
//	ifstream fin;
//	fin.open("d:\\dataset\\testdataset.txt", ios::in);
//
//
//
//	if (fin)//读取到数据集
//	{
//		int testsize = 0;//训练集大小
//
//		string line;//定义读取一行文本的变量
//		vector<string> invec;//获取切割后的字符串序列
//
//							 //记录准确率
//		int sumcount = 0;
//
//		double expection = 0;
//
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
//				invec.push_back(in);
//				i = j + 1;
//			}
//
//			//推断+推断结果
//			vector<string> hypo = testsample(invec);
//
//
//			//词汇大类
//			cout << "词汇大类标准取值: " << invec[5] << " ";
//			cout << "推断词汇大类取值" << hypo[0] << "\t|\t";
//
//
//			//词汇中类
//			cout << "词汇中类标准取值: " << invec[8] << " ";
//			cout << "推断词汇中类取值" << hypo[1] << "\t|\t";
//
//			//词汇小类
//			cout << "词汇小类标准取值: " << invec[13] << " ";
//			cout << "推断词汇小类取值" << hypo[2] << endl;
//
//
//
//			//计算期望
//			double curexpection = 0;
//			if (invec[5] == hypo[0])
//			{
//				curexpection += 1;
//			}
//			if (invec[8] == hypo[1])
//			{
//				curexpection += 1;
//			}
//			if (invec[13] == hypo[2])
//			{
//				curexpection += 1;
//			}
//
//			curexpection /= 3;
//			expection += curexpection;
//
//
//			//匹配计数
//			if (invec[5] == hypo[0] && invec[8] == hypo[1] && invec[13] == hypo[2])
//			{
//				sumcount++;
//			}
//
//
//			++testsize;
//		}
//
//		//输出模型的准确率,期望
//		cout << endl << "********************************************************************" << endl;
//		cout << "当前模型的完全准确率: " << (double)sumcount / (double)testsize << endl;
//		cout << "当前模型的期望: " << ((double)1 / (double)testsize) * expection << endl;
//
//		fin.close();
//
//	}
//	else
//		cout << "dataset doesn't exist!" << endl;
//}
///**************************************************test(推断) ED****************************************************************************************/
//
//
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
////双音节词问题总函数
//void BN_CP_construct()
//{
//	cout << "*************************精确推理:枚举推理**************************************" << endl << endl;
//	//数据预处理
//	cout << "--------------------数据预处理 当前属性的取值:----------------------------------" << endl;
//	get_dataset();
//
//
//	//构建有向无环图+表项
//	cout << "---------------------构建贝叶斯网络建立表项-------------------------------------" << endl;
//	tar.push_back(5); tar.push_back(8); tar.push_back(13);
//	construct_BayesianNW();
//
//
//	//训练(精确推理:枚举推理)
//	cout << "-----------------------------训练条件概率表-------------------------------------" << endl;
//	//(对条件概率表+边缘分布表进行计数)
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	cout << "训练集大小:\t" << trainingsetsize << endl;
//	//训练概率
//	trainBN();
//
//	//推断
//	cout << "-----------------------------测试集推断-----------------------------------------" << endl;
//	clock_t start = clock();
//	test();
//	clock_t end = clock();
//
//	cout << "Running Time：" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
//}
//
//
///**************************************************变量消元 ST****************************************************************************************/
////函数结构体
//struct Function {
//
//	unordered_set<int> label;//函数参数的标号
//
//
//	bool flag;//true为概率函数
//	int head;//记录概率函数的目标
//	map<vector<string>, double> value;//非概率函数
//
//	Function() {}
//	Function(bool _flag, int _head)
//	{
//		flag = _flag;
//		head = _head;
//	}
//
//};
//
//vector<Function> Fset;//函数集合
//
//
//					  //初始化函数集合
//void initFset()
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		//设为概率函数
//		Function curF(true, id);
//		cout << "HEAD: " << id;
//		curF.label.insert(id);
//
//		for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//		{
//			cout << "\t" << it->id;
//			curF.label.insert(it->id);
//		}
//		cout << endl;
//	}
//}
//
//
//vector<int> get_order(int st, int E, int Q)
//{
//	//d数组的含义为相邻结点的编号数量
//	fill(d, d + maxn, 0);
//	stack<int> s;
//	vector<int> order;
//
//	d[st] = 1;
//
//	for (int id = 1; id <= 13; id++)
//	{
//		int MAX = 0;
//		int maxi;
//
//		for (int u = 1; u <= 13; u++)
//		{
//			if (d[u] > MAX && visited[u] == false)
//			{
//				MAX = d[u];
//				maxi = u;
//			}
//		}
//
//
//		//cout<<"cur："<<maxi<<"\t当前相邻个数："<<d[maxi]<<endl;
//		if (maxi != E && maxi != Q)
//		{
//			s.push(maxi);
//		}
//		visited[maxi] = true;
//
//
//		//cout<<"更新"<<endl;
//		for (int v = 1; v <= 13; v++)
//		{
//			if (visited[v] == false && G[maxi][v] == 1)
//			{
//				//cout<<v<<"\t";
//				d[v]++;
//			}
//		}
//		cout << endl;
//	}
//
//	//栈弹出
//	while (!s.empty())
//	{
//		cout << s.top() << " ";
//		order.push_back(s.top());
//		s.pop();
//	}
//
//
//	return order;
//}
//
////Fset为函数集合
//void Elim(int Z)
//{
//	vector<Function> proFset;
//	vector<Function> curFset;
//
//	for (vector<Function>::iterator it = Fset.begin(); it != Fset.end(); it++)
//	{
//		if (it->label.find(Z) != it->label.end())
//		{
//			proFset.push_back(*it);
//		}
//		else
//		{
//			curFset.push_back(*it);
//		}
//	}
//	//由proFset生成 一个 函数
//
//
//	Fset = curFset;
//}
//
//
//void VE(int E, string e, int Q, vector<int> order)
//{
//	while (!order.empty())
//	{
//		int Z = order.front();
//		vector<int>::iterator it = order.begin();
//		order.erase(it);
//
//		Elim(Z);
//	}
//	//TODO
//	//输出
//
//}
//
//
//void PRtest()
//{
//	memset(G, 0, sizeof(G));
//	memset(visited, false, sizeof(visited));
//
//	//将结点关系补入无向图
//	G[1][5] = 1; G[5][1] = 1;
//	G[2][5] = 1; G[5][2] = 1;
//	G[3][5] = 1; G[5][3] = 1;
//	G[4][5] = 1; G[5][4] = 1;
//
//	G[1][6] = 1; G[6][1] = 1;
//	G[2][7] = 1; G[7][2] = 1;
//	G[5][8] = 1; G[8][5] = 1;
//	G[6][8] = 1; G[8][6] = 1;
//	G[7][8] = 1; G[8][7] = 1;
//
//	G[6][9] = 1; G[9][6] = 1;
//	G[7][10] = 1; G[10][7] = 1;
//	G[9][13] = 1; G[13][9] = 1;
//	G[10][13] = 1; G[13][10] = 1;
//	G[11][13] = 1; G[13][11] = 1;
//	G[12][13] = 1; G[13][12] = 1;
//
//	int E; string e;
//	int Q;
//
//	cout << "输入证据变量的编号和取值（参考数据预处理内容）：" << endl;
//	cin >> E >> e;
//	cout << "输入查询变量的编号：" << endl;
//	cin >> Q;
//
//	//初始化函数
//	initFset();
//	//初始化消元顺序
//	int st;
//	while (true)
//	{
//		st = rand() % 13 + 1;
//		if (st != E || st != Q)
//			break;
//	}
//	vector<int> order = get_order(st, E, Q);
//	//变量消元
//	VE(E, e, Q, order);
//
//}
///**************************************************变量消元 ED****************************************************************************************/
//
//
//
//int main()
//{
//
//	srand(time(NULL));//随机种子
//	BN_CP_construct();
//	//PRtest();
//
//	return 0;
//}
//
