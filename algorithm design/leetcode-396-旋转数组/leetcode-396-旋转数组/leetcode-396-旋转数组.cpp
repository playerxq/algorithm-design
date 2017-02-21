// leetcode-396-旋转数组.cpp : 定义控制台应用程序的入口点。
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
	int maxRotateFunction(vector<int>& A) {
		vector<int> sum(A.size()+1,0);
		int n = A.size();
		if (n == 0)
			return 0;
		for (int i = 0; i < A.size(); i++)
			sum[0] += A[i];
		for (int i = 1; i < A.size(); i++)
			sum[i] = sum[0] - A[n-i];
		vector<int> res(n+1,0);
		for (int i = 0; i < n; i++)
			res[0] += (i*A[i]);
		for (int i = 1; i < n; i++)
			res[i] = res[i - 1] - (n - 1)*A[n - i] + sum[i];
		int maxx = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			if (maxx < res[i])
				maxx = res[i];
		}
		return maxx;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(4);
	ve.push_back(3);
	ve.push_back(2);
	ve.push_back(6);
	Solution s;
	s.maxRotateFunction(ve);
	return 0;
}

