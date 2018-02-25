// leetcode-788-Ðý×ªÊý×Ö.cpp : Defines the entry point for the console application.
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
	bool is_valid(int n)
	{
		int s = 0;
		int tmp = n;
		string temp = to_string(n);
		int len = temp.length();
		int cnt = len - 1;
		while (n)
		{
			s = n % 10;
			n /= 10;
			if (s == 0 || s == 1 || s == 8)
				temp[cnt--] = s + '0';
			else if (s == 2)
				temp[cnt--] = '5';
			else if (s == 5)
				temp[cnt--] = '2';
			else if (s == 6)
				temp[cnt--] = '9';
			else if (s == 9)
				temp[cnt--] = '6';
			else
				return false;
		}
		int ss = stoi(temp);
		if (ss == tmp)
			return false;
		return true;
	}
	int rotatedDigits(int N) {
		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			if (is_valid(i))
				sum++;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	s.rotatedDigits(10);
    return 0;
}

