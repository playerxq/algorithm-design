// leetcode-835-æÿ’Û∆Ω“∆∏≤∏«.cpp : Defines the entry point for the console application.
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
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<int> LA, LB;
		int N = A.size();
		unordered_map<int, int> count;
		for (int i = 0; i < N * N; ++i) if (A[i / N][i % N] == 1) LA.push_back(i / N * 100 + i % N);
		for (int i = 0; i < N * N; ++i) if (B[i / N][i % N] == 1) LB.push_back(i / N * 100 + i % N);
		for (int i : LA) for (int j : LB) count[i - j]++;
		int res = 0;
		for (auto it : count) res = max(res, it.second);
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> A = { {1, 1, 0},{0, 1, 0},{0, 1, 0} };
	vector<vector<int>> B = { { 0, 0, 0 },{ 0, 1, 1 },{ 0, 0, 1 } };
	s.largestOverlap(A,B);
    return 0;
}

