// leetcode-395-最长包含重复字符的子串.cpp : 定义控制台应用程序的入口点。
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
	int longestSubstring(string s, int k) {
		if (s.size() == 0 || k > s.size())   return 0;
		if (k == 0)  return s.size();

		unordered_map<char, int> Map;
		for (int i = 0; i < s.size(); i++){
			Map[s[i]]++;
		}
		int idx = 0;
		while (idx <s.size() && Map[s[idx]] >= k)    idx++;
		if (idx == s.size()) return s.size();
		int left = longestSubstring(s.substr(0, idx), k);
		int right = longestSubstring(s.substr(idx + 1), k);

		return max(left, right);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

