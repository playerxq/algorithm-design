// leetcode-660-10进制转9进制.cpp : Defines the entry point for the console application.
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
	int newInteger(int n) {
		int ans = 0;
		int b = 1;
		while (n)
		{
			ans += (n % 9)*b;
			n /= 9;
			b *= 10;
		}
		return ans;
	}
};

int main()
{
    return 0;
}

