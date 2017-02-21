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
		unordered_map<char, int> cnt;
		for (char c : s) cnt[c]++;
		int i = 0, j = 0, ans = 0;
		while (i < s.size()) {
			unordered_map<char, int> added;
			while (i < s.size() && cnt[s[i]] < k) ++i;
			j = i;
			while (j < s.size() && cnt[s[j]] + added[s[j]] >= k) {
				added[s[j]]++;
				cnt[s[j]]--;
				++j;
			}
			bool valid = true;
			for (char c = 'a'; c <= 'z' && valid; ++c) {
				if (added[c] != 0 && added[c] < k) valid = false;
			}
			if (valid) ans = max(ans, j - i);
			else ans = max(ans, longestSubstring(s.substr(i, j - i), k));
			i = j;
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

