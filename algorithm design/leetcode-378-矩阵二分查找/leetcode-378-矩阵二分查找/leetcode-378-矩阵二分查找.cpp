// leetcode-378-矩阵二分查找.cpp : 定义控制台应用程序的入口点。
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
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		if (!n)
			return 0;
		int le = matrix[0][0];
		int ri = matrix[n-1][n-1];
		int mid = 0;
		while (le < ri)
		{
			mid = le + (ri - le) / 2;
			int pos = 0;
			for (int i = 0; i < n; i++)
			{
				int nnn = upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
				pos += nnn;
			}
			if (pos < k)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
		}
		return le;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

