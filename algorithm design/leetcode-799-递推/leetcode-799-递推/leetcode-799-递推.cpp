// leetcode-799-µÝÍÆ.cpp : Defines the entry point for the console application.
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
	double champagneTower(int poured, int query_row, int query_glass) {
		if (!poured)
			return 0;
		vector<vector<double>> dp(101, vector<double>(101,0.0));
		dp[0][0] = poured;
		for (int i = 0; i <= query_row; i++)
		{
			for (int j = 0; j <= query_glass; j++)
			{
				double cur = dp[i][j];
				dp[i][j] = (cur > 1.0) ? 1.0 : cur;
				cur = (cur > 1.0) ? (cur - 1.0) : 0.0;
				dp[i + 1][j] += cur / 2;
				dp[i + 1][j + 1] += cur / 2;
			}
		}
		return dp[query_row][query_glass];
	}
};
int main()
{
	Solution s;
	s.champagneTower(1000000000,99,99);
    return 0;
}

