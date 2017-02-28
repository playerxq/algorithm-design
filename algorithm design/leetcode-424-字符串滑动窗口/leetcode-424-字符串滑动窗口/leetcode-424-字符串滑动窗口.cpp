// leetcode-424-字符串滑动窗口.cpp : 定义控制台应用程序的入口点。
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
	int characterReplacement(string s, int k) {
		vector<int> counts(26, 0);
		int start = 0;
		int maxCharCount = 0;
		int n = s.length();
		int result = 0;
		for (int end = 0; end < n; end++){
			counts[s[end] - 'A']++;
			if (maxCharCount < counts[s[end] - 'A']){
				maxCharCount = counts[s[end] - 'A'];
			}
			while (end - start - maxCharCount + 1 > k){
				counts[s[start] - 'A']--;
				start++;
				for (int i = 0; i < 26; i++){
					if (maxCharCount < counts[i]){
						maxCharCount = counts[i];
					}
				}
			}
			result = max(result, end - start + 1);
		}
		return result;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

