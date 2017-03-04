// leetcode-456-数组大小.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2)
			return false;
		vector<int> le_min(n+1,INT_MIN);
		vector<int> ri_max(n+1,INT_MIN);
		int minn = INT_MAX;
		for (int i = 1; i < n; i++)
		{
			if (nums[i - 1] < minn)
			{
				minn = nums[i-1];
			}
			if (nums[i] > minn)
				le_min[i] = minn;
			else
				le_min[i] = INT_MIN;
		}
		stack<int> st;
		st.push(nums[n-1]);
		ri_max[n - 1] = INT_MIN;
		for (int i = n - 2; i >= 0; i--)
		{
			if (st.empty())
				st.push(nums[i]);
			else
			{
				while (!st.empty()&&st.top() < nums[i])
				{
					ri_max[i] = st.top();
					st.pop();
				}
				st.push(nums[i]);
			}
		}
		for (int i = 1; i < n - 1; i++)
		{
			if (ri_max[i] > le_min[i] && le_min[i]!=INT_MIN&&ri_max[i]!=INT_MIN)
				return true;
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve = {3,2,1};
	Solution s;
	s.find132pattern(ve);
	return 0;
}

