// leetcode-658-数组中离x最近的k个值.cpp : Defines the entry point for the console application.
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
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		queue<int> q;
		for (int i = 0; i < arr.size(); i++)
		{
			if (q.size() < k)
				q.push(arr[i]);
			else
			{
				if (abs(arr[i] - x) >= abs(q.front() - x) && arr[i] != q.front())
					break;
				q.pop();
				q.push(arr[i]);
			}
		}
		vector<int> res;
		while (!q.empty())
		{
			res.push_back(q.front());
			q.pop();
		}
		return res;
	}
};

int main()
{
    return 0;
}

