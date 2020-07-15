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
//#include<iostream>
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
//using namespace std;
//
///*******************************************数据结构 ST*************************************************************************************************/
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
//		s_1stWB = a;
//		s_2ndWB = b;
//		s_1stPosB = c;
//		s_2ndPosB = d;
//		s_TWB = e;
//		s_1stWM = f;
//		s_2ndWM = g;
//		s_TWM = h;
//		s_1stWS = i;
//		s_2ndWS = j;
//		s_1stPosS = k;
//		s_2ndPosS = l;
//		s_TWS = m;
//		mode = n;
//	}
//};
//
//vector<sample> trainingset;//训练集
//int trainingsetsize;
//map<int, set<string>> av;//属性取值
//
///*条件概率表定义 ST*/
////通用表项
//struct CPtableI
//{
//	int count;
//	double pro;
//	CPtableI() {}
//	CPtableI(int _count)
//	{
//		count = _count;
//	}
//	CPtableI(int _count, double _pro)
//	{
//		count = _count;
//		pro = _pro;
//	}
//};
///*条件概率表定义 ED*/
////条件概率树的一个结点
//struct Treenode {
//	string name;//结点名称（属性名称）
//	double id;//结点标号（属性标号）
//
//	bool flag;//标记是否为叶节点（叶节点为路径上的目标结点）;判断是不是概率结点
//	int value;//上一层分支的取值
//
//	double conpro;//概率结点存储条件概率的容器
//	int pro;//概率结点存储最终概率的容器
//
//	vector<int> path;//节点存储的路径上的结点属性的取值
//	vector<Treenode> child;//孩子结点
//};
//
////建立贝叶斯网络结点:一个结点一个条件概率树(表)
//struct Node {
//	int id;//属性标号
//	string name;//属性名
//
//	//条件概率表
//	map<vector<string>, CPtableI> CPtable;
//	//map<CPtableH, map<vector<string>, CPtableI>> CPtable;
//	//map<CPtableH, unordered_map<string, CPtableI>> CPtable;
//
//	//条件概率树
//	Treenode CPtree;
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
///*******************************************数据结构 ED*************************************************************************************************/
//
//
//
///********************************************数据预处理 ST*************************************************************************************************/
////利用数据集获取数据的特性(数据预处理)
//void get_dataset()
//{
//
//	ifstream fin;
//	fin.open("d:\\dataset.txt", ios::in);
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
//		for (map<int, set<string>>::iterator it = av.begin(); it != av.end(); it++)
//		{
//			cout << "当前id：" << it->first;// << "当前属性: " << BN[it->first].name;
//			cout << "当前大小："<<it->second.size() << endl;
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
///********************************************数据预处理 ED*************************************************************************************************/
//
//
//
///********************************construct_BN  ST*******************************************************************************************************/
///*
////条件概率表的第一级表头
//struct CPtableH {
//	string tarval;//目标取值
//	int tarcount;//目标边缘计数
//	double tarpro;//目标边缘概率
//	CPtableH(){}
//	CPtableH(string _tarval, int _tarcount,double _tarpro)
//	{
//		tarval = _tarval;
//		tarcount = _tarcount;
//		tarpro = _tarpro;
//	}
//	friend bool operator <(CPtableH a, CPtableH b)
//	{
//		return a.tarval < b.tarval;
//	}
//};
////条件概率表第二级表头
////条件概率表第二级表项
//struct CPtableI
//{
//	int concount;//条件计数
//	double conpro;//条件概率
//	CPtableI(){}
//	CPtableI(int _concount, double _conpro)
//	{
//		concount = _concount;
//		conpro = _conpro;
//	}
//};
//*/
//
///*
////获得当棋属性的条件属性编号
//vector<int> get_condition_id(int id)
//{
//vector<int> condition;
//for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//{
//condition.push_back(it->id);
//}
//return condition;
//}
//
////dfs函数生成二级表项(bfs生成二级表项)
//void build_CPtableI(vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &secondCPtable)
//{
//if (index == condition.size())
//{
//secondCPtable[curcon] = CPtableI(0, 0);
//return;
//}
//
////cout << condition[index] << endl;
//
//for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//{
//curcon.push_back(*it);
//build_CPtableI(condition, index + 1, curcon, secondCPtable);
//curcon.pop_back();
//}
//}
//
////总构建函数
//void construct_CPtable(int id)
//{
//vector<int> condition = get_condition_id(id);
//
////二级表项为空
//if (condition.size() == 0)
//{
//map<vector<string>, CPtableI> secondCPtable;//二级表项
////循环遍历目标属性取值
//for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//{
//BN[id].CPtable[CPtableH(*it, 0, 0)] = secondCPtable;//二级表项
//}
//}
////二级表项不为空
//else
//{
////建立二级表项
//int index = 0;//下标控制访问
//vector<string> curcon;//当前路径上的条件取值
//map<vector<string>, CPtableI> secondCPtable;//二级表项
//curcon.clear(); secondCPtable.clear();
////递归函数
//build_CPtableI(condition, index, curcon, secondCPtable);
//
////循环遍历目标属性取值
//for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//{
//BN[id].CPtable[CPtableH(*it, 0, 0)] = secondCPtable;//二级表项
//}
//}
//
//}
//*/
//
///*****************construct_CPtable ST*********************/
////获得当棋属性+条件属性编号
//vector<int> get_condition_id(int id)
//{
//	vector<int> condition;
//	condition.push_back(id);
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//	return condition;
//}
//
////dfs函数生成条件概率表表项
///*
//void build_CPtableH(vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &curCPtable)
//{
//	if (index == condition.size())
//	{
//		curCPtable[curcon] = CPtableI(0, 0);
//
//		//输出测试
//		for (vector<string>::iterator itstring = curcon.begin(); itstring != curcon.end(); itstring++)
//		{
//			cout << *itstring << "\t";
//		}
//		cout << endl;
//
//
//		return;
//	}
//
//	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//	{
//		curcon.push_back(*it);
//		build_CPtableH(condition, index + 1, curcon, curCPtable);
//		curcon.pop_back();
//	}
//}
//*/
//
////bfs生成条件概率表表项
//void build_CPtableH(vector<int> condition, int index, vector<string> rootcon, map<vector<string>, CPtableI> &curCPtable)
//{
//	queue<vector<string>> q;
//	for (set<string>::iterator it = av[condition[index]].begin(); it != av[condition[index]].end(); it++)
//	{
//		rootcon.push_back(*it);
//		q.push(rootcon);
//		rootcon.pop_back();
//	}
//	while (!q.empty())
//	{
//		vector<string> curcon = q.front();
//		q.pop();
//		if (curcon.size() != condition.size())
//		{
//			for (set<string>::iterator it = av[condition[curcon.size()]].begin(); it != av[condition[curcon.size()]].end(); it++)
//			{
//				curcon.push_back(*it);
//				q.push(curcon);
//				curcon.pop_back();
//			}
//		}
//
//		else
//		{
//			curCPtable[curcon] = CPtableI(0);
//			//输出测试
//			/*
//			for (vector<string>::iterator it = curcon.begin(); it != curcon.end(); it++)
//			{
//				cout << *it << "\t";
//			}
//			cout << endl;
//			*/
//		}
//
//	}
//}
//
////总构建函数
//void construct_CPtable(int id)
//{
//	vector<int> condition = get_condition_id(id);
//
//	//建立MD:循环遍历目标属性取值
//	for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
//	{
//		BN[id].MD[*it] = CPtableI(0, 0);
//	}
//
//	//建立CPtable:
//	//条件为空
//	if (condition.size() == 1)
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
//		//dfs建表
//		//build_CPtableH(condition, index, curcon, BN[id].CPtable);
//
//		//bfs建表
//		build_CPtableH(condition, index, curcon, BN[id].CPtable);
//
//		cout << " \t条件概率表大小: " << BN[id].CPtable.size() << endl;
//
//	}
//
//}
///*****************construct_CPtable ED*********************/
//
///*****************construct_CPtree ST**********************/
///*
//vector<int> get_condition(int id)
//{
//	vector<int> condition;
//	for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//	{
//		condition.push_back(it->id);
//	}
//	return condition;
//}
//*/
///*****************construct_Cptree ED**********************/
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
//	WM1.child.push_back(WS1); WS1.parent.push_back(WM1);
//	WM2.child.push_back(WS2); WS2.parent.push_back(WM2);
//	WS1.child.push_back(TWS); TWS.parent.push_back(WS1);
//	WS2.child.push_back(TWS); TWS.parent.push_back(WS2);
//	PosS1.child.push_back(TWS); TWS.parent.push_back(PosS1);
//	PosS2.child.push_back(TWS); TWS.parent.push_back(PosS2);
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
//		construct_CPtable(id);
//		/*
//		if (BN[id].CPtable.size() != 0)
//		{
//
//		cout << "id: " << id << "属性名称: " << BN[id].name << endl;
//		for (map<vector<string>, CPtableI>::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//		vector<string> curstring = it->first;
//		for (vector<string>::iterator itstring = curstring.begin(); itstring != curstring.end(); itstring++)
//		{
//		cout << *itstring << "\t";
//		}
//		cout << endl;
//		}
//		}
//		*/
//	}
//	//方法二: 每个结点的条件概率树,边缘分布表(只开空间不输入数据)
//	/*
//	for (int id = 1; id <= 13; id++)
//	{
//
//	}
//	*/
//
//}
///*****************************construct_BN ED***********************************************************************************************************/
//
//
//
///********************************get_Trainingset  ST****************************************************************************************************/
////计数函数
//void count_CPtable_MD(int id, vector<string> invec)
//{
//	//边缘分布表
//	BN[id].MD[invec[id]].count++;
//
//	//从样例中提取->条件概率表
//	cout <<BN[id].name<< " 从样例中提取的取值: " << endl;
//	if (BN[id].parent.size() != 0)
//	{
//		vector<string> com;
//		cout << invec[id] << "\t";
//		com.push_back(invec[id]);
//		for (vector<Node>::iterator it = BN[id].parent.begin(); it != BN[id].parent.end(); it++)
//		{
//			cout << invec[it->id] << "\t";
//			com.push_back(invec[it->id]);
//		}
//		cout <<"数量: "<< BN[id].CPtable.count(com) ;
//
//		BN[id].CPtable[com].count++;
//
//		cout <<"\t" << BN[id].CPtable[com].count;
//
//		cout << endl;
//
//	}
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
//	fin.open("d:\\trainingdataset.txt", ios::in);
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
//			//获取每个属性结点的取值
//			for (int i = 1; i <= 14; i++)
//			{
//				if (invec[i].size() <= 2)
//					av[i].insert(invec[i]);
//			}
//
//			//进行数据计数
//			for (int id = 1; id <= 13; id++)
//			{
//				cout << "********************************************" << endl;
//				count_CPtable_MD(id, invec);
//				cout << "********************************************" << endl;
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
//		it->second.pro = (double)it->second.count / (double)trainingsetsize;
//		//cout << " " << id << " " << it->second.pro<<endl;
//	}
//	if (BN[id].parent.size() != 0)
//	{
//		//条件概率分布
//		for (map<vector<string>, CPtableI>::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//			it->second.pro = (double)it->second.count / (double)trainingsetsize;
//			if (it->second.count != 0)
//			{
//
//				//double a = it->second.count;
//				//double b = trainingsetsize;
//				//cout << a / b;
//
//				//cout<<it->second.count<<" "<<trainingsetsize<<" "<<it->second.pro<<endl;
//
//			}
//
//		}
//	}
//
//
//}
//
////总训练函数
//void trainBN()
//{
//	for (int id = 1; id <= 13; id++)
//	{
//		train_CPtable_MD(id);
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
//	//匹配词汇大类
//	//记录
//	vector<vector<string>> comTWB;
//
//	for (set<string>::iterator it = av[5].begin(); it != av[5].end(); it++)
//	{
//		vector<string> curcomTWB;
//
//		curcomTWB.push_back(*it);
//		for (vector<Node>::iterator secondit = BN[5].parent.begin(); secondit != BN[5].parent.end(); secondit++)
//		{
//			curcomTWB.push_back(invec[secondit->id]);
//		}
//		comTWB.push_back(curcomTWB);
//	}
//	//匹配
//	string maxvalue;
//	double maxpro = -1.0;
//
//	for (vector<vector<string>>::iterator it = comTWB.begin(); it != comTWB.end(); it++)
//	{
//		if (BN[5].CPtable[*it].pro > maxpro)
//		{
//			maxvalue = (*it)[0];
//			maxpro = BN[5].CPtable[*it].pro;
//		}
//	}
//	hypo.push_back(maxvalue);
//
//
//
//	//匹配词汇中类
//	//记录
//	vector<vector<string>> comTWM;
//
//	for (set<string>::iterator it = av[8].begin(); it != av[8].end(); it++)
//	{
//		vector<string> curcomTWM;
//
//		curcomTWM.push_back(*it);
//		for (vector<Node>::iterator secondit = BN[8].parent.begin(); secondit != BN[8].parent.end(); secondit++)
//		{
//			curcomTWM.push_back(invec[secondit->id]);
//		}
//		comTWM.push_back(curcomTWM);
//	}
//	//匹配
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (vector<vector<string>>::iterator it = comTWM.begin(); it != comTWM.end(); it++)
//	{
//		if (BN[8].CPtable[*it].pro > maxpro)
//		{
//			maxvalue = (*it)[0];
//			maxpro = BN[8].CPtable[*it].pro;
//		}
//	}
//	hypo.push_back(maxvalue);
//
//
//	//匹配词汇小类
//	//记录
//	vector<vector<string>> comTWS;
//
//	for (set<string>::iterator it = av[13].begin(); it != av[13].end(); it++)
//	{
//		vector<string> curcomTWS;
//
//		curcomTWS.push_back(*it);
//		for (vector<Node>::iterator secondit = BN[13].parent.begin(); secondit != BN[13].parent.end(); secondit++)
//		{
//			curcomTWS.push_back(invec[secondit->id]);
//		}
//		comTWS.push_back(curcomTWS);
//	}
//	//匹配
//	maxvalue = "";
//	maxpro = -1.0;
//
//	for (vector<vector<string>>::iterator it = comTWS.begin(); it != comTWS.end(); it++)
//	{
//		if (BN[13].CPtable[*it].pro > maxpro)
//		{
//			maxvalue = (*it)[0];
//			maxpro = BN[13].CPtable[*it].pro;
//		}
//	}
//	hypo.push_back(maxvalue);
//
//	return hypo;
//}
//
//void test()
//{
//	cout << "--------------------------测试集推断----------------------------------" << endl;
//
//	//查询目标结点的条件概率表
//	ifstream fin;
//	fin.open("d:\\testdataset.txt", ios::in);
//
//	//记录准确率
//	int count = 0;
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
//			//推断+推断结果
//			vector<string> hypo=testsample(invec);
//
//
//			//词汇大类
//			cout << "词汇大类标准取值: " << invec[5] << " ";
//			cout << "推断词汇大类取值" << hypo[0] << "\t|\t";
//
//
//			//词汇中类
//			cout << "词汇中类标准取值: " << invec[8] << " ";
//			cout << "推断词汇中类取值" << hypo[1]<<"\t|\t";
//
//			//词汇小类
//			cout << "词汇小类标准取值: " << invec[13] << " ";
//			cout << "推断词汇小类取值" << hypo[2]<<endl;
//
//			if (invec[5] == hypo[0] && invec[8] == hypo[1] && invec[13] == hypo[2])
//			{
//				count++;
//			}
//
//
//		}
//
//		cout << endl << "********************************************************************" << endl;
//		cout << "当前模型的准确率: " << (double)count / (double)trainingsetsize << endl;
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
//
///*****************************testout 条件概率树 测试输出ST*********************************************************************************************/
///*
////输出每给属性结点的条件概率表项
//void travelCPtable(int id)
//{
//
//	//二级表项为空
//	if ( BN[id].parent.size() == 0 )
//		return;
//
//	map<CPtableH, map<vector<string>, CPtableI>>::iterator it = BN[id].CPtable.begin();
//	map<vector<string>, CPtableI> secondmap = it->second;
//
//	for (map<vector<string>, CPtableI>::iterator secondit = secondmap.begin(); secondit != secondmap.end(); secondit++)
//	{
//		for (int i = 0; i < secondit->first.size(); i++)
//		{
//			cout << secondit->first[i] << "\t";
//		}
//		cout << endl;
//	}
//
//	//map<vector<string>,CPtableI>::iterator secondit = it->second;
//}
//void testout()
//{
//	cout << "测试输出!" << endl;
//
//	for (vector<Node>::iterator it = BN.begin(); it != BN.end(); it++)
//	{
//		if (it->id != 0)
//		{
//			cout << "当前id: " << it->id << "当前属性: " << it->name<<endl;
//			cout << "输出第二级表项" << endl;
//			travelCPtable(it->id);
//			cout << "*********************************" << endl;
//		}
//
//	}
//}
//*/
///******************************testout 条件概率树 测试输出ED********************************************************************************************/
//
//
//
//int main()
//{
//	//数据预处理
//	cout << "数据预处理 当前属性的取值:" << endl;
//	get_dataset();
//	//构建有向无环图+表项
//	cout << "--------------------------------------------------------------------------------" << endl;
//	construct_BayesianNW();
//
//	//testout();//测试条件概率树
//
//	//(对条件概率表+边缘分布表进行计数)
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	cout <<"训练集大小:\t" <<trainingsetsize << endl;
//	/*
//	cout <<"训练集大小："<<(int)trainingset.size()<<endl;
//	//测试输出训练集
//	int count = 0;
//	for (vector<sample>::iterator it = trainingset.begin(); it != trainingset.end(); it++)
//	{
//		cout << ++count;
//		cout << it->s_word << "\t" << it->s_1stWB << "\t" << it->s_2ndWB << "\t" << it->s_1stPosB << "\t" << it->s_2ndPosB << "\t" << it->s_TWB << "\t";
//		cout << it->s_1stWM << "\t" << it->s_2ndWM << "\t" << it->s_TWM << "\t";
//		cout << it->s_1stWS << "\t" << it->s_2ndWS << "\t" << it->s_1stPosS << "\t" << it->s_2ndPosS << "\t" << it->s_TWS << "\t";
//		cout << it->mode;
//		cout << endl;
//	}
//	*/
//
//	//训练概率
//	cout << "--------------------------------------------------------------------------------" << endl;
//	trainBN();
//	/*
//	for (int id = 1; id <= 13; id++)
//	{
//
//		cout <<endl<<BN[id].name<< " 边缘分布表概率" << endl;
//		for (map<string, CPtableI>::iterator it = BN[id].MD.begin(); it != BN[id].MD.end(); it++)
//		{
//
//			cout <<"当前取值: "<<it->first<<" count: "<<it->second.count<<" pro:"<< it->second.pro << endl;
//		}
//		cout << "********************************************" << endl;
//
//		cout << endl << "条件概率表" << endl;
//		for (map <vector<string>, CPtableI> ::iterator it = BN[id].CPtable.begin(); it != BN[id].CPtable.end(); it++)
//		{
//			cout << "cur: ";
//			vector<string> cursv = it->first;
//			for (vector<string>::iterator itstring = cursv.begin(); itstring != cursv.end(); itstring++)
//			{
//				cout << *itstring << " ";
//			}
//			cout<< " pro: " << it->second.pro << " ";
//			cout << endl;
//		}
//
//		cout << endl;
//
//	}
//	*/
//
//	//推断
//	test();
//
//	return 0;
//}
