// leetcode-483-整数的基.cpp : 定义控制台应用程序的入口点。
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
	unsigned long long helper(unsigned long long num, int d)
	{
		double nn = (double)num;
		unsigned long long le = 1;
		unsigned long long ri = (unsigned long long)(pow(nn, (1.0 / d)) + 1);
		while (le <= ri)
		{
			unsigned long long mid = le + (ri - le) / 2;
			unsigned long long cur = mid;
			unsigned long long sum = 1;
			for (int i = 0; i < d; i++)
			{
				sum += cur;
				cur *= mid;
			}
			if (sum == num)
				return mid;
			else if (sum < num)
				le = mid + 1;
			else
				ri = mid - 1;
		}
		return 0;
	}
	string smallestGoodBase(string n) {
		unsigned long long num = (unsigned long long)stoll(n);
		unsigned long long x = 1;
		for (int i = 62; i >= 1; i--)
		{
			if ((x << i) < num)
			{
				unsigned long long cur = helper(num, i);
				if (cur != 0)
					return to_string(cur);
			}
		}
		return to_string(num - 1);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

