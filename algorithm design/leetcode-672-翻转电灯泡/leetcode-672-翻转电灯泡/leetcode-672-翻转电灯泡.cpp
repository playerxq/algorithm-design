// leetcode-672-·­×ªµçµÆÅÝ.cpp : Defines the entry point for the console application.
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
	int flipLights(int n, int m) {
		if (m == 0 || n == 0)
			return 1;
		if (n == 1 && m == 1)
			return 2;
		if (n == 1 && m == 2)
			return 2;
		if (n == 1 && m == 3)
			return 2;
		if (n == 2 && m == 1)
			return 3;
		if (n == 2 && m == 2)
			return 4;
		if (n == 2 && m == 3)
			return 4;
		if (n == 3 && m == 1)
			return 4;
		if (n == 3 && m == 2)
			return 7;
		if (n >= 3 && m >= 3)
			return 8;
		if (n >= 3)
			return flipLights(3,m);
		if (m >= 3)
			return flipLights(n,3);
	}
};
int main()
{
    return 0;
}

