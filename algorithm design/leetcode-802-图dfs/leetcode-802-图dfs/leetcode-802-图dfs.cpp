// leetcode-802-ͼdfs.cpp : Defines the entry point for the console application.
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
	int dfs(int cur, vector<int>& vis, vector<vector<int>>& graph)
	{
		int n = graph[cur].size();
		if (!n)
		{
			vis[cur] = 2;
			return 2;
		}
		for (int i = 0; i < n; i++)
		{
			if (vis[graph[cur][i]] == -1)
			{
				vis[graph[cur][i]] = 1;
				int res = dfs(graph[cur][i], vis, graph);
				if (res != 2)
				{
					vis[cur] = 0;
					return 0;
				}
			}
			else if (vis[graph[cur][i]] == 0)
			{
				vis[cur] = 0;
				return 0;
			}
			else if (vis[graph[cur][i]] == 1)
			{
				vis[cur] = 0;
				return 0;
			}
			else
				continue;
		}
		vis[cur] = 2;
		return 2;
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		vector<int> res;
		int n = graph.size();
		vector<int> vis(n,-1);
		for (int i = 0; i < n; i++)
		{
			if (graph[i].size() == 0)
			{
				res.push_back(i);
				vis[i] = 2;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (vis[i] == -1)
				dfs(i,vis, graph);
		}
		res.clear();
		for (int i = 0; i < n; i++)
			if (vis[i]==2)
				res.push_back(i);
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> ve = { {1,2},{2,3},{5},{0},{5},{},{} };
	s.eventualSafeNodes(ve);
    return 0;
}

