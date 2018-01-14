// leetcode-765-Êý×é½»»».cpp : Defines the entry point for the console application.
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
	int minSwapsCouples(vector<int>& row) {
		int n = row.size();
		for (int i = 0; i < n; i++)
			row[i] = row[i] / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (row[i] != row[i + 1])
			{
				for (int j = i + 2; j < n; j++)
				{
					if (row[j] == row[i])
					{
						swap(row[i + 1], row[j]);
						cnt++;
					}
				}
			}
		}
		return cnt;
	}
};


int main()
{
    return 0;
}

