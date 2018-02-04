// leetcode-779-±àÂë.cpp : Defines the entry point for the console application.
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
	int kthGrammar(int N, int K) {
		if (N <= 1) return 0;
		int allCount = pow(2, N - 1);
		int c = 0;
		while (allCount>2) {
			if (K>allCount / 2) {
				K -= allCount / 2;
				c++;
			}
			allCount = allCount >> 1;
		}
		if (c % 2 == 0) {
			return K == 1 ? 0 : 1;
		}
		else return K == 1 ? 1 : 0;
	}
};
int main()
{
	Solution s;
	int res = s.kthGrammar(4, 1);
	int t;
	t = res;
    return 0;
}

