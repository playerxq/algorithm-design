// leetcode-829-连续数字和.cpp : Defines the entry point for the console application.
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
	int consecutiveNumbersSum(int N) {
		int res = 0;
		int n = (int)sqrt(N);
		for (int i = n * 2; i >= 2; i--)
		{
			if ((2 * N + i - i*i) % (2 * i) == 0 && (2 * N + i - i*i) > 0)
			{
				res++;
			}
		}
		return res+1;
	}
};
int main()
{
	Solution s;
	s.consecutiveNumbersSum(5);
    return 0;
}

