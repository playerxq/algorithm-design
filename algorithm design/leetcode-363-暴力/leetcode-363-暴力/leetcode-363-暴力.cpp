// leetcode-363-暴力.cpp : 定义控制台应用程序的入口点。
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
	int maxsum(vector<int>& ve, int k)
	{
		int maxx = INT_MIN;
		int sum = 0;
		for (int i = 0; i < ve.size(); i++)
		{
			sum += ve[i];
			maxx = max(maxx,sum);
			if (maxx == k)
				return maxx;
			if (sum < 0)
				sum = 0;
		}
		if (maxx <= k)
			return maxx;
		maxx = INT_MIN;
		sum = 0;
		for (int i = 0; i < ve.size(); i++)
		{
			sum = 0;
			for (int j = i; j < ve.size(); j++)
			{
				sum += ve[j];
				if (sum == k)
					return sum;
				if (sum < k&&sum > maxx)
					maxx = sum;
			}
		}
		return maxx;
	}
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.size() == 0)
			return 0;
		int maxx = INT_MIN;
		for (int r1 = 0; r1 < matrix.size(); r1++)
		{
			vector<int> arr(matrix[r1].size(),0);
			for (int r2 = r1; r2 < matrix.size(); r2++)
			{
				for (int c = 0; c < matrix[r1].size(); c++)
					arr[c] += matrix[r2][c];
				int ms = maxsum(arr,k);
				if (ms == k)
					return ms;
				if (ms<k&&ms>maxx)
					maxx = ms;
			}
		}
		return maxx;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

