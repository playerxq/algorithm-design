// leetcode-757-greedy.cpp : Defines the entry point for the console application.
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
	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b) {return a[1] < b[1]; });
		vector<int> ve;
		for (auto e : intervals)
		{
			int n = ve.size();
			if (n == 0 || e[0] > ve[n - 1])
			{
				ve.push_back(e[1] - 1);
				ve.push_back(e[1]);
			}
			else
			{
				int l = 0;
				int r = n - 1;
				while (l < r)
				{
					int mid = l + ((r - l) / 2);
					if (ve[mid] < e[0])
						l = mid + 1;
					else
						r = mid;
				}
				if (n - l < 2)
				{
					ve.push_back(e[1]);
					int k = ve.size() - 1;
					while (k&&ve[k - 1] == ve[k])
					{
						ve[k - 1]--;
						k--;
					}
				}
			}
		}
		return ve.size();
	}
};

int main()
{
    return 0;
}

