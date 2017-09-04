// leetcode-670-最大整数翻转.cpp : Defines the entry point for the console application.
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
	string maxswap(string& s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			int po = i;
			for (int j = s.size() - 1; j > i; j--)
			{
				if (s[j] > s[po])
					po = j;
			}
			if (po != i)
			{
				swap(s[po],s[i]);
				break;
			}
		}
		return s;
	}
	int maximumSwap(int num) {
		string s = to_string(num);
		int ans = stoi(maxswap(s));
		return ans;
	}
};
int main()
{
    return 0;
}

