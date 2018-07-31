// leetcode-875-2∑÷≤È’“.cpp : Defines the entry point for the console application.
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
	int minEatingSpeed(vector<int>& piles, int H) {
		int le = 1;
		int ri = 0;
		for (int i = 0; i < piles.size(); i++)
		{
			if (ri < piles[i])
				ri = piles[i];
		}
		while (le <= ri)
		{
			int m = (le + ri) / 2;
			int sum = 0;
			for (int i = 0; i < piles.size(); i++)
			{
				sum += (piles[i] + m - 1) / m;
			}
			if (sum > H)
				le = m + 1;
			else
				ri = m-1;
		}
		return le;
	}
};
int main()
{
	Solution s;
	vector<int> ve = { 30,11,23,4,20 };
	s.minEatingSpeed(ve,6);
    return 0;
}

