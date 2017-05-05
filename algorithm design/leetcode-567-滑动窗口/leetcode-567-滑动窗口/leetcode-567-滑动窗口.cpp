// leetcode-567-滑动窗口.cpp : 定义控制台应用程序的入口点。
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
	bool checkInclusion(string s1, string s2) {
		vector<int> cnt(256,0);
		for (char ch : s1)
			cnt[ch]++;
		int left = s1.size();
		for (int i = 0, j = 0; j < s2.size(); j++)
		{
			if (cnt[s2[j]]-- > 0)
				left--;
			while (left == 0)
			{
				if (j - i + 1 == s1.size())
					return true;
				if (++cnt[s2[i++]] > 0)
					++left;
			}
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

