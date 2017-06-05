// leetcode-565-dfs.cpp : 定义控制台应用程序的入口点。
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
	int recurse(vector<int>& nums, vector<int>& dp, int st, int& mx, int k)
	{
		if (dp[k] >= 0)
			return dp[k];
		if (st == k)
			return 0;
		int hops = recurse(nums, dp, st, mx, nums[k]);
		dp[k] = hops + 1;
		mx = max(mx, dp[k]);
		return dp[k];
	}
	int arrayNesting(vector<int>& nums) {
		vector<int> dp(nums.size(), -1);
		int mx = 0;
		for (int k = 0; k < nums.size(); k++)
		{
			if (dp[k] >= 0) continue;
			int hops = recurse(nums, dp, k, mx, nums[k]);
			dp[k] = hops + 1;
			mx = max(mx, dp[k]);
		}
		return mx;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

