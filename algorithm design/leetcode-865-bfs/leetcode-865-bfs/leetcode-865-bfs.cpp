// leetcode-865-bfs.cpp : Defines the entry point for the console application.
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
	int shortestPathAllKeys(vector<string>& grid) {
		int m = grid.size();
		int n = m ? grid[0].size() : 0;
		if (!m || !n) return 0;
		vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(64,0)));
		vector<int> dirs = { 0,-1,0,1,0 };
		queue<pair<int, int>> q;
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == '@')
				{
					q.push(make_pair(i*n+j,0));
					vis[i][j][0] = 1;
				}
				if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
					sum++;
			}
		}
		int res = 0;
		while (!q.empty())
		{
			int sz = q.size();
			for (int i = 0; i < sz; i++)
			{
				int x = q.front().first / n;
				int y = q.front().first%n;
				int cur = q.front().second;
				q.pop();
				if (cur == ((1 << sum) - 1))
					return res;
				for (int d = 0; d < 4; d++)
				{
					int nx = x + dirs[d];
					int ny = y + dirs[d + 1];
					int temp = cur;
					if (nx<0 || nx >= m || ny<0 || ny >= n || grid[x][y] == '#') continue;
					if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f')
					{
						temp = cur|(1 << (grid[nx][ny] - 'a'));
					}
					else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F')
					{
						if (!(temp&(1 << (grid[nx][ny] - 'A'))))
							continue;
					}
					if (!vis[nx][ny][temp])
					{
						vis[nx][ny][temp] = true;
						q.push(make_pair(nx*n+ny,temp));
					}
				}
			}
			res++;
		}
		return -1;
	}
};
int main()
{
    return 0;
}

