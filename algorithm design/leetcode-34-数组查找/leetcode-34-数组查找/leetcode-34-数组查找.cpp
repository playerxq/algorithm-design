// leetcode-34-数组查找.cpp : 定义控制台应用程序的入口点。
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
/*
class Solution {
public:
	void bin_search(vector<int>& nums,int target, int l, int r, int& st, int& ed)
	{
		if(l>r)
			return;
		int mid = (l+r)/2;
		if(nums[mid]>target)
		{
			return bin_search(nums,target,l,mid-1,st,ed);
		}
		else if(nums[mid]<target)
		{
			return bin_search(nums,target,mid+1,r,st,ed);
		}
		else
		{
			if(mid>ed)
			{
				ed = mid;
				bin_search(nums,target,mid+1,r,st,ed);
			}
			if(mid<st||st==-1)
			{
				st = mid;
				bin_search(nums,target,l,mid-1,st,ed);
			}
		}
		return;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
		int right = nums.size()-1;
		vector<int > ve;
		ve.clear();
		int l,r;
		l = r = -1;
		bin_search(nums,target,left,right,l,r);
		ve.push_back(l);
		ve.push_back(r);
		return ve;
    }
};
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
		int r = nums.size()-1;
		while(l<r)
		{
			int mid = (l+r)/2;
			if(nums[mid]==target)
				return mid;
			else if(nums[mid]<target)
			{
				l = mid+1;
			}
			else
				r = mid-1;
		}
		if((l==r)&&(nums[l]>target))
		{
			if(l)
				return l;
			return 0;
		}
		else if((l==r)&&(nums[l]<target))
		{
			return l+1;
		}
		else if(l)
		{
			return l;
		}
		else
			return 0;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	//v.push_back(5);
	//v.push_back(6);
	Solution s;
	s.searchInsert(v,2);
}

