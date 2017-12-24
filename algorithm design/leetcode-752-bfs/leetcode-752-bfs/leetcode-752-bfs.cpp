// leetcode-752-bfs.cpp : Defines the entry point for the console application.
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
	vector<string> nextstr(string key)
	{
		vector<string> res;
		for (int i = 0; i < 4; i++)
		{
			string tmp = key;
			tmp[i] = (key[i] - '0' + 1) % 10 + '0';
			res.push_back(tmp);
			tmp[i] = (key[i] - '0' - 1+10) % 10 + '0';
			res.push_back(tmp);
		}
		return res;
	}
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> dd(deadends.begin(), deadends.end());
		unordered_set<string> vis;
		queue<string> Q;
		string st = "0000";
		if (dd.find(st) != dd.end())
			return -1;
		vis.insert(st);
		Q.push(st);
		int res = 0;
		while (!Q.empty())
		{
			int k = Q.size();
			for (int i = 0; i < k; i++)
			{
				string cur = Q.front();
				Q.pop();
				vector<string> tt = nextstr(cur);
				for (auto ss : tt)
				{
					if (ss == target) return ++res;
					if (vis.find(ss) != vis.end()) continue;
					if ((dd.find(ss) == dd.end()))
					{
						vis.insert(ss);
						Q.push(ss);
					}
				}
			}
			++res;
		}
		return -1;
	}
};
int main()
{
    return 0;
}

