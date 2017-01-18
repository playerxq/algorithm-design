// leetcode-287-找到数组中的重复元素.cpp : 定义控制台应用程序的入口点。
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
	int findDuplicate(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int n = nums.size()-1;
		if (n == 0)
			return 1;
		int slow = 0;
		int fast = 0;
		int meet = 0;
		while (1)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow==fast)
			{
				meet = slow;
				break;
			}
		}
		slow = 0;
		while (slow!= meet)
		{
			slow = nums[slow];
			meet = nums[meet];
		}
		return slow;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(2);
	ve.push_back(5);
	ve.push_back(9);
	ve.push_back(6);
	ve.push_back(9);
	ve.push_back(3);
	ve.push_back(8);
	ve.push_back(9);
	ve.push_back(7);
	ve.push_back(1);
	Solution s;
	s.findDuplicate(ve);
	return 0;
}

