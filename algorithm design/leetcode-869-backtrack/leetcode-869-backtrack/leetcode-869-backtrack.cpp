// leetcode-869-backtrack.cpp : Defines the entry point for the console application.
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
	bool backtrack(string& S, int k)
	{
		if (k == S.size())
		{
			int n = stoi(S);
			return (!(n&(n - 1)));
		}

		for (int i = k; i < S.size(); ++i)
		{
			swap(S[i], S[k]);
			if (S[0] != '0' && backtrack(S, k + 1))   return true;
			swap(S[i], S[k]);
		}
		return false;
	}
	bool reorderedPowerOf2(int N)
	{
		string s = to_string(N);
		return backtrack(s, 0);
	}
};
int main()
{
    return 0;
}

