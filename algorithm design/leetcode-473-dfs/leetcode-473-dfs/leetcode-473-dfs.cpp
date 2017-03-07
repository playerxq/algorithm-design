// leetcode-473-dfs.cpp : 定义控制台应用程序的入口点。
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
	int sum;
	bool dfs(vector<int>& edges, vector<int>& nums, int st)
	{
		if (st == nums.size())
		{
			if (edges[0] == edges[1] && edges[1] == edges[2] && edges[2] == edges[3] && edges[3] == edges[0])
				return true;
			return false;
		}
		for (int i = 0; i < 4; i++)
		{
			if (edges[i] + nums[st]>sum / 4)
				continue;
			int j = i;
			while (--j >= 0)
			{
				if (edges[j] == edges[i])
					break;
			}
			if (j != -1)
				continue;
			edges[i] += nums[st];
			if (dfs(edges, nums, st + 1))
				return true;
			edges[i] -= nums[st];
		}
		return false;
	}
	bool makesquare(vector<int>& nums) {
		if (nums.empty())
			return false;
		int n = nums.size();
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += nums[i];
		}
		if (sum % 4)
			return false;
		auto mycom = [](const int& l, const int& r){return l > r; };
		sort(nums.begin(),nums.end(),mycom);
		vector<int> edges(4,0);
		return dfs(edges,nums,0);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

