// leetcode-238-数组乘法.cpp : 定义控制台应用程序的入口点。
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
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size()+1);
		if (nums.size() == 0)
			return res;
		int sum = 1;
		for (int i = 0; i < nums.size(); i++)
			sum *= nums[i];
		int pre = 1;
		int after = 1;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			after = after*nums[i];
			res[i] = after;
		}
		res[nums.size()] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i)
				pre = pre*nums[i-1];
			res[i] = res[i + 1] * pre;
		}
		res.pop_back();
		return res;
	}
};
int main()
{

}
