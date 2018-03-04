// leetcode-793-½×³ËÎ²Êý0.cpp : Defines the entry point for the console application.
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
	long zeros(long n) {
		if (n == 0) return 0;
		long count = 0;
		for (long i = 5; n / i >= 1; i *= 5) {
			count += n / i;
		}
		return count;
	}
	long bSearch(long t, bool upper) {
		long l = 0, r = 4294967296l, res = -1;
		while (l <= r) {
			long m = (l + r) >> 1;
			long v = zeros(m);
			if (v > t) {
				r = m - 1;
			}
			else if (v < t) {
				l = m + 1;
			}
			else {
				res = m;
				if (upper) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}
		return res;
	}
	int preimageSizeFZF(int k) {
		long l = bSearch(k, false);
		long r = bSearch(k, true);
		if (l != -1 && r != -1) {
			return (int)(r - l + 1);
		}
		else {
			return 0;
		}
	}
};
int main()
{
    return 0;
}

