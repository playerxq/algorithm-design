// leetcode-805-分割数组.cpp : Defines the entry point for the console application.
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
	//dfs 能否取出和为sum的数组 从p开始 n个数
	bool dfs(int p, int k, int sum, vector<int> &A) {
		if (k == 0)
			return sum == 0;
		if (sum > A[p] * k)
			return false;
		for (int i = p; i <= A.size() - k; i++) // 依次枚举第一个取出的数 n个数平均数sum/n 故取出的第一个A[i]<=sum/n
			if (sum >= A[i] && dfs(i + 1, k - 1, sum - A[i], A))
				return true;
		return false;
	}
	bool splitArraySameAverage(vector<int>& A) {
		int sum = 0, n = A.size();
		for (int i : A)
			sum += i;
		sort(A.begin(), A.end(), greater<int>());
		for (int i = 1; i <= n / 2; i++)
			if (i * sum % n == 0 && dfs(0, i, i * sum / n, A)) // pruning
				return true;
		return false;
	}
};
int main()
{
    return 0;
}

