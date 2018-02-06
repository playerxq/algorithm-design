// leetcode-777-×Ö·û´®Æ¥Åä.cpp : Defines the entry point for the console application.
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
	bool canTransform(string start, string end) {
		int n = start.length();
		if (!n)
			return true;
		int i = 0;
		int j = 0;
		while (i < n&&j < n)
		{
			while (i < n&&start[i] == 'X')
				i++;
			while (j < n&&end[j] == 'X')
				j++;
			if (i == n&&j == n)
				break;
			if (i == n || j == n || start[i] != end[j])
				return false;
			if (start[i] == 'R'&&i > j)
				return false;
			if (start[i] == 'L'&&i < j)
				return false;
			i++;
			j++;
		}
		return true;
	}
};

int main()
{
	Solution s;
	s.canTransform("RXXLRXRXL", "XRLXXRRLX");
    return 0;
}

