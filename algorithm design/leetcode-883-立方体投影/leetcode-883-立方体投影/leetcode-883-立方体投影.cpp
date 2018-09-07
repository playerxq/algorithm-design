// leetcode-883-立方体投影.cpp : 定义控制台应用程序的入口点。
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
	int projectionArea(vector<vector<int>>& grid) {
		int n = grid.size();
		if (!n)
			return 0;
		int m = grid[0].size();
		if (!m)
			return 0;
		int sum = 0;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (grid[i][j])
					sum++;
			}
		}
		for (int i = 0;i < n;i++)
		{
			int tmp = INT_MIN;
			for (int j = 0;j < m;j++)
			{
				if (grid[i][j] > tmp)
					tmp = grid[i][j];
			}
			sum += tmp;
		}
		for (int j = 0;j < m;j++)
		{
			int tmp = INT_MIN;
			for (int i = 0;i < n;i++)
			{
				if (grid[i][j] > tmp)
					tmp = grid[i][j];
			}
			sum += tmp;
		}
		return sum;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> ve = { { 2,2,2 },{ 2,1,2 },{ 2,2,2 } };
	s.projectionArea(ve);
    return 0;
}

