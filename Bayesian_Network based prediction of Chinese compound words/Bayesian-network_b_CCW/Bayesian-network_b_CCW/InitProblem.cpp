#include"InitProblem.h"
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

extern map<string, int> feature;//属性-》标号
extern map<int, string> Name;//标号-》属性

void init_feature_Name()
{
	//初始化属性标记
	feature["temp"] = 0;
	feature["1stWB"] = 1; feature["2ndWB"] = 2;
	feature["1stPosB"] = 3; feature["2ndPosB"] = 4;
	feature["TWB"] = 5;

	feature["1stWM"] = 6; feature["2ndWM"] = 7;
	feature["TWM"] = 8;

	feature["1stWS"] = 9; feature["2ndWS"] = 10;
	feature["1stPosS"] = 11; feature["2ndPosS"] = 12;
	feature["TWS"] = 13;

	//标号-》属性
	for (map<string, int>::iterator it = feature.begin(); it != feature.end(); it++)
	{
		Name[it->second] = it->first;
	}
}

