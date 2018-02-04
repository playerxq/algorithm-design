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
		if (N == 1) return 0;
		if (K % 2 == 0) return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
		else return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
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

