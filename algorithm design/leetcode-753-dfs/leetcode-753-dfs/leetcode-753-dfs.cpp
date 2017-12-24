// leetcode-753-dfs.cpp : Defines the entry point for the console application.
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
	bool dfs(string& s, int tot, unordered_set<string>& vis, int n, int k)
	{
		if (vis.size() == tot) return true;
		string prev = s.substr(s.length() - n+1);
		for (int i = 0; i < k; i++)
		{
			string nx = prev;
			nx += (i+'0');
			if (vis.find(nx) == vis.end())
			{
				vis.insert(nx);
				string tt = s;
				s += (i+'0');
				if (dfs(s, tot, vis, n, k))
					return true;
				else
				{
					s = tt;
					vis.erase(nx);
				}
			}
		}
		return false;
	}
	string crackSafe(int n, int k) {
		string s;
		int tot = (int)pow(k,n);
		for (int i = 0; i < n; i++) s += '0';
		unordered_set<string> vis;
		vis.insert(s);
		dfs(s,tot,vis,n,k);
		return s;
	}
};
int main()
{
	Solution s;
	s.crackSafe(1,3);
    return 0;
}

