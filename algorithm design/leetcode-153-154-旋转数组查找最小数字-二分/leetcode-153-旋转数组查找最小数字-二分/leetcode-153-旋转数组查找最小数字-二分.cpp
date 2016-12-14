// leetcode-153-��ת���������С����-����.cpp : �������̨Ӧ�ó������ڵ㡣
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
//���ظ�Ԫ��
class Solution1 {
public:
	int bin_search(vector<int>& nums, int st, int ed)
	{
		if(st>=ed)
			return nums[st];
		int mid = (st+ed)/2;
		if(nums[mid]>nums[ed])
			return bin_search(nums,mid+1,ed);
		else if(nums[mid]<nums[ed])
			return bin_search(nums,st,mid);
		else
			return nums[ed];
	}
    int findMin(vector<int>& nums) {
		int ed = nums.size();
		int st = 0;
		int ans = bin_search(nums,st,ed-1);
		return ans;
    }
};
//���ظ�Ԫ��
class Solution {
public:
	int bin_search(vector<int>& nums, int st, int ed)
	{
		if(st>=ed)
			return nums[st];
		int mid = (st+ed)/2;
		if(nums[mid]>nums[ed])
			return bin_search(nums,mid+1,ed);
		else if(nums[mid]<nums[ed])
			return bin_search(nums,st,mid);
		else
		{
			if(mid==ed)
				return nums[ed];
			else
			{
				int ans = nums[st];
				for(int i = st;i<=ed;i++)
					ans = min(ans,nums[i]);
				return ans;
			}
		}
	}
    int findMin(vector<int>& nums) {
		int ed = nums.size();
		int st = 0;
		int ans = bin_search(nums,st,ed-1);
		return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(3);
	s.findMin(nums);
}

