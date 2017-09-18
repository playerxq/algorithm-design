// leetcode-679-24��.cpp : Defines the entry point for the console application.
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
	bool judgePoint24(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		do {
			if (valid(nums)) return true;
		} while (next_permutation(nums.begin(), nums.end()));
		return false;
	}
private:
	bool valid(vector<int>& nums) {
		double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
		if (valid(a + b, c, d) || valid(a - b, c, d) || valid(a*b, c, d) || valid(a / b, c, d)) return true;
		if (valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b*c, d) || valid(a, b / c, d)) return true;
		if (valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c*d) || valid(a, b, c / d)) return true;
		return false;
	}
	bool valid(double a, double b, double c) {
		if (valid(a + b, c) || valid(a - b, c) || valid(a*b, c) || b&&valid(a / b, c)) return true;
		if (valid(a, b + c) || valid(a, b - c) || valid(a, b*c) || c&&valid(a, b / c)) return true;
		return false;
	}
	bool valid(double a, double b) {
		if (abs(a + b - 24.0) < 0.0001 || abs(a - b - 24.0) < 0.0001 || abs(a*b - 24.0) < 0.0001 || b&&abs(a / b - 24.0) < 0.0001)
			return true;
		return false;
	}
};
int main()
{
    return 0;
}

