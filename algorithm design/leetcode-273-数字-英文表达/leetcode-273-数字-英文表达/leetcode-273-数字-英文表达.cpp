// leetcode-273-数字-英文表达.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	static const char * const below_10[];
	static const char * const below_100[];
	string int_string(int n)
	{
		if (n >= 1000000000)
		{
			return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
		}
		else if (n >= 1000000)
		{
			return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
		}
		else if (n >= 1000)
		{
			return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
		}
		else if (n >= 100)
		{
			return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
		}
		else if (n >= 20)
		{
			return string(" ") + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
		}
		else if (n >= 1)
		{
			return string(" ") + below_10[n - 1];
		}
		else
			return "";
	}
	string numberToWords(int num) {
		if (num == 0)
			return "Zero";
		else
			return int_string(num).substr(1);
	}
};
const char * const Solution::below_10[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
const char * const Solution::below_100[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

