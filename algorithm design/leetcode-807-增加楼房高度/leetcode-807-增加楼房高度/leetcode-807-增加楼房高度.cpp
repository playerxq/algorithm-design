// leetcode-807-增加楼房高度.cpp : Defines the entry point for the console application.
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
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		vector<int> row_max(grid.size(), INT_MIN);
		vector<int> col_max(grid.size() ? grid[0].size() : 0, INT_MIN);
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				row_max[i] = max(row_max[i], grid[i][j]);
				col_max[i] = max(col_max[i], grid[j][i]);
			}
		}
		int result = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] < row_max[i] && grid[i][j] < col_max[j])
					result += min(row_max[i] - grid[i][j], col_max[j] - grid[i][j]);
			}
		}
		return result;
	}
};
int main()
{
    return 0;
}

