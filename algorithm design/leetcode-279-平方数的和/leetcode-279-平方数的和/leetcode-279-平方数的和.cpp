// leetcode-279-平方数的和.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1);
		for (int i = 0; i <= n; i++)
			dp[i] = INT_MAX;
		dp[0] = 0;
		int k = 1;
		while (k <= n)
		{
			for (int i = 1; i*i <= k; i++)
			{
				dp[k] = min(dp[k], dp[k - i*i] + 1);
			}
			k++;
		}
		return dp[n];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

