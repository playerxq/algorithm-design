// leetcode-335-地图穿插.cpp : 定义控制台应用程序的入口点。
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
	bool isSelfCrossing(vector<int>& x) {
		x.insert(x.begin(),4,0);
		int i = 4;
		for (; i < x.size(); i++)
		{
			if (x[i]>x[i - 2])
				continue;
			else
				break;
		}
		if (i == x.size())
			return false;
		if (i == x.size() - 1)
			return false;
		int t = x[i-2] - x[i];
		if (t <= x[i - 4] &&x[i + 1] + x[i - 3] >= x[i - 1])
			return true;
		i++;
		for (; i < x.size(); i++)
		{
			if (x[i] < x[i - 2])
				continue;
			else
				break;
		}
		if (i == x.size())
			return false;
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(1);
	ve.push_back(1);
	ve.push_back(2);
	ve.push_back(1);
	ve.push_back(1);
	Solution s;
	s.isSelfCrossing(ve);
	return 0;
}

