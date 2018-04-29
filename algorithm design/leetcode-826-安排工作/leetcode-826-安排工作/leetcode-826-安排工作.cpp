// leetcode-826-°²ÅÅ¹¤×÷.cpp : Defines the entry point for the console application.
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
	int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
		map<int, int> mp;
		for (int i = 0; i < d.size(); i++)
		{
			if (mp.count(d[i]))
				mp[d[i]] = max(mp[d[i]], p[i]);
			else
				mp[d[i]] = p[i];
		}
		for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it == mp.begin())
				continue;
			it->second = max(it->second,prev(it)->second);
		}
		int res = 0;
		for (int i = 0; i < w.size(); i++)
		{
			res += prev(mp.upper_bound(w[i])) == mp.end() ? 0 : prev(mp.upper_bound(w[i]))->second;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> d = { 5, 50, 92, 21, 24, 70, 17, 63, 30, 53 };
	vector<int> p = { 68, 100, 3, 99, 56, 43, 26, 93, 55, 25 };
	vector<int> w = { 96, 3, 55, 30, 11, 58, 68, 36, 26, 1 };
	s.maxProfitAssignment(d,p,w);
    return 0;
}

