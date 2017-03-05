// leetcode-462-平均数组.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	void swap(vector<int>& nums, int i, int j)
	{
		int t = nums[j];
		nums[j] = nums[i];
		nums[i] = t;
	}
	int partion(vector<int>& nums, int st, int ed)
	{
		int key = nums[st];
		int i = st;
		int j = ed;
		while (i <= j)
		{
			while (i <= j&&nums[i] <= key)
				i++;
			while (i <= j&&nums[j] >= key)
				j--;
			if (i<=ed&&j>=st&&i<=j)
				swap(nums, i, j);
		}
		swap(nums,st,j);
		return j;
	}
	int find_median(vector<int>& nums, int st, int ed, int k)
	{
		if (k > ed - st + 1)
			return -1;
		int pos = partion(nums,st,ed);
		if (pos - st < k - 1)
			return find_median(nums, pos + 1, ed, k - (pos-st+1));
		else if (pos - st == k - 1)
			return nums[pos];
		else
			return find_median(nums,st,pos-1,k);
	}
	int minMoves2(vector<int>& nums) {
		int n = nums.size();
		if (n == 0 || n == 1)
			return 0;
		sort(nums.begin(),nums.end());
		if (n == 2 || n == 3)
			return abs(nums[n - 1] - nums[0]);
		long long sum = 0;
		int mid = INT_MIN;
		mid = find_median(nums,0,n-1,n/2+1);
		for (int i = 0; i < n; i++)
		{
			if (nums[i] != mid)
				sum += abs(nums[i]-mid);
		}
		return sum;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve = { 1,0,0,8,6};
	Solution s;
	s.minMoves2(ve);
	return 0;
}

