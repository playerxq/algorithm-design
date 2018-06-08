// leetcode-840-Ã¶¾Ù¾ØÕó.cpp : Defines the entry point for the console application.
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
	bool fill_g(vector<vector<int>>& grid, vector<vector<int>>& subg, int x, int y)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[x + i][y + j] < 10 && grid[x + i][y + j] >= 1)
					subg[i][j] = grid[x + i][y + j];
				else
					return false;
			}
		}
		return true;
	}
	bool is_magic(vector<vector<int>>& grid)
	{
		int sum = grid[0][0]+grid[0][1]+grid[0][2];
		int t_sum = 0;
		for (int i = 1; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				t_sum += grid[i][j];
			}
			if (t_sum != sum)
				return false;
			t_sum = 0;
		}
		t_sum = 0;
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				t_sum += grid[i][j];
			}
			if (t_sum != sum)
				return false;
			t_sum = 0;
		}
		t_sum = 0;
		for (int i = 0; i < 3; i++)
		{
			t_sum += grid[i][i];
		}
		if (t_sum != sum)
			return false;
		t_sum = 0;
		for (int i = 0; i < 3; i++)
		{
			t_sum += grid[i][2-i];
		}
		if (t_sum != sum)
			return false;
		return true;
	}
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		int n = grid.size();
		if (!n||n<3)
			return 0;
		int m = grid[0].size();
		if (!m||m < 3)
			return 0;
		vector<vector<int>> subg(3,vector<int>(3,0));
		int cnt = 0;
		for (int i = 0; i + 2 < n; i++)
		{
			for (int j = 0; j + 2 < m; j++)
			{
				if(fill_g(grid,subg,i,j))
					if (is_magic(subg))
						cnt++;
			}
		}
		return cnt;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> grid = { {4, 3, 8, 4},{9, 5, 1, 9},{2, 7, 6, 2} };
	s.numMagicSquaresInside(grid);
    return 0;
}

