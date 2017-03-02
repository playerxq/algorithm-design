// leetcode-440-第k个最小数.cpp : 定义控制台应用程序的入口点。
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
	int helper(int n, long n1, long n2)
	{
		int step = 0;
		while (n1 <= n)
		{
			step += (min((long)n + 1, n2) - n1);
			n1 *= 10;
			n2 *= 10;
		}
		return step;
	}
	int findKthNumber(int n, int k) {
		if (k == 1||n==1)
			return 1;
		if (n < 10)
			return k;
		k--;
		int cur = 1;
		int step = 0;
		while (k)
		{
			int t = helper(n,cur,cur+1);
			if (t <= k)
			{
				k -= t;
				cur++;
			}
			else
			{
				k--;
				cur *= 10;
			}
		}
		return cur;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

