// leetcode-668-二分查找2维乘法表.cpp : Defines the entry point for the console application.
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
	int findKthNumber(int m, int n, int k) {
		int le = 1;
		int ri = m*n;
		int cnt = 0;
		while (le < ri)
		{
			int mid = le + (ri - le) / 2;
			cnt = 0;
			for (int i = 1; i <= m; i++)
			{
				cnt += (mid / i < n) ? mid / i : n;//找到每一行中比mid小的数的个数
			}
			if (cnt < k)
				le = mid + 1;
			else
				ri = mid;
		}
		return le;
	}
};

int main()
{
    return 0;
}

