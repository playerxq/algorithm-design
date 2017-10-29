// leetcode-719-Õ∞≈≈–Ú.cpp : Defines the entry point for the console application.
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
	int smallestDistancePair(vector<int>& nums, int k) {
		int n = nums.size(), N = 1000000;
		vector<int> cnt(N, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				cnt[abs(nums[i] - nums[j])]++;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if (cnt[i] >= k) return i;
			k -= cnt[i];
		}
		return 0;
	}
};

int main()
{
    return 0;
}

