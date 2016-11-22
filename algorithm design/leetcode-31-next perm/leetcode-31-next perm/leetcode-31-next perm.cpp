// leetcode-31-next perm.cpp : 定义控制台应用程序的入口点。
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
    void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		if(n==1)
			return;
		if(n==2)
		{
			int t = nums[0];
			nums[0] = nums[1];
			nums[1] = t;
			return;
		}
		int i = n-2;
		while(i>=0&&nums[i]>=nums[i+1])
			i--;
		if(i<0)
		{
			reverse(nums.begin(),nums.end());
			return;
		}
		int j = n-1;
		while(nums[j]<=nums[i])
			j--;
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
		reverse(nums.begin()+i+1,nums.end());
		return;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> v;
	v.push_back(4);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	Solution s;
	s.nextPermutation(v);
}
