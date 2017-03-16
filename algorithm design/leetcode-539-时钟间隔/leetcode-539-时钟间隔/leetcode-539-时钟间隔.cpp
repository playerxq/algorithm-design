// leetcode-539-时钟间隔.cpp : 定义控制台应用程序的入口点。
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
	int com(string s1, string s2)
	{
		int h1 = stoi(s1.substr(0,2));
		int m1 = stoi(s1.substr(3,2));
		int h2 = stoi(s2.substr(0, 2));
		int m2 = stoi(s2.substr(3, 2));
		return (h2 - h1) * 60 + (m2-m1);
	}
	int findMinDifference(vector<string>& timePoints) {
		int n = timePoints.size();
		if (!n)
			return 0;
		sort(timePoints.begin(),timePoints.end());
		int res = 1440;
		for (int i = 0; i < n; i++)
		{
			int dif = abs(com(timePoints[(i-1+n)%n],timePoints[i]));
			dif = min(dif,1440-dif);
			res = min(res,dif);
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> ve;
	ve = {"23:59","00:00"};
	Solution s;
	s.findMinDifference(ve);
	return 0;
}

