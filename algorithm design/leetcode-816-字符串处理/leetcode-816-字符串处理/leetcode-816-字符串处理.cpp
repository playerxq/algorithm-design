// leetcode-816-×Ö·û´®´¦Àí.cpp : Defines the entry point for the console application.
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
	bool is_valid(string fi, string la)
	{
		size_t pos;
		if (fi.size() > 1 && fi[0]=='0')
		{
			return false;
		}
		if (la.size()>=1&&la[la.size() - 1] == '0')
			return false;
		return true;
	}
	vector<string> get_num(string num)
	{
		vector<string> res;
		string la;
		string fi;
		if (is_valid(num,la))
		{
			res.push_back(num);
		}
		for (int i = 1; i < num.size(); i++)
		{
			string temp = num.substr(0, i);
			fi = temp;
			temp += '.';
			temp += num.substr(i);
			la = num.substr(i);
			if (is_valid(fi,la))
				res.push_back(temp);
		}
		return res;
	}
	vector<string> ambiguousCoordinates(string S) {
		string now = S.substr(1,S.size()-2);
		vector<string> res;
		for (int i = 0; i < now.size()-1; i++)
		{
			string s1 = now.substr(0,i+1);
			string s2 = now.substr(i+1);
			vector<string> vs1 = get_num(s1);
			vector<string> vs2 = get_num(s2);
			if (!vs1.size() || !vs2.size())
				continue;
			for (int i1 = 0; i1 < vs1.size(); i1++)
			{
				for (int i2 = 0; i2 < vs2.size(); i2++)
				{
					string rr = '(' + vs1[i1] + ", " + vs2[i2] + ')';
					res.push_back(rr);
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	s.ambiguousCoordinates("(100)");
    return 0;
}

