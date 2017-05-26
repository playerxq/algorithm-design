// leetcode-594-数组找子串.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int findLHS(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ans = 0;
		map<int, int> mp;
		int cur = 0;
		while (cur < nums.size())
		{
			if (mp.count(nums[cur]) == 0)
				mp.insert(make_pair(nums[cur], 1));
			else
				mp[nums[cur]]++;
			cur++;
		}
		if (mp.size() < 2)
			return 0;
		for (map<int, int>::iterator it = mp.begin(), nx = mp.begin(); it != mp.end(); it++)
		{
			if (it == nx)
				continue;
			if (it->first == nx->first + 1)
				ans = max(ans,it->second+nx->second);
			nx = it;
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> a{ 1, 3, 2, 2, 5, 2, 3, 7 };
	Solution s;
	s.findLHS(a);
	return 0;
}

