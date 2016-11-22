// leetcode-41-找到第一个缺失的正数.cpp : 定义控制台应用程序的入口点。
//k个任意正数集合  第一个缺失的正整数(从1开始计算)必然值域为[1,k+1]
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
	int partion(vector<int>& nums)
	{
		int q = -1;
		for(int i = 0;i<nums.size();i++)
		{
			if(nums[i]>0)
			{
				q++;
				swap(nums[i],nums[q]);
			}
		}
		return q;
	}
    int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		if(n==0)
			return 1;
		int k = partion(nums)+1;//[0:k-1]为正数集合 则第一个缺失的数值域为[1:k] 可以作为索引来标识
		int temp = 0;
		int id = k;
		for(int i = 0;i<k;i++)
		{
			temp = abs(nums[i]);
			if(temp<=k)//出现一个正数且落在[1:k]中 将其作为索引并将对应位置为负数
				nums[temp-1] = (nums[temp-1]<0)?nums[temp-1]:-nums[temp-1];
		}
		for(int i = 0;i<k;i++)//查看索引 对应的值为[1:k]
		{
			if(nums[i]>0)//没有出现过
			{
				id = i;
				break;
			}
		}
		return id+1;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> ve;
	ve.push_back(3);
	ve.push_back(4);
	ve.push_back(-1);
	ve.push_back(6);
	ve.push_back(7);
	Solution s;
	s.firstMissingPositive(ve);
}

