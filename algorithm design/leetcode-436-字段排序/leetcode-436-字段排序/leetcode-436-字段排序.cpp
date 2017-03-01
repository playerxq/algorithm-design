// leetcode-436-�ֶ�����.cpp : �������̨Ӧ�ó������ڵ㡣
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

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals) {
		map<int, int> hash;
		vector<int> res;
		for (int i = 0; i < intervals.size(); i++)
		{
			hash[intervals[i].start] = i;
		}
		for (auto itr : intervals)
		{
			auto id = hash.lower_bound(itr.end);
			if (id == hash.end())
				res.push_back(-1);
			else
				res.push_back(id->second);
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

