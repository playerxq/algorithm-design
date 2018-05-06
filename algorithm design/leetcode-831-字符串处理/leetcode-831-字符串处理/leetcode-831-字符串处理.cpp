// leetcode-831-×Ö·û´®´¦Àí.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	void email_fun(string& res, string S, int pos)
	{
		string s = S;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] <= 'Z'&&s[i] >= 'A')
			{
				s[i] ^= 1 << 5;
			}
		}
		string name1 = s.substr(0,pos);
		string name = name1.substr(0,1);
		name.append("*****");
		name += name1.substr(name1.size()-1,1);
		//string name = to_string(name1[0]) + "*****" + to_string(name1[name1.size() - 1]);
		res = name + s.substr(pos);
	}
	void phone_fun(string& res, string S)
	{
		string s;
		for (int i = 0; i < S.length(); i++)
		{
			if (isdigit(S[i]))
				s += S[i];
		}
		if (s.length() == 10)
		{
			res = "***-***-" + s.substr(6);
		}
		else
		{
			int l = s.length() - 10;
			string t;
			for (int j = 0; j < l; j++)
				t += "*";
			res = '+' + t + '-' + "***-***-" + s.substr(s.size()-4);
		}
	}
	string maskPII(string S) {
		string res;
		int pos = -1;
		if ((pos = S.find('@')) != string::npos)
		{
			email_fun(res,S,pos);
		}
		else
		{
			phone_fun(res,S);
		}
		return res;
	}
};
int main()
{
	Solution s;
	s.maskPII("86-(10)12345678");
    return 0;
}

