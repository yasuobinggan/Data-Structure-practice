#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

extern const int maxsize;

/*
struct StrtoInt {
	string value;
	int index;

};
*/

struct Code {
	int id;
	string sti[75];//int下标-》string取值
	Code(){}
	Code(int _id)
	{
		id = _id;
	}
};

void cA(int id, Code &curcode);

void ca(int id, Code &curcode);

void cnum(int id, Code &curcode);

int find(int id, string value);

void string_to_int(int id);

void encode();

void testout();