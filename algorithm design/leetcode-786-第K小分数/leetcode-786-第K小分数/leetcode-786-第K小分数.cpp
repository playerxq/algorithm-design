// leetcode-786-第K小分数.cpp : Defines the entry point for the console application.
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
	vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
		priority_queue<pair<double, pair<int, int>>> Q;
		for (int i = 0; i < A.size(); i++)
		{
			Q.push(make_pair(-1.0*A[i] / A.back(), make_pair(i, A.size() - 1)));
		}
		while (--K)
		{
			auto cur = Q.top().second;
			Q.pop();
			cur.second--;
			int minx = min(cur.first, cur.second);
			int maxx = max(cur.first, cur.second);
			cur.first = minx;
			cur.second = maxx;
			Q.push(make_pair(-1.0*A[cur.first] / A[cur.second], make_pair(cur.first, cur.second)));
		}
		return{ A[Q.top().second.first],A[Q.top().second.second] };
	}
};
int main()
{
    return 0;
}

