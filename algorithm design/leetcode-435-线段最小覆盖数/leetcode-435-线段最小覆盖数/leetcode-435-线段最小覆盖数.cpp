// leetcode-435-线段最小覆盖数.cpp : 定义控制台应用程序的入口点。
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
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool com(Interval& a, Interval& b)
{
	if (a.start == b.start)
		return a.end < b.end;
	return a.start < b.start;
}
class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return 0;
		sort(intervals.begin(),intervals.end(),com);
		int max_right = intervals[0].end;
		int max_left = intervals[0].start;
		int cnt = 0;
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i].start >= max_right)
			{
				max_right = intervals[i].end;
				max_left = max(max_left,intervals[i].start);
				continue;
			}
			else if ((intervals[i].end >= max_right) && (intervals[i].start <= max_right))
				cnt++;
			else if (intervals[i].end <= max_right)
			{
				max_right = intervals[i].end;
				max_left = max(max_left,intervals[i].start);
				cnt++;
			}
			else
				max_right = intervals[i].end;
		}
		return cnt;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

