#pragma once
#include<vector>
#include<string>

using namespace std;

//条件概率树计数
void count_CPtree(int id, vector<string> invec);

//条件概率树计算概率
void cal_CPtree(int id, int depth, Treenode &curCPtree);

//计数函数
void count_JPtable(int id, vector<string> invec);

//获取训练集
void get_trainingset();

//计算边缘概率
void cal_MDpro(int id);
void cal_MD();


//计算联合概率
void cal_JPpro(int id);
void cal_JPtable();


//利用边缘分布传播计算条件概率
//计算条件概率
double cal_mulJP(int id, vector<string> con);
void cal_CPpro(int id);
void cal_CPtable();


//总训练函数
void train();