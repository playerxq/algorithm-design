// leetcode-809-×Ö·û´®Æ¥Åä.cpp : Defines the entry point for the console application.
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
	string derepeat(string s)
	{
		string res;
		int id = 0;
		for (; id < s.size(); id++)
		{
			if (!id)
				res += s[0];
			else if (s[id] == s[id - 1])
				continue;
			else
				res += s[id];
		}
		return res;
	}
	void getgroup(string s,vector<string>& ve)
	{
		int n = s.size();
		string res;
		for (int id = 0; id < n; id++)
		{
			if (id == 0)
				res = s[0];
			else if (s[id] != s[id - 1])
			{
				ve.push_back(res);
				res = s[id];
			}
			else
				res += s[id];
		}
		ve.push_back(res);
	}
	int expressiveWords(string S, vector<string>& words) {
		int n = words.size();
		string cur = derepeat(S);
		vector<string> res;
		for (int i = 0; i < n; i++)
		{
			if (cur == derepeat(words[i]))
			{
				res.push_back(words[i]);
			}
		}
		int cnt = res.size();
		vector<string> gp;
		getgroup(S,gp);
		int m = gp.size();
		for (int i = 0; i < res.size(); i++)
		{
			vector<string> subgp;
			getgroup(res[i],subgp);
			for (int j = 0; j < m; j++)
			{
				if (gp[j].size() < 3 && gp[j].size() != subgp[j].size())
				{
					cnt--;
					break;
				}
				else if (gp[j].size() >= 3 && gp[j].size() < subgp[j].size())
				{
					cnt--;
					break;
				}
			}
		}
		return cnt;
	}
};

int main()
{
	Solution s;
	string S = "aaa";
	vector<string> ve = { "aaaa" };
	s.expressiveWords(S,ve);
    return 0;
}

