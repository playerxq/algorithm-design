// leetcode-738-µ¥µ÷Êý.cpp : Defines the entry point for the console application.
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
	int monotoneIncreasingDigits(int N) {
		string s = to_string(N);
		int len = s.length();
		string res;
		for (int i = len - 1; i >= 1; i--)
		{
			if (s[i - 1] <= s[i])
			{
				res += s[i];
			}
			else
			{
				s[i - 1]--;
				res = string(len-i,'9');
			}
		}
		res += s[0];
		reverse(res.begin(),res.end());
		return stoi(res);
	}
};
int main()
{
    return 0;
}

