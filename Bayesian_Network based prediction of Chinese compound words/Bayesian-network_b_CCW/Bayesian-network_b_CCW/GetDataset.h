#pragma once
//头文件只被编译一次
/*
获取训练集
*/

/**
* 各属性概率:
* 1：P(1st WB);
* 2：P(2nd WB);
* 3：P(1st PosB);
* 4：P(2nd PosB);
* 5：P(TWB)= P(TWB |1st WB,2nd WB,1st PosB,2nd PosB)*P(1stWB)*P(2ndWB)*P(1stPosB)*P(2ndPosB)
* 6：P(1st WM)= P(1st WM|1st WB)*P(1st WB)
* 7：P(2nd WM)= P(2nd WM|2nd WB)*P(2nd WB)
* 8：P(TWM) = P(TWM |1st WM,2nd WM)*P(1st WM)*P(2nd WM)
* 9：P(1st WS) = P(1st WS|1st WM)*P(1st WM)
* 10：P(2nd WS) = P(2nd WS|2nd WM)*P(2nd WM)
* 11：P(1st PosS)
* 12：P(2nd PosS)
* 13：P(TWS) = P(TWS |1st WS,2nd WS,1st PosS,2nd PosS)*P(1st WS)*P(2nd WS)*P(1st PosS)*P(2nd PosS)
*/

#pragma once
//#include<fstream>
//#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

struct sample {
	string s_word;//训练词汇
	string s_1stWB;//第一语素义大类
	string s_2ndWB;//第二语素义大类
	string s_1stPosB;//第一词性大类
	string s_2ndPosB;//第二词性大类
	string s_TWB;//目标词汇大类
	string s_1stWM;//第一语素义中类
	string s_2ndWM;//第二语素义中类
	string s_TWM;//目标词汇中类
	string s_1stWS;//第一语素义小类
	string s_2ndWS;//第二语素义小类
	string s_1stPosS;//第一词性小类
	string s_2ndPosS;//第二词性小类
	string s_TWS;//目标词汇小类
	string mode;//构词方式类别

	sample() {}
	sample(string input, string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l, string m, string n)
	{
		s_word = input;
		s_1stWB = a;
		s_2ndWB = b;
		s_1stPosB = c;
		s_2ndPosB = d;
		s_TWB = e;
		s_1stWM = f;
		s_2ndWM = g;
		s_TWM = h;
		s_1stWS = i;
		s_2ndWS = j;
		s_1stPosS = k;
		s_2ndPosS = l;
		s_TWS = m;
		mode = n;
	}
};


void get_dataset();