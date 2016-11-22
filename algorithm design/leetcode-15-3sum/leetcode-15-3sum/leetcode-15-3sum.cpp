// leetcode-15-3sum.cpp : 定义控制台应用程序的入口点。
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i ++) {
            // in case of duplicate solutions
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            int lf = i + 1;
            int rt = nums.size() - 1;
            while(lf < rt) {
                int b = nums[lf];
                int c = nums[rt];
                if(0 == a + b + c) {
                    ans.push_back(vector<int> {a, b, c});
                    // in case of duplicate solutions
                    while(lf < nums.size() && nums[lf] == b) lf ++;
                    // in case of duplicate solutions
                    while(rt >= 0 && nums[rt] == c) rt --;
                }
                else if(a + b + c > 0) rt --;
                else lf ++;
            }
        }
        return ans;
    }
};
*/
class Solution1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        
        if(nums.size() < 3) 
        {
            if(nums.size()==1)
            return nums[0];
            else
            return nums[0]+nums[1];
        }
        ans = nums[0]+nums[1]+nums[2];
        
        for(int i = 0; i < nums.size() - 2; i ++) {
            // in case of duplicate solutions
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            int lf = i + 1;
            int rt = nums.size() - 1;
            while(lf < rt) {
                int b = nums[lf];
                int c = nums[rt];
				int temp = a+b+c;
                if(abs(temp-target)<abs(ans-target)) {
                    ans = temp;
                    // in case of duplicate solutions
                    while(lf < nums.size()-1 && nums[lf+1] == b) lf ++;
                    // in case of duplicate solutions
                    while(rt >= 1 && nums[rt-1] == c) rt --;
                }
                if(a + b + c > target) rt --;
                else lf ++;
            }
        }
        return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution1 s;
	vector<int> a;
	a.push_back(0);
	a.push_back(2);
	a.push_back(1);
	a.push_back(-3);
	s.threeSumClosest(a,1);
}

