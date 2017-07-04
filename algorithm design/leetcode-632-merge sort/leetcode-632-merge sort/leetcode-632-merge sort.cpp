// leetcode-632-merge sort.cpp : Defines the entry point for the console application.
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
	vector<int> smallestRange(vector<vector<int>>& nums) {
		typedef vector<int>::iterator vi;
		struct comp {
			bool operator()(pair<vi, vi> p1, pair<vi, vi> p2) {
				return *p1.first > *p2.first;
			}
		};
		int lo = INT_MAX, hi = INT_MIN;
		priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
		for (auto &row : nums) {
			lo = min(lo, row[0]);
			hi = max(hi, row[0]);
			pq.push({ row.begin(), row.end() });
		}
		vector<int> ans = { lo, hi };
		while (true) {
			auto p = pq.top();//vector<int>
			pq.pop();
			++p.first;
			if (p.first == p.second)
				break;
			pq.push(p);
			lo = *pq.top().first;
			hi = max(hi, *p.first);
			if (hi - lo < ans[1] - ans[0])
				ans = { lo, hi };
		}
		return ans;
	}
};
int main()
{
	vector<vector<int>> a = { {4, 10, 15, 24, 26},{0, 9, 12, 20},{5, 18, 22, 30} };
	Solution s;
	s.smallestRange(a);
    return 0;
}

