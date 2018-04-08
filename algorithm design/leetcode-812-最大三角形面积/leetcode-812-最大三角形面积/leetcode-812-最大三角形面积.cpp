// leetcode-812-最大三角形面积.cpp : Defines the entry point for the console application.
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
	double largestTriangleArea(vector<vector<int>>& points) {
		int n = points.size();
		if (!n)
			return 0;
		double mx = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					double A = points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1]);
					A = abs(A);
					A /= 2;
					if (A > mx)
						mx = A;
				}
			}
		}
		return mx;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> ve = { {0,0},{0,1},{1,0},{0,2},{2,0} };
	s.largestTriangleArea(ve);
    return 0;
}

