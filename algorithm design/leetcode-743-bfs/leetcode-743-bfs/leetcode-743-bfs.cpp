// leetcode-743-bfs.cpp : Defines the entry point for the console application.
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
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> vis(N+1,-1);
		vector<vector<int>> dir(N+1);
		vector<vector<int>> mp(N + 1, vector<int>(N + 1, -1));
		int nn = times.size();
		for (int i = 0; i < nn; i++)
		{
			dir[times[i][0]].push_back(times[i][1]);
			mp[times[i][0]][times[i][1]] = times[i][2];
		}
		vis[K] = 0;
		queue<int> Q;
		Q.push(K);
		int sm = 0;
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			int k = dir[cur].size();
			for (int i = 0; i < k; i++)
			{
				if (vis[dir[cur][i]] == -1 || vis[dir[cur][i]] > vis[cur] + mp[cur][dir[cur][i]])
				{
					vis[dir[cur][i]] = vis[cur] + mp[cur][dir[cur][i]];
					Q.push(dir[cur][i]);
				}
			}
		}
		for (int i = 1; i <= N; i++)
		{
			if (vis[i] == -1)
				return -1;
			else
				sm = max(sm,vis[i]);
		}
		return sm;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> v;
	v = {{2, 1, 1}, { 2, 3, 1 }, { 3, 4, 1 }
	};
	s.networkDelayTime(v,4,2);
    return 0;
}

