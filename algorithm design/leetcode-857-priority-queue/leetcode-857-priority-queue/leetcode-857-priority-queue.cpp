// leetcode-857-priority-queue.cpp : Defines the entry point for the console application.
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
struct worker
{
	double wq;
	double q;
	worker(double wag, double qui) :wq(wag / qui), q(qui) {}
	
};
bool cmp (const worker& a, const worker& b)
{
	return a.wq < b.wq;
}
class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
		int n = quality.size();
		vector<worker> ve;
		for (int i = 0; i<n; ++i) {
			worker temp(wage[i], quality[i]);
			ve.push_back(temp);
		}
		sort(ve.begin(),ve.end(),cmp);
		priority_queue<double> Q;
		double sum = 0;
		for (int i = 0; i < K; i++)
		{
			sum += ve[i].q;
			Q.push(ve[i].q);
		}
		double ans = sum*ve[K - 1].wq;
		for (int i = K; i < n; i++)
		{
			Q.push(ve[i].q);
			sum += ve[i].q;
			sum -= Q.top();
			Q.pop();
			ans = min(ans,sum*ve[i].wq);
		}
		return ans;
	}
};
int main()
{
	Solution s;
	vector<int> quality = { 3,1,10,10,1 };
	vector<int> wage = { 4,8,2,2,7 };
	s.mincostToHireWorkers(quality,wage,3);
    return 0;
}

