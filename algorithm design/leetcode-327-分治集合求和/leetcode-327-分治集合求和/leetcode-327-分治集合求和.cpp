// leetcode-327-分治集合求和.cpp : 定义控制台应用程序的入口点。
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
	int mergesort(vector<long long>& sum, int st, int ed, int low, int up)
	{
		if (st >= ed)
			return 0;
		if (st == ed-1)
		{
			if (sum[st] >= low&&sum[st] <= up)
				return 1;
			return 0;
		}
		int mid = (st + ed) / 2;
		int ans = mergesort(sum,st,mid,low,up) + mergesort(sum,mid,ed,low,up);
		int m = mid, n = mid;
		for (int i = st; i< mid; i++)
		{
			while (m < ed && sum[m] - sum[i] < low) m++;
			while (n < ed && sum[n] - sum[i] <= up) n++;
			ans += n - m;
		}
		inplace_merge(sum.begin() + st, sum.begin() + mid, sum.begin() + ed);
		return ans;
	}
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
		{
			if (nums[0] >= lower&&nums[0] <= upper)
				return 1;
			return 0;
		}
		vector<long long> sum(nums.size()+1,0);
		sum[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			sum[i] = sum[i - 1] + nums[i];
		int ans = mergesort(sum,0,nums.size(),lower,upper);
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(-2);
	ve.push_back(5);
	ve.push_back(-1);
	Solution s;
	s.countRangeSum(ve,-2,2);
	return 0;
}

