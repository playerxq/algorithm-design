// leetcode-523-子数组和为k倍数.cpp : 定义控制台应用程序的入口点。
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
	bool checkSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		if (!n)
			return false;
		vector<int> sum(n,0);
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				sum[0] = nums[0];
			else
				sum[i] = sum[i - 1] + nums[i];
		}
		unordered_set<int> ss;
		int pre = 0;
		for (int i = 0; i < n; i++)
		{
			if (k != 0)
				sum[i] = sum[i] % k;
			if (ss.count(sum[i]))
				return true;
			ss.insert(pre);
			pre = sum[i];
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

