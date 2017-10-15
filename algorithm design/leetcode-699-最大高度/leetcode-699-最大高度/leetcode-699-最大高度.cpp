// leetcode-699-最大高度.cpp : Defines the entry point for the console application.
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
	class interval
	{
	public:
		int start, end, height;
		interval(int s, int e, int h) : start(s), end(e), height(h) {}
	};
	int get_height(vector<interval>& inters, interval& vv)
	{
		int preMaxHeight = 0;
		for (auto& i : inters)
		{
			if (i.end < vv.start) continue;
			if (i.start > vv.end) continue;
			preMaxHeight = max(preMaxHeight, i.height);
		}
		vv.height += preMaxHeight;
		inters.push_back(vv);
		return vv.height;
	}
	vector<int> fallingSquares(vector<pair<int, int>>& positions) {
		vector<interval> inters;
		vector<int> res;
		int h = 0;
		for (auto& p : positions)
		{
			interval vv(p.first,p.first+p.second-1,p.second);
			h = max(h,get_height(inters,vv));
			res.push_back(h);
		}
		return res;
	}
};
int main()
{
    return 0;
}

