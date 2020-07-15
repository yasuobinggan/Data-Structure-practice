#pragma once

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



/*条件概率表定义 ST*/
//二级表项
struct CPtableI
{
	int cnt;
	double pro;
	CPtableI() {}
	CPtableI(int _cnt)
	{
		cnt = _cnt;
	}
	CPtableI(int _cnt, double _pro)
	{
		cnt = _cnt;
		pro = _pro;
	}
};

//二级表头
struct  CPtableH
{
	int sumcnt;
	map<string, CPtableI> curCPtableI;

	CPtableH() {}
	CPtableH(int _sumcnt)
	{
		sumcnt = _sumcnt;
	}
	CPtableH(int _sumcnt, map<string, CPtableI> _curCPtableI)
	{
		sumcnt = _sumcnt;
		curCPtableI = _curCPtableI;
	}
};
/*条件概率表定义 ED*/

//条件概率树的一个结点
struct Treenode {
	string name;//结点名称（属性名称）
	int id;//结点标号（属性标号）

	string value;//上一层分支的取值
	int valueid;//上一层分支的取值的编号


	bool flag;//标记是(true)为叶节点（叶节点为路径上的目标结点）//叶结点的下一层是概率结点	
	
	int sumcnt;//联合概率（向下传递）
	int cnt;//概率结点的计数
	
	double pro;//概率结点的条件概率
	

	vector<int> path;//节点存储的路径上的结点属性的取值
	
	Treenode* child;//动态开辟内存
};


/*
struct Treenode
{
	TreeH Treehead;
	TreeH child[105];//孩子结点
};
*/


//建立贝叶斯网络结点:一个结点一个条件概率树(表)
struct Node {
	
	int id;//属性标号
	string name;//属性名

	//联合分布表
	map<vector<string>, CPtableI> JPtable;

	//条件概率表
	map<vector<string>, CPtableH> CPtable;

	//条件概率树
	Treenode CPtree;

	//边缘分布表
	map<string, CPtableI> MD;

	//既为属性的条件属性
	vector<Node> parent;
	//属性的孩子属性
	vector<Node> child;

	Node() {}
	Node(int _id, string _name)
	{
		id = _id;
		name = _name;
	}
};



//获得当棋属性+条件属性编号
vector<int> get_condition_id(int id);



//构建边缘分布函数
void construct_MD(int id);

//dfs生成联合概率表
void build_JPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableI> &curJPtable);
//构建联合分布表
void construct_JPT(int id);

//dfs函数生成条件概率表表项
void build_CPtable(int id, vector<int> condition, int index, vector<string> curcon, map<vector<string>, CPtableH> &curCPtable);
//构建条件概率表
void construct_CPT(int id);

//建表的优化策略
void construct_JPT_CPT(int id);

//dfs建立条件概率树
void build_CPtree(int id, vector<int> condition, int index, vector<string> curcon, Treenode &curCPtree, int &cnt);
//建立条件概率树
void construct_CPtree(int id);


//构建贝叶斯网络
void construct_BayesianNW();