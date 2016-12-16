// leetcode-164-桶排序找到最大相近数字-难.cpp : 定义控制台应用程序的入口点。
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
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
		if(n<2)
			return 0;
		
		int minx, maxx;
		minx = maxx = nums[0];
		for(int i = 1;i<n;i++)
		{
			if(nums[i]<minx)
				minx = nums[i];
			if(nums[i]>maxx)
				maxx = nums[i];
		}
		int bu_size = max(1,(maxx-minx)/(n-1));
		int bu_num = (maxx-minx)/bu_size+1;
		vector<int> bu_min(bu_num,INT_MAX);
		vector<int> bu_max(bu_num,INT_MIN);
		vector<int> bu_cnt(bu_num,0);
		for(int i = 0;i<n;i++)
		{
			int bu_id = (nums[i]-minx)/bu_size;
			bu_cnt[bu_id]++;
			bu_min[bu_id] = min(nums[i],bu_min[bu_id]);
			bu_max[bu_id] = max(nums[i],bu_max[bu_id]);
		}
		int las = minx;
		int ans = INT_MIN;
		for(int i = 0;i<bu_num;i++)
		{
			if(bu_cnt[i])
			{
				ans = max(ans,bu_min[i]-las);
				las = bu_max[i];
			}
		}
		return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

