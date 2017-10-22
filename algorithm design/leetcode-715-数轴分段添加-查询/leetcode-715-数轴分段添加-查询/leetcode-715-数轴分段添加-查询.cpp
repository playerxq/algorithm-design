// leetcode-715-数轴分段添加-查询.cpp : Defines the entry point for the console application.
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
class RangeModule {
public:
	vector<pair<int, int>> invals;
	RangeModule() {

	}

	void addRange(int left, int right) {
		int n = invals.size();
		vector<pair<int, int>> tmp;//重构一个tmp代替invals
		for (int i = 0; i <= n; i++)
		{
			if (i == n || invals[i].first > right)
			{
				tmp.push_back({ left, right });
				while (i < n) tmp.push_back(invals[i++]);//将新的intervals加入到invals头部
			}
			else if (invals[i].second < left)
				tmp.push_back(invals[i]);
			else
			{
				left = min(left, invals[i].first);
				right = max(right, invals[i].second);
			}
		}
		swap(invals, tmp);
	}

	bool queryRange(int left, int right) {
		int n = invals.size(), l = 0, r = n - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (invals[m].first >= right)
				r = m - 1;
			else if (invals[m].second <= left)
				l = m + 1;
			else
				return invals[m].first <= left&&invals[m].second >= right;
		}
		return false;
	}

	void removeRange(int left, int right) {
		int n = invals.size();
		vector<pair<int, int>> tmp;//重构invals
		for (int i = 0; i < n; i++)
		{
			if (invals[i].second <= left || invals[i].first >= right)
				tmp.push_back(invals[i]);
			else
			{
				if (invals[i].first < left)
					tmp.push_back({ invals[i].first, left });
				if (invals[i].second > right)
					tmp.push_back({ right, invals[i].second });
			}
		}
		swap(tmp,invals);
	}
};

int main()
{
    return 0;
}

