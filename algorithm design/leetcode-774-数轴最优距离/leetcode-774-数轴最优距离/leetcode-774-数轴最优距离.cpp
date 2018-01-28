// leetcode-774- ˝÷·◊Ó”≈æ‡¿Î.cpp : Defines the entry point for the console application.
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
class CustomClass {
public:
	CustomClass(int x) : numerator(x), denominator(1), val(x) {}
	bool operator<(const CustomClass &o) const {
		return val < o.val;
	}
	double numerator;
	double denominator;
	double val;
};


class Solution {
public:
	double minmaxGasDist(vector<int>& stations, int K) {
		double res = 0;
		double threshold = 0;
		priority_queue<CustomClass> gap;
		for (int i = 1; i < stations.size(); i++) {
			int diff = stations[i] - stations[i - 1];
			threshold += diff / (double(K + 1));
			gap.push(CustomClass(diff));
		}
		for (int i = 0; i < K;) {
			auto top = gap.top();
			gap.pop();
			while (i < K && (top.val >= gap.top().val || top.val > threshold)) {
				i++;
				top.denominator++;
				top.val = top.numerator / top.denominator;
			}
			gap.push(top);
		}
		return gap.top().val;
	}
};

int main()
{
	double tt = 0;
	Solution s;
	vector<int> ve = { 10, 19, 25, 27, 56, 63, 70, 87, 96, 97 };
	tt = s.minmaxGasDist(ve,3);
    return 0;
}

