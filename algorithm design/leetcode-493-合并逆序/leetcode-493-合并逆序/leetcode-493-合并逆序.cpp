// leetcode-493-合并逆序.cpp : 定义控制台应用程序的入口点。
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
	int merge_sort(vector<int>& nums, int st, int ed)
	{
		if (ed <= st)
			return 0;
		int mid = (st + ed) / 2;
		int a = merge_sort(nums, st, mid);
		int b = merge_sort(nums, mid + 1, ed);
		int cnt = 0;
		int res = a + b;
		for (int i = st, j = mid + 1; i <= mid;)
		{
			if (j > ed || (long long)nums[j] * 2 >= nums[i])
			{
				i++;
				res += cnt;
			}
			else
			{
				j++;
				cnt++;
			}
		}
		vector<int> nn(ed - st + 1, 0);
		for (int i = st, j = mid + 1, k = 0; i <= mid || j <= ed;)
		{
			if (i <= mid && (j > ed || nums[i] <= nums[j]))
			{
				nn[k++] = nums[i++];
			}
			else
				nn[k++] = nums[j++];
		}
		for (int i = 0; i < ed - st + 1; i++)
		{
			nums[st + i] = nn[i];
		}
		return res;
	}
	int reversePairs(vector<int>& nums) {
		int res = 0;
		res = merge_sort(nums, 0, nums.size() - 1);
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve = { 1, 3, 2, 3, 1 };
	Solution s;
	s.reversePairs(ve);
	return 0;
}

