// leetcode-736-递归计算表达式.cpp : Defines the entry point for the console application.
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
	string parse(string s, int& st)
	{
		int ed = st + 1;
		int cnt = 1;
		int temp = st;
		if (s[st] == '(')
		{
			while (cnt)
			{
				if (s[ed] == '(')
					cnt++;
				else if (s[ed] == ')')
					cnt--;
				ed++;
			}
		}
		else
		{
			while (ed < s.size() && s[ed] != ' ')
				ed++;
		}
		st = ed + 1;
		return s.substr(temp, ed - temp);
	}
	int helper(string s, unordered_map<string, int> mp)
	{
		if (s[0] == '-' || (s[0] >= '0'&&s[0] <= '9'))
			return stoi(s);
		else if (s[0] != '(')
			return mp[s];
		s = s.substr(1, s.size() - 2);
		int st = 0;
		string wd;
		wd = parse(s, st);
		if (wd == "let")
		{
			while (1)
			{
				string v = parse(s, st);
				if (st > s.size())
					return helper(v, mp);
				mp[v] = helper(parse(s, st), mp);
			}
		}
		else if (wd == "add")
		{
			return helper(parse(s, st), mp) + helper(parse(s, st), mp);
		}
		else
		{
			return helper(parse(s, st), mp) * helper(parse(s, st), mp);
		}
	}
	int evaluate(string expression) {
		unordered_map<string, int> mp;
		return helper(expression, mp);
	}
};
int main()
{
    return 0;
}

