// leetcode-347-桶排序.cpp : 定义控制台应用程序的入口点。
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
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (int num : nums)
			++m[num];

		vector<vector<int>> buckets(nums.size() + 1);
		for (auto p : m)
			buckets[p.second].push_back(p.first);

		vector<int> ans;
		for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
			for (int num : buckets[i]) {
				ans.push_back(num);
				if (ans.size() == k)
					break;
			}
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

