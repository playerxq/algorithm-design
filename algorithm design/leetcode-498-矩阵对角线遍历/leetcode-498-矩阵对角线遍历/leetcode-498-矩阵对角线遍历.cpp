// leetcode-498-矩阵对角线遍历.cpp : 定义控制台应用程序的入口点。
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
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int m = matrix.size();
		if (!m)
			return res;
		int n = matrix[0].size();
		int cnt = 0;
		int back = 0;
		int i = 0;
		int j = 0;
		while (cnt < m*n)
		{
			if (back == 0)
			{
				res.push_back(matrix[i][j]);
				i--;
				j++;
				if (i < 0 && j <= n - 1)
				{
					i++;
					back = 1;
				}
				else if (j>n - 1)
				{
					i += 2;
					j = n - 1;
					back = 1;
				}
			}
			else
			{
				res.push_back(matrix[i][j]);
				i++;
				j--;
				if (i > m - 1)
				{
					i = m - 1;
					j += 2;
					back = 0;
				}
				else if (j < 0 && i <= m - 1)
				{
					j = 0;
					back = 0;
				}
			}
			cnt++;
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

