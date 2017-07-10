// leetcode-640-µ» Ωº∆À„.cpp : Defines the entry point for the console application.
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
	string solveEquation(string equation) {
		int sign = 1;
		int i = 0;
		int tot = 0;
		int coe = 0;
		int n = equation.size();
		for (int j = 0; j<equation.size(); j++)
		{
			if (equation[j] == '+' || equation[j] == '-')
			{
				if (j>i)
				{
					tot += sign*stoi(equation.substr(i, j - i));
					i = j;
				}
			}
			else if (equation[j] == 'x')
			{
				if (i == j || equation[j - 1] == '+')
				{
					coe += sign;
				}
				else if (equation[j - 1] == '-')
					coe -= sign;
				else
					coe += sign*stoi(equation.substr(i, j - i));
				i = j + 1;
			}
			else if (equation[j] == '=')
			{
				if (j>i)
					tot += sign*stoi(equation.substr(i, j - i));
				sign = -1;
				i = j + 1;
			}
		}
		if (i<n)
			tot += sign*stoi(equation.substr(i));
		if (coe == 0 && tot == 0) return "Infinite solutions";
		if (coe == 0 && tot) return "No solution";
		int ans = -tot / coe;
		return "x=" + to_string(ans);
	}
};
int main()
{
    return 0;
}

