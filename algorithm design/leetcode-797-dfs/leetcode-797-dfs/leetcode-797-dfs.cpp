// leetcode-797-dfs.cpp : Defines the entry point for the console application.
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
	void dfs(int cur, vector<int>& ve, vector<vector<int>>& res, vector<vector<int>>& graph, vector<int>& vis)
	{
		int n = graph[cur].size();
		if (cur == graph.size() - 1)
		{
			res.push_back(ve);
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (vis[graph[cur][i]] == 0)
			{
				vis[graph[cur][i]] = 1;
				ve.push_back(graph[cur][i]);
				dfs(graph[cur][i], ve, res, graph, vis);
				ve.pop_back();
				vis[graph[cur][i]] = 0;
			}
		}
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> res;
		if (!n)
			return res;
		vector<int> ve;
		vector<int> vis(n,0);
		ve.push_back(0);
		vis[0] = 1;
		dfs(0,ve,res, graph, vis);
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> graph = {{1, 2}, { 3}, { 3}, {}};
	s.allPathsSourceTarget(graph);
    return 0;
}

