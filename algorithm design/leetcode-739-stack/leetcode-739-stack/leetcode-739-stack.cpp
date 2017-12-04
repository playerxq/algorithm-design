// leetcode-739-stack.cpp : Defines the entry point for the console application.
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
	vector<int> dailyTemperatures(vector<int>& temp) {
		int n = temp.size();
		vector<int> res(n, 0);
		stack<pair<int, int>> st;
		for (int i = 0; i < n - 1; i++)
		{
			if (temp[i] < temp[i + 1])
			{
				res[i] = 1;
				while (!st.empty() && st.top().first < temp[i + 1])
				{
					res[st.top().second] = i + 1 - st.top().second;
					st.pop();
				}
			}
			else
			{
				st.push(make_pair(temp[i],i));
			}
		}
		return res;
	}
};

int main()
{
    return 0;
}

