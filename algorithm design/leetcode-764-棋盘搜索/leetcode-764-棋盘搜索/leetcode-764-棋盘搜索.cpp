// leetcode-764-ÆåÅÌËÑË÷.cpp : Defines the entry point for the console application.
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
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
		int K = 0;
		vector<vector<int>> grid(N, vector<int>(N, 1));
		for (int i = 0; i < mines.size(); i++)
		{
			grid[mines[i][0]][mines[i][1]] = 0;
		}
		vector<vector<vector<int>>> dp(4, vector<vector<int>>(N, vector<int>(N, 0)));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int x = N - i - 1;
				int y = N - j - 1;
				dp[0][i][j] = grid[i][j] == 0 ? 0 : (j == 0 ? 1 : 1 + dp[0][i][j - 1]);
				dp[1][i][j] = grid[i][j] == 0 ? 0 : (i == 0 ? 1 : 1 + dp[1][i - 1][j]);
				dp[2][i][y] = grid[i][y] == 0 ? 0 : (y == N - 1 ? 1 : 1 + dp[2][i][y + 1]);
				dp[3][x][j] = grid[x][j] == 0 ? 0 : (x == N - 1 ? 1 : 1 + dp[3][x + 1][j]);
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				K = max(K, min({ dp[0][i][j],dp[1][i][j],dp[2][i][j],dp[3][i][j] }));
			}
		}
		return K;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> ve = { { 4,2 } };
	s.orderOfLargestPlusSign(5, ve);
    return 0;
}

