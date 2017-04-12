// leetcode-556-下一个排列.cpp : 定义控制台应用程序的入口点。
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
	int nextGreaterElement(int n) {
		string s = to_string(n);
		if (s.length() == 1) {
			return -1;
		}
		int i = s.length() - 2;
		for (i; i >= 0 && s[i] >= s[i + 1]; i--)
		{
		}
		if (i == -1)
			return -1;
		int j = s.length() - 1;
		for (; s[i] >= s[j]; j--){}
		swap(s[i],s[j]);
		reverse(s.begin()+i+1,s.end());
		long nx = stol(s);
		if (nx == n || nx > INT_MAX)
			return -1;
		return nx;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

