// leetcode-750-ур╬ьпн.cpp : Defines the entry point for the console application.
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
	int f(int n)
	{
		return n*(n - 1) / 2;
	}
	int countCornerRectangles(vector<vector<int>>& grid) {
		int m = grid.size();
		if (!m||m==1)
			return 0;
		int n = grid[0].size();
		if (!n||n==1)
			return 0;
		int res = 0;
		vector<int> tmp(n+1,0);
		for (int i = 0; i < n; i++)
			tmp[i] = grid[0][i];
		for (int i = 1; i < m; i++)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				for (int l = 0; l< n; l++)
				{
					tmp[l] = grid[i][l] * grid[k][l];
				}
				int t = 0;
				for (int j = 0; j < n; j++)
				{
					if (tmp[j] != 0)
						t++;
				}
				if(t)
					res += f(t);
			}
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> grid = { {0, 1, 0},{1, 0, 1},{1, 0, 1},{0, 1, 0} };
	Solution s;
	s.countCornerRectangles(grid);
    return 0;
}

