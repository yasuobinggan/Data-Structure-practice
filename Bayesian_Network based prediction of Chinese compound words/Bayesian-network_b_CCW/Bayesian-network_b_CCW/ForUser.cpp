#include"InitProblem.h"
#include"GetDataset.h"
#include"TreeEncode.h"
#include"ConstructBN.h"
#include"Training.h"
#include"Inferencing.h"


#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
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


const int maxn = 1005;//贝叶斯网络中最多可能的属性个数
const int maxsize = 105;//属性的最多取值个数



map<string, int> feature;//属性-》标号
map<int, string> Name;//标号-》属性


vector< vector<string> > trainingset;//训练集
int trainingsetsize;//训练集的大小
map< int, set<string> > av;//属性取值
int r[maxn];//属性取值数量
vector<Code> HASH;//属性取值的编码



vector<Node> BN;//贝叶斯网络
vector<int> tar;//最终搜索的目标属性结点



int main()
{
	
	//初始化双音节词实际问题
	cout << "*************************精确推理:枚举推理**************************************" << endl << endl;
	init_feature_Name();
	
	//数据预处理
	cout << "--------------------数据预处理 当前属性的取值:----------------------------------" << endl;
	//初始化属性取值数量上限
	memset(r, 0, sizeof(r));
	get_dataset();
	//预设属性取值上限
	for (int id = 1; id <= 13; id++)
	{
		r[id] = av[id].size();
	}
	//设置目标属性结点
	tar.push_back(5); tar.push_back(8); tar.push_back(13);
	//对目标属性的取值进行编码
	encode();
	//testout();

	//建立表项
	cout << "---------------------构建贝叶斯网络建立表项-------------------------------------" << endl;
	clock_t start = clock();
	construct_BayesianNW();
	clock_t end = clock();

	cout << "建表时间：" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	

	//获得训练集
	cout << "-----------------------------训练-----------------------------------------------" << endl;
	get_trainingset();
	train();
	
	
	cout << "-----------------------------测试集推断-----------------------------------------" << endl;
	start = clock();
	test();
	end = clock();

	cout << "查找时间：" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}


/*

进入	H	H	V	V	H	j	j	j	64	64			64	1
学科	D	D	N	N	D	k	k	k	3	3		g	3	1
长度	D	D	N	N	D	n	n	n	1	1			1	1
美好	E	E	A	A	E	d	d	d	3	3			3	1
共总	H	H	D	V	H	e	j	e	16	15			16	1
验证	H	J	V	V	H	c	a	c	18	4			18	2
解手	I	B	V	N	I	b	k	b	8	8			8	2
老头	K	B	N	N	A	d	k	b	6	2	h		2	2
苹果	B	B	N	N	B	h	h	h	7	13	g		7	2
承受	H	J	V	V	H	j	e	j	24	14	g		24	2
演奏	H	H	V	V	H	h	h	h	1	4			4	3
阿妹	K	A	N	N	A	d	h	h	6	10	h		10	3
牌桌	B	B	N	N	B	o	p	p	32	29			29	3
毛绒	B	B	N	N	B	k	k	q	11	11	g	g	1	3
炮灰	B	B	N	N	B	o	b	b	27	2			2	3
清新	E	E	A	A	E	b	b	f	19	28			12	4
初一	D	D	M	M	C	n	n	a	4	3			23	4
初民	E	A	B	N	A	d	a	a	26	1	g	g	1	4
初民	E	A	B	N	A	d	a	a	26	1	g	g	1	4
圆日	B	B	N	N	C	b	d	a	4	2	g		23	4
私产	E	D	A	N	D	d	j	j	55	3	g	g	3	5
酒工	B	A	N	N	A	r	e	e	12	2		g	2	5
巨资	E	D	A	N	D	a	j	j	3	3			3	5
巨作	E	D	A	N	D	a	k	k	3	19			19	5
剧作	D	D	N	N	D	k	k	k	29	19	g		19	5
习作	H	D	V	N	H	g	k	g	6	19			16	6
试场	H	C	V	N	C	j	b	b	12	28		g	28	6
待到	H	H	V	V	K	i	f	b	7	8	g		2	6
古来	C	H	T	V	C	a	j	a	2	63			11	6
讲理	H	D	V	N	E	i	b	e	12	6			38	6
宏达	E	H	A	V	E	d	f	e	20	8			18	7
脑际	B	C	N	N	D	k	b	f	2	14	g	g	1	7
细条	E	B	A	N	E	a	h	a	6	10		g	6	7
救应	H	H	V	V	H	i	i	i	36	18			36	7
味道	B	B	N	N	B	g	n	g	6	11			6	7
间道	I	B	V	N	B	e	n	n	2	11			11	8
原由	K	D	D	N	D	a	b	b	10	1			1	8
反应	H	H	V	V	D	b	i	a	3	18	g		25	8
独特	K	E	D	A	E	a	d	d	23	4			4	8
开口	I	B	V	N	H	h	k	i	3	4			12	8

*/