// leetcode-65-判断是否是有效数字.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
		s.erase(0,s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ")+1);
		int p = s.find('e');
		if(string::npos!=p)
		{
			string s1 = s.substr(0,p);
			string s2 = s.substr(p+1);
			bool b1 = pureNumber(s1);
			bool b2 = pureNumber(s2,true);
			return b1&&b2;
		}
		return pureNumber(s);
    }
	bool pureNumber(string s, bool integerOnly = false)
	{
		bool num = false;
		int i = 0;
		if('-'==s[i]||'+'==s[i]) i++;
		for(;i<s.size();i++)
		{
			if('.'==s[i])
			{
				if(integerOnly)
					return false;
				else
					integerOnly = true;
			}
			else if(s[i]>='0'&&s[i]<='9')
				num = true;
			else
				return false;
		}
		return num;
	}
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

