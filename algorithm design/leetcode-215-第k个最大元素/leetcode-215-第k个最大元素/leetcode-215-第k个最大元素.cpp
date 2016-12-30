// leetcode-215-第k个最大元素.cpp : 定义控制台应用程序的入口点。
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
	int partion(vector<int>& nums, int id, int st, int ed)
	{
		int i = st-1;
		int p = nums[ed];
		for(int j = st;j<ed;j++)
		{
			if(nums[j]<p)
			{
				i++;
				int t = nums[i];
				nums[i] = nums[j];
				nums[j] = t;
			}
		}
		i++;
		int t = nums[i];
		nums[i] = p;
		nums[ed] = t;
		int m = i-st;
		if(m==id)
			return i;
		if(m>id)
			return partion(nums,id,st,i-1);
		else
			return partion(nums,id-m-1,i+1,ed);
	}
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
		int id = n-k;
		int res = partion(nums,id,0,n-1);
		return nums[res];
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> ve;
	ve.push_back(7);
	ve.push_back(6);
	ve.push_back(5);
	ve.push_back(4);
	ve.push_back(3);
	ve.push_back(2);
	ve.push_back(1);
	Solution s;
	s.findKthLargest(ve,2);
}

