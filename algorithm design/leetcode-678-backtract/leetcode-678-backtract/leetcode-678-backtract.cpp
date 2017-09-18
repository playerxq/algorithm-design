// leetcode-678-backtract.cpp : Defines the entry point for the console application.
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
	bool helper(string s, int start, int cnt)
	{
		if (cnt < 0)
			return false;
		for (int i = start; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				cnt += 1;
			}
			else if (s[i] == ')')
			{
				if (cnt <= 0)
					return false;
				cnt--;
			}
			else
			{
				return helper(s, i + 1, cnt) || helper(s, i + 1, cnt + 1) || helper(s, i + 1, cnt - 1);
			}
		}
		return cnt == 0;
	}
	bool checkValidString(string s) {
		return helper(s,0,0);
	}
};

int main()
{
    return 0;
}

