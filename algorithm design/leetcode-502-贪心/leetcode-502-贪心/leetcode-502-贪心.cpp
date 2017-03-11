// leetcode-502-贪心.cpp : 定义控制台应用程序的入口点。
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
struct comp1
{
	bool operator()(const pair<int, int> a, const pair<int, int> b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}
};
struct comp2
{
	bool operator()(const pair<int, int> a, const pair<int, int> b)
	{
		if (a.second == b.second)
			return a.first > b.first;
		return a.second < b.second;
	}
};
class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		priority_queue < pair<int, int>, vector<pair<int, int>>, comp1> qCap;
		priority_queue < pair<int, int>, vector<pair<int, int>>, comp2> qPro;
		for (int i = 0; i < Profits.size(); i++)
		{
			qCap.push(make_pair(Capital[i],Profits[i]));
		}
		for (int i = 0; i < k; i++)
		{
			while (!qCap.empty() && qCap.top().first <= W)
			{
				qPro.push(qCap.top());
				qCap.pop();
			}
			if (qPro.empty())
				break;
			W += qPro.top().second;
			qPro.pop();
		}
		return W;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

