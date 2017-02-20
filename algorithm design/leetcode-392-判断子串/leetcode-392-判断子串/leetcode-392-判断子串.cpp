// leetcode-392-判断子串.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int sLen = s.length(), sIdx = 0, tLen = t.length();
		for (int i = 0; i<tLen && sIdx<sLen; i++)
			if (t[i] == s[sIdx]) sIdx++;
		return sIdx == sLen;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

