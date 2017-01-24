// leetcode-319-整数分解.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		int ans = 1;
		if (n == 0)
			return 0;
		return sqrt(n);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.bulbSwitch(5);
	return 0;
}

