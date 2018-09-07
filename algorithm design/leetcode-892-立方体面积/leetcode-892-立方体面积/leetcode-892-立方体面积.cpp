// leetcode-892-立方体面积.cpp : 定义控制台应用程序的入口点。
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
	int surfaceArea(vector<vector<int>>& grid) {
		int xy = 0;
		int yz = 0;
		int xz = 0;
		for (int x = 0;x < grid.size();x++)
		{
			for (int y = 0;y < grid[0].size();y++)
			{
				if (grid[x][y])
				{
					xy += 2;
					if (grid[x][y] - helper(grid, x - 1, y) > 0) yz += grid[x][y] - helper(grid, x - 1, y);
					if (grid[x][y] - helper(grid, x + 1, y) > 0) yz += grid[x][y] - helper(grid, x + 1, y);

					if (grid[x][y] - helper(grid, x, y - 1) > 0) xz += grid[x][y] - helper(grid, x, y - 1);
					if (grid[x][y] - helper(grid, x, y + 1) > 0) xz += grid[x][y] - helper(grid, x, y + 1);
				}
			}
		}
		return xy + yz + xz;
	}
	int helper(vector<vector<int>>& grid, int x, int y)
	{
		if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
			return 0;
		return grid[x][y];
	}
};

int main()
{
    return 0;
}

