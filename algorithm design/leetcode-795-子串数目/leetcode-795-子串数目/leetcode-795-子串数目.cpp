// leetcode-795-×Ó´®ÊýÄ¿.cpp : Defines the entry point for the console application.
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
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int sum = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] > R)
				continue;
			int mx = INT_MIN;
			for (int j = i; j < A.size(); j++)
			{
				mx = max(mx,A[j]);
				if (mx > R)
					break;
				if (mx >= L)
					sum++;
			}
		}
		return sum;
	}
};

int main()
{
	Solution s;
	vector<int> ve = { 2, 9, 2, 5,6 };
	s.numSubarrayBoundedMax(ve,2,8);
    return 0;
}

