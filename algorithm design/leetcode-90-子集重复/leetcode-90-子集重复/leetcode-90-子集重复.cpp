// leetcode-90-子集重复.cpp : 定义控制台应用程序的入口点。
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        temp.clear();
        res.push_back(temp);
        int pre = 0;
        for(int i = 0;i<n;i++)
        {
			int tmp = res.size();
            if(i==0||nums[i]!=nums[i-1])
            {
                for(int k = 0;k<tmp;k++)
                {
					vector<int> s;
					s = res[k];
                    res.push_back(s);
                    res.back().push_back(nums[i]);
                }
            }
            else
            {
                for(int k = pre;k<tmp;k++)
                {
					vector<int> s;
					s = res[k];
                    res.push_back(s);
                    res.back().push_back(nums[i]);
                }
            }
			pre = tmp;
        }
        return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	s.subsetsWithDup(nums);
}

