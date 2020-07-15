#include"TreeEncode.h"

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

extern vector<int> tar;

extern map< int, set<string> > av;//属性取值
extern int r[];//属性取值数量
extern vector<Code> HASH;


//标记：A
void cA(int id, Code &curcode)
{
	for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
	{
		int index = (*it)[0] - 'A';
		curcode.sti[index] = *it;
	}
}

//标记：a
void ca(int id, Code &curcode)
{
	for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
	{
		int index = (*it)[0] - 'a';
		curcode.sti[index] = *it;
	}
}

//标记：数字
void cnum(int id, Code &curcode)
{
	for (set<string>::iterator it = av[id].begin(); it != av[id].end(); it++)
	{
		int index = 0;
		for (int i = 0; i < (*it).size(); i++)
		{
			index *= 10;
			index += ((*it)[i] - '0');
		}
		curcode.sti[index] = *it;
	}
}


int find(int id, string value)
{
	int index = 0;

	switch (id)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		index = value[0] - 'A';
		break;

	case 6:
	case 7:
	case 8:
		index = value[0] - 'a';
		break;

	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
		
		for (int i = 0; i < value.size(); i++)
		{
			index *= 10;
			index += (value[i] - '0');
		}
		break;
	default:
		break;
	}

	return index;
}

void string_to_int(int id)
{
	
	Code curcode(id);

	switch (id)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			cA(id, curcode);
			HASH.push_back(curcode);
			break;

		case 6:
		case 7:
		case 8:
			ca(id, curcode);
			HASH.push_back(curcode);
			break;

		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
			cnum(id, curcode);
			HASH.push_back(curcode);
			break;

		default:
			break;
	}
}

void encode()
{
	HASH.push_back(Code(0));
	for (int id = 1; id <= 13; id++)
	{
		string_to_int(id);
	}
	
}

void testout()
{
	for (vector<Code>::iterator it = HASH.begin(); it != HASH.end(); it++)
	{
		cout << "*****************************************" << endl;
		for (int i = 0; i < 105; i++)
		{
			cout << it->sti[i] << "\t";
		}
		cout << endl << "*****************************************" << endl;
	}
}