// leetcode-851-dfs.cpp : Defines the entry point for the console application.
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
	int dfs(int cur, vector<vector<int>>& mp, vector<int>& res, vector<int>& quiet)
	{
		if (res[cur] != -1)
			return res[cur];
		if (!mp[cur].size())
			return cur;
		int temp = INT_MAX;
		int id = -1;
		for (int i = 0; i < mp[cur].size(); i++)
		{
			res[mp[cur][i]] = dfs(mp[cur][i],mp,res,quiet);
			if (quiet[res[mp[cur][i]]] < temp)
			{
				temp = quiet[res[mp[cur][i]]];
				id = res[mp[cur][i]];
			}
		}
		if (temp > quiet[cur])
			id = cur;
		res[cur] = id;
		return res[cur];
	}
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		vector<vector<int>> mp(n);
		for (int i = 0; i < richer.size(); i++)
		{
			mp[richer[i][1]].push_back(richer[i][0]);
		}
		vector<int> res(n,-1);
		for (int i = 0; i < n; i++)
		{
			res[i] = dfs(i,mp,res, quiet);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> richer = { {1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3} };
	vector<int> quiet = {3,2,5,4,6,1,7,0};
	s.loudAndRich(richer,quiet);
    return 0;
}

