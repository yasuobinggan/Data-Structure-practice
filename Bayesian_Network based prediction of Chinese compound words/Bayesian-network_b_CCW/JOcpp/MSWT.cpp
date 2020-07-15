///*
//	MSWT:	
//		最大权生成树
//		基于互信息(MI)
//		与基本的贝叶斯网络的联合概率分布的相对熵最小
//	思考:
//		生成的是一棵树
//*/
//
////#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//#include<algorithm>
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
////边结构体
//struct Edge {
//	int u;
//	int v;
//	double wei;
//	Edge(){}
//	Edge(int _u, int _v, double _wei)
//	{
//		u = _u;
//		v = _v;
//		wei = _wei;
//	}
//};
//
//bool cmp(Edge a, Edge b)
//{
//	return a.wei > b.wei;
//}
//
//
////向量表示图
//vector<Edge> GV;
////并查集
//int father[maxn];
////邻接矩阵存储贝叶斯网络(只存储关系)
//int G[maxn][maxn];
////标记数组
//bool visited[maxn];
////距离数组
//double d[maxn];
////权重矩阵(存储属性的互信息)
//double Weight[maxn][maxn];
//
////最大权生成树
//vector<Edge> MSWT;
//
////属性名称
//string Name[maxn];
//void initName()
//{
//	Name[0] = "temp";
//
//	Name[1] = "1stWB";Name[2] = "2ndWB";
//	Name[3] = "1stPosB";Name[4] = "2ndPosB";
//	Name[5] = "TWB";
//	
//	Name[6] = "1stWM";Name[7] = "2ndWM";
//	Name[8] = "TWM";
//
//	Name[9] = "1stWS";Name[10] = "2ndWS";
//	Name[11] = "1stPosS";Name[12] = "2ndPosS";
//	Name[13] = "TWS";
//}
//
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
//vector<sample> trainingset;
//int trainingsetsize;
//
////属性取值
//map<int, set<string>> r;
//
//struct MTI {
//	int cnt;
//	double pro;
//	MTI() {}
//	MTI(int _cnt, double _pro)
//	{
//		cnt = _cnt;
//		pro = _pro;
//	}
//};
////边缘概率分布表
//map<string, MTI> MT[maxn];
//
//struct Pair {
//	int u;
//	int v;
//	Pair() {}
//	Pair(int _u, int _v)
//	{
//		u = _u;
//		v = _v;
//	}
//	friend bool operator<(Pair a, Pair b)
//	{
//		if (a.u != b.u)
//			return a.u < b.u;
//		else
//			return a.v < b.v;
//	}
//};
//struct JPI {
//	int cnt;
//	double pro;
//	JPI() {}
//	JPI(int _cnt, double _pro)
//	{
//		cnt = _cnt;
//		pro = _pro;
//	}
//};
////联合概率分布表
//map < Pair, map<vector<string>, JPI>> JPT;
//
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
//	fin.open("d:\\dataset\\trainingdataset.txt", ios::in);
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
//					r[i].insert(invec[i]);
//			}
//
//			
//		}
//
//		//测试输出
//		for (map<int, set<string>>::iterator it = r.begin(); it != r.end(); it++)
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
///********************************************建立表项 ST************************************************************************************************/
////构建二级表项(属性的取值组合)
////二层循环
//map<vector<string>,JPI> build_JPI(int u,int v)
//{
//	map<vector<string>, JPI> curJPI;
//
//	for (set<string>::iterator it = r[u].begin(); it != r[u].end(); it++)
//	{
//		vector<string> cur;
//		cur.clear();
//		cur.push_back(*it);
//		for (set<string>::iterator secondit = r[v].begin(); secondit != r[v].end(); secondit++)
//		{
//			cur.push_back(*secondit);
//			curJPI[cur] = JPI(0, 0);
//			cur.pop_back();
//		}
//	}
//	return curJPI;
//}
//void construct_MT_JPT()
//{
//	for (int u = 1; u <= 13; u++)
//	{
//		//建立MD:循环遍历目标属性取值
//		for (set<string>::iterator it = r[u].begin(); it != r[u].end(); it++)
//		{
//			MT[u][*it] = MTI(0, 0);
//		}
//		//建立联合概率表
//		for (int v = u + 1; v <= 13; v++)
//		{
//			//cout << "当前联合分布表项：" << u << " " << v << endl;
//			JPT[Pair(u, v)] = build_JPI(u, v);
//			
//			//cout << "***************************************" << endl;
//		}
//	}
//}
///********************************************建立表项 ED************************************************************************************************/
//
//
//
///********************************************读入训练集 ST**********************************************************************************************/
////利用数据集获取数据的特性(数据预处理)
//void get_trainingset()
//{
//	trainingset.clear();
//	//读训练集(先读.txt文件)
//	ifstream fin;
//	fin.open("d:\\dataset\\trainingdataset.txt", ios::in);
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
//			//进行数据计数
//			for (int id = 1; id <= 13; id++)
//			{
//				//边缘分布表计数
//				//cout << "当前更改结点: " << Name[id] << "\t当前取值:" << invec[id] << endl;
//				 ++MT[id][invec[id]].cnt;
//			
//			}
//			//联合概率表计数
//			for (int u = 1; u <= 13; u++)
//			{
//				vector<string> cur;
//				cur.clear();
//				cur.push_back(invec[u]);
//				for (int v = u + 1; v <= 13; v++)
//				{
//					cur.push_back(invec[v]);
//					/*
//					for (vector<string>::iterator it = cur.begin(); it != cur.end(); it++)
//					{
//						cout << *it << "\t";
//					}
//					cout << endl;
//					*/
//					cout <<"大标项数量："<< JPT.count(Pair(u, v)) << "\t";
//					cout << "小标项数量："<< JPT[Pair(u, v)].count(cur) << "\t";
//					cout <<"更改前："<< JPT[Pair(u, v)][cur].cnt << "\t";
//					
//					JPT[Pair(u, v)][cur].cnt++;
//					
//					cout <<"更改后：" << JPT[Pair(u, v)][cur].cnt << endl;
//					cur.pop_back();
//				}
//			}
//
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
///********************************************读入训练集 ED**********************************************************************************************/
//
//
//
///********************************************获取权重数组 ST********************************************************************************************/
////对所有表项计算概率
//void cal_pro()
//{
//	//边缘概率分布
//	for (int u = 1; u <= 13; u++)
//	{
//		
//		for (map<string, MTI>::iterator it = MT[u].begin(); it != MT[u].end(); it++)
//		{
//			it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
//
//		}
//		
//		//联合概率分布
//		//cout << "联合分布：" << endl;
//		for (int v = u + 1; v <= 13; v++)
//		{
//			for (map<vector<string>, JPI>::iterator it = JPT[Pair(u, v)].begin(); it != JPT[Pair(u, v)].end(); it++)
//			{
//				it->second.pro = (double)it->second.cnt / (double)trainingsetsize;
//			}
//		}
//		
//	}
//}
//
//
//
//double get_MI(int u, int v)
//{
//	double score = 0;
//	for (set<string>::iterator it = r[u].begin(); it != r[u].end(); it++)
//	{
//		for (set<string>::iterator secondit = r[v].begin(); secondit != r[v].end(); secondit++)
//		{
//			double px = MT[u][*it].pro;
//			double py = MT[v][*secondit].pro;
//
//			vector<string> cur;
//			cur.clear();
//			cur.push_back(*it); cur.push_back(*secondit);
//			
//			double pxy = JPT[Pair(u, v)][cur].pro;
//				
//			if (pxy != 0)
//			{
//				score += pxy * log(pxy / px / py);
//			}
//			//cout << score << endl;
//		}
//	}
//	return score;
//}
//
//
//void get_Weight()
//{
//	for (int u = 1; u <= 13; u++)
//	{
//		for (int v = u + 1; v <= 13; v++)
//		{
//			double curwei = get_MI(u, v);
//			GV.push_back(Edge(u, v, curwei));
//						
//		}
//	}
//}
///********************************************获取权重数组 ED********************************************************************************************/
//
//
///********************************************获得MSWT ST************************************************************************************************/
////prim获取最大生成树
//void prim_MSWT(int root)
//{
//	fill(visited, visited + maxn, 0);
//	fill(d, d + maxn, -INF);
//	d[root] = 0;
//	double ans = 0;
//	
//	for (int i = 1; i <= 13; i++)
//	{
//		double MAXD = -INF;
//		int u = -1;
//		for (int id = 1; id <= 13; id++)
//		{
//			if (d[id] > MAXD)
//			{
//				MAXD = d[id];
//				u = id;
//			}
//		}
//
//		visited[u] = true;
//		ans += d[u];
//		
//		for (int v = 1; v <= 13; v++)
//		{
//			if (G[u][v] == 1 && visited[v] == false && Weight[u][v] < d[v])
//			{
//				d[v] = Weight[u][v];
//			}
//		}
//	}
//	cout <<"prim生成的最大权重: "<< ans << endl;
//}
//
////并查集压缩路径+查找
//int findfather(int u)
//{
//	if (father[u] == u)
//		return u;
//	else
//		return father[u] = findfather(father[u]);
//}
//
////kruskal获取最大生成树
//void kruskal_MSWT()
//{
//	double ans = 0;
//	
//	sort(GV.begin(), GV.end(), cmp);
//	//并查集初始化
//	for (int id = 1; id <= 13; id++)
//	{
//		father[id] = id;
//	}
//	int curedgenum = 0;
//	for (int i = 0; i < GV.size(); i++)
//	{
//		int fa = findfather(GV[i].u);
//		int fb = findfather(GV[i].v);
//		if (fa != fb)
//		{
//			ans += GV[i].wei;
//			
//			father[fa] = fb;
//			MSWT.push_back(GV[i]);
//			curedgenum++;
//
//			if (curedgenum == n - 1)
//				break;
//		}
//	}
//
//	cout << "MSWT权重: " << ans << endl;
//}
///********************************************获得MSWT ED************************************************************************************************/
//
//
//
///********************************************获得BN ST**************************************************************************************************/
//void dfs(int father, int u)
//{
//	cout << Name[u] << endl;
//	
//	visited[u] = true;
//	Node cur(u, Name[u]);
//	cur.parent.push_back(father);
//
//	for (int v = 1; v <= 13; v++)
//	{
//		if (G[u][v] == 1 && visited[v] == false)
//		{
//			
//			cur.child.push_back(v);			
//			dfs(u,v);
//
//		}
//	}
//	BN.push_back(cur);
//}
//
//void get_BN(int root)
//{
//	//向量图-》邻接矩阵
//	for (int i = 0; i < MSWT.size(); i++)
//	{
//		int u = MSWT[i].u;
//		int v = MSWT[i].v;
//		double wei = MSWT[i].wei;
//		
//		G[u][v] = G[v][u] = 1;
//		Weight[u][v] = Weight[v][u] = wei;
//	}
//
//	cout << "输出" << endl;
//	//深度优先遍历
//	dfs(0, root);
//}
///********************************************获得BN ED**************************************************************************************************/
//int main()
//{
//	//初始化数据
//	memset(G, 1, sizeof(G));
//	fill(Weight[0], Weight[0] + maxn*maxn, 0);
//	initName();
//	
//
//	//数据预处理
//	cout << endl;
//	cout << "--------------------------------------数据预处理---------------------------------------------" << endl;
//	get_dataset();
//
//
//	//建立表项
//	construct_MT_JPT();	
//
//
//	//记录数据+计数
//	cout << "--------------------------------------数据训练-----------------------------------------------" << endl;
//	get_trainingset();
//	trainingsetsize = trainingset.size();
//	
//
//	//获得权重+构建向量图
//	cal_pro();
//	get_Weight();
//
//
//	//获得最大权生成树
//	cout << "--------------------------------------生成MSWT-----------------------------------------------" << endl;
//	kruskal_MSWT();
//	//prim_MSWT(1);
//	for (vector<Edge>::iterator it = MSWT.begin(); it != MSWT.end(); it++)
//	{
//		cout << it->u << " " << it->v << "\t" << it->wei;
//		cout << endl;
//	}
//
//
//	//获得贝叶斯网络
//	cout << "--------------------------------------观察贝叶斯网络(树)-------------------------------------" << endl;
//	int root;
//	cout << "输入树根的编号(1<= && <=13)，观察贝叶斯网络的结构：" << endl;
//	cin >> root;
//	get_BN(root);
//
//
//	//测试输出	
//	for (vector<Node>::iterator it = BN.begin(); it != BN.end(); it++)
//	{
//		cout << "***************************************************" << endl;
//		cout << "当前结点：" << it->name<<endl;
//		cout << "父属性结点：" << endl;
//		for (vector<int>::iterator pit = it->parent.begin(); pit != it->parent.end(); pit++)
//		{
//			cout << Name[*pit] << "\t";
//		}
//		cout << endl;
//		cout << "孩子属性结点：" << endl;
//		for (vector<int>::iterator cit = it->child.begin(); cit != it->child.end(); cit++)
//		{
//			cout << Name[*cit] << "\t";
//		}
//		cout << endl;
//		cout << "***************************************************" << endl << endl;
//	}
//	
//
//	return 0;
//}