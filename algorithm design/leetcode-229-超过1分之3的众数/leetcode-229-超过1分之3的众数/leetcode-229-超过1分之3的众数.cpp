// leetcode-229-超过1分之3的众数.cpp : 定义控制台应用程序的入口点。
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
    vector<int> majorityElement(vector<int>& nums) {
		vector<int> res;
		if(nums.size()==0)
			return res;
		int cnt1 = 0;
		int cnt2 = 0;
		int cand1 = 0;
		int cand2 = 1;
		for(int i = 0;i<nums.size();i++)
		{
			if(nums[i]==cand1)
				cnt1++;
			else if(nums[i]==cand2)
				cnt2++;
			else if (cnt1==0)
			{
				cand1 = nums[i];
				cnt1 = 1;
			}
			else if(cnt2==0)
			{
				cand2 = nums[i];
				cnt2 = 1;
			}
			else
			{
				cnt1--;
				cnt2--;
			}
		}
		cnt1 = cnt2 = 0;
		for(int i = 0;i<nums.size();i++)
		{
		    if(nums[i]==cand1)
		        cnt1++;
		    else if(nums[i]==cand2)
		        cnt2++;
		}
		if(cnt1>nums.size()/3)
			res.push_back(cand1);
		if(cnt2>nums.size()/3)
			res.push_back(cand2);
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

