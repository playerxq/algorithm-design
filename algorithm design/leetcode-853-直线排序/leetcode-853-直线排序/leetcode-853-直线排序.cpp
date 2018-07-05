// leetcode-853-÷±œﬂ≈≈–Ú.cpp : Defines the entry point for the console application.
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
typedef pair<double, double> pp;
class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int n = position.size();
		if (!n)
			return 0;
		vector<pair<double, double>> v;
		for (int i = 0; i<n; i++)
		{
			double pos = position[i];
			double sp = speed[i];
			v.push_back({ pos,sp });
		}
		sort(v.begin(), v.end(), [&](const pp& a, const pp& b) {return a.first < b.first; });
		double tim = (target - v[n - 1].first) / v[n - 1].second;
		int cnt = 1;
		for (int i = n - 2; i >= 0; i--)
		{
			double dis = target - v[i].first;
			double t = dis / v[i].second;
			if (t > tim)
			{
				cnt++;
				tim = t;
			}
		}
		return cnt;
	}
};

int main()
{
    return 0;
}

