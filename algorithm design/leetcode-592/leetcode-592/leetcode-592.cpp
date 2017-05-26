// leetcode-592.cpp : 定义控制台应用程序的入口点。
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
	int gcd(int a, int b)
	{
		return (b == 0) ? a : gcd(b, a%b);
	}
	string fractionAddition(string expression) {
		int a = 0;
		int b = 1;
		int c = 0;
		int d = 1;
		int cur = 0;
		int p1 = 0;
		int p2 = 0;
		if (expression[0] != '-')
			expression = '+' + expression;
		while (cur < expression.size())
		{
			for (p1 = cur + 1; p1 < expression.size() && expression[p1] != '/'; p1++);
			for (p2 = p1 + 1; p2 < expression.size() && expression[p2] != '-'&&expression[p2] != '+'; p2++);
			c = stoi(expression.substr(cur + 1, p1 - 1 - cur));
			d = stoi(expression.substr(p1 + 1, p2 - 1 - p1));
			int g = gcd(b, d);
			a = (a*d) / g + (expression[cur] == '-' ? -1 : 1)*(b*c) / g;
			b = (b*d) / g;
			cur = p2;
		}
		int g = gcd(abs(a), b);
		return to_string(a / g) + '/' + to_string(b / g);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

