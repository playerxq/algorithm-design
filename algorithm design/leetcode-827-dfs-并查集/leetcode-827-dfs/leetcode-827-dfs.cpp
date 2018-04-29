// leetcode-827-dfs.cpp : Defines the entry point for the console application.
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
	int find(int x, vector<int>& p)
	{
		return p[x] == x ? x : p[x] = find(p[x],p);
	}
	void union_set(int a, int b, vector<int>& p, vector<int>& dep, vector<int>& siz)
	{
		a = find(a,p);
		b = find(b,p);
		if (a == b)
			return;
		if (dep[a] > dep[b])
		{
			p[b] = a;
			siz[a] += siz[b];
		}
		else
		{
			if (dep[a] == dep[b])
				dep[b]++;
			siz[b] += siz[a];
			p[a] = b;
		}
		return;
	}
	void init(vector<int>& p, vector<int>& dep, vector<int>& siz, int n)
	{
		for (int i = 0; i<n; i++)
		{
			p[i] = i;
			dep[i] = 0;
			siz[i] = 1;
		}
	}
	int largestIsland(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<int> p(row*col);
		vector<int> dep(row*col);
		vector<int> siz(row*col);
		init(p,dep,siz,row*col);
		int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
		int res = 1;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == 1)
				{
					for (int d = 0; d < 2; d++) {
						int r = i + dir[d][0];
						int c = j + dir[d][1];
						if (r >= 0 && c >= 0 && grid[r][c] == 1) {
							union_set(i * col + j, r * col + c,p,dep,siz);
							res = max(res, siz[find(i * col + j,p)]);
						}
					}
				}
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == 0)
				{
					map<int, int> mp;
					for (int d = 0; d < 4; d++) {
						int r = i + dir[d][0];
						int c = j + dir[d][1];
						if (r >= 0 && c >= 0 && r<row&&c<col&&grid[r][c] == 1) {
							int parent = find(r*col+c,p);
							mp.insert({parent,siz[parent]});
						}
					}
					int tem = 1;
					for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
					{
						tem += it->second;
					}
					res = max(res,tem);
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> grid = { {1,1},{1,0} };
	s.largestIsland(grid);
    return 0;
}

