// leetcode-832-·­×ª¾ØÕó.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int n = A.size();
		if (!n)
			return A;
		int m = A[0].size();
		vector<vector<int>> B(n,vector<int>(m,0));
		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				B[i][m - j - 1] = A[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				B[i][j] ^= 1;
		}
		return B;
	}
};

int main()
{
    return 0;
}

