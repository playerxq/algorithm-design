// leetcode-861-¾ØÕó·­×ª.cpp : Defines the entry point for the console application.
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
	int matrixScore(vector<vector<int>>& A) {
		int n = A.size();
		if (!n)
			return 0;
		int m = A[0].size();
		for (int i = 0; i < n; i++)
		{
			if (A[i][0] == 0)
			{
				for (int j = 0; j < m; j++)
				{
					A[i][j] ^= 1;
				}
			}
		}
		for (int i = 1; i < m; i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (A[j][i] == 1)
					cnt++;
			}
			if (2 * cnt < n)
			{
				for (int j = 0; j < n; j++)
					A[j][i] ^= 1;
			}
		}
		int res = 0;
		for (int i = 0; i < m; i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (A[j][i] == 1)
					cnt++;
			}
			res += cnt*(int)pow(2, m - 1 - i);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> ve = { {0,0,1,1},{1,0,1,0},{1,1,0,0} };
	s.matrixScore(ve);
    return 0;
}

