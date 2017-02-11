// leetcode-343-整数分解.cpp : 定义控制台应用程序的入口点。
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
	int integerBreak(int n) {
		vector<int> ve(n+1,0);
		if (n == 1||n==2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		if (n == 5)
			return 6;
		if (n == 6)
			return 9;
		ve[0] = 0;
		ve[1] = 1;
		ve[2] = 1;
		ve[3] = 2;
		ve[4] = 4;
		ve[5] = 6;
		ve[6] = 9;
		for (int i = 7; i <= n; i++)
		{
			ve[i] = ve[i - 3] * 3;
		}
		return ve[n];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.integerBreak(10);
	return 0;
}

