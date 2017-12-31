// leetcode-755-Ä£ÄâË®µÎ.cpp : Defines the entry point for the console application.
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
	int helper(vector<int>& heights, int K, int h,int l, int r)
	{
		if (l&&K&&heights[K - 1] <= heights[K] && helper(heights, K - 1, h, 1, 0))
			return 1;
		if (r&&K < heights.size() - 1 && heights[K + 1] <= heights[K] && helper(heights, K + 1, h, 0, 1))
			return 1;
		if (heights[K] == h)
			return 0;
		heights[K]++;
		return 1;
	}
	vector<int> pourWater(vector<int>& heights, int V, int K) {
		if (V == 0)
			return heights;
		while (V--)
			helper(heights,K,heights[K]+1,1,1);
		return heights;
	}
};
int main()
{
    return 0;
}

