// leetcode-452-线段不重复变体.cpp : 定义控制台应用程序的入口点。
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
bool com(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.size() == 0)
			return 0;
		sort(points.begin(),points.end());
		int max_right = points[0].second;
		int max_left = points[0].first;
		int cnt = 0;
		for (int i = 1; i < points.size(); i++)
		{
			if (points[i].first > max_right)
			{
				max_right = points[i].second;
				max_left = max(max_left, points[i].first);
				continue;
			}
			else if ((points[i].second >= max_right) && (points[i].first <= max_right))
				cnt++;
			else if (points[i].second <= max_right)
			{
				max_right = points[i].second;
				max_left = max(points[i].first, max_left);
				cnt++;
			}
			else
				max_right = points[i].second;
		}
		cnt = points.size() - cnt;
		return cnt;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<pair<int, int>> ve;
	ve.push_back(make_pair(1,2));
	ve.push_back(make_pair(2, 3));
	ve.push_back(make_pair(3, 4));
	ve.push_back(make_pair(4, 5));
	Solution s;
	s.findMinArrowShots(ve);
	return 0;
}

