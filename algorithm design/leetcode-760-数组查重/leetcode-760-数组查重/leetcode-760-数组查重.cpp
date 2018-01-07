// leetcode-760-数组查重.cpp : Defines the entry point for the console application.
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
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		int n = A.size();
		vector<int> res(n,0);
		if (!n)
			return res;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (A[i] == B[j])
					res[i] = j;
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<int> A = {12, 28, 46, 32, 50};
	vector<int> B = { 50, 12, 32, 46, 28 };
	s.anagramMappings(A,B);
    return 0;
}

