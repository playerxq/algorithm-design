// leetcode-46-排列.cpp : 定义控制台应用程序的入口点。
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
	void dfs(vector<int>& nums, vector<vector<int>>& res, int cur,vector<int> now)
	{
		if(cur==nums.size())
		{
			res.push_back(now);
			return;
		}
		for(int i = 0;i<nums.size();i++)
		{
			if(i&&nums[i]==nums[i-1])
			{
				continue;
			}
			int c1 = 0;
			int c2 = 0;
			for(int j = 0;j<cur;j++)
				if(nums[i]==now[j])
					c1++;
			for(int j = 0;j<nums.size();j++)
				if(nums[j]==nums[i])
					c2++;
			if(c1>=c2)
				continue;
			else
			{
				now.push_back(nums[i]);
				dfs(nums,res,cur+1,now);
				now.pop_back();
			}
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
		vector<vector<int>> res;
		sort(nums.begin(),nums.end());
		int n = nums.size();
		if(n==1)
		{
			res.push_back(nums);
			return res;
		}
		if(n==2)
		{
			res.push_back(nums);
			if(nums[0]!=nums[1])
			{
				reverse(nums.begin(),nums.end());
				res.push_back(nums);
			}
			return res;
		}
		cur.clear();
		dfs(nums,res,0,cur);
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> ve;
	ve.push_back(1);
	ve.push_back(1);
	ve.push_back(2);
	Solution s;
	s.permute(ve);
}

