// leetcode-625-分解整数.cpp : 定义控制台应用程序的入口点。
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
	int smallestFactorization(int a) {
		if (a<10)
			return a;
		int res[40];
		int j = 0;
		for (int i = 9; i>1; i--)
		{
			while (a%i == 0)
			{
				a /= i;
				res[j++] = i;
			}
		}
		if (a>10)
			return 0;
		unsigned long long ans = 0;
		for (int k = j - 1; k >= 0; k--)
		{
			ans = ans * 10 + res[k];
			if (ans > 2147483647) return 0;
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

