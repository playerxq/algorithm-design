// leetcode-771-×Ö·û´®Æ¥Åä.cpp : Defines the entry point for the console application.
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
	int numJewelsInStones(string J, string S) {
		int n = S.length();
		if (!n)
			return 0;
		int  cnt = 0;
		int len = J.length();
		if (!len)
			return 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (S[i] == J[j])
				{
					cnt++;
					break;
				}
			}
		}
		return cnt;
	}
};
int main()
{
	Solution s;
	s.numJewelsInStones("aA", "aAAbbbb");
    return 0;
}

