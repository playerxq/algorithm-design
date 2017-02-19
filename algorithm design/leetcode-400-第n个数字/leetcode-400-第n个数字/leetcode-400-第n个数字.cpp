// leetcode-400-第n个数字.cpp : 定义控制台应用程序的入口点。
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
	int findNthDigit(int n) {
		if (n<10)
			return n;
		long long tmp = 9;
		long long sum = 9;
		int cnt = 1;
		long long pre = 0;
		while (sum <= n)
		{
			pre = sum;
			tmp = tmp * 10;
			cnt++;
			sum += (tmp*cnt);
		}
		n = n - pre;
		int a = n / cnt;
		int b = n%cnt;
		long long c = (int)pow((int)10, cnt - 1) + a - 1;
		if (b == 0)
			return c % 10;
		c++;
		return (c % ((int)pow((int)10, cnt - b + 1))) / ((int)pow((int)10, cnt - b));
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.findNthDigit(1000000000);
	return 0;
}

