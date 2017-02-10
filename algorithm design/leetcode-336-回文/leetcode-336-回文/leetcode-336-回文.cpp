// leetcode-336-回文.cpp : 定义控制台应用程序的入口点。
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
	bool is_pali(string str)
	{
		int i = 0;
		int j = str.size() - 1;

		while (i < j) {
			if (str[i++] != str[j--]) return false;
		}
		return true;
	}
	vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> dict;
		vector<vector<int>> ans;
		for (int i = 0; i < words.size(); i++) {
			string key = words[i];
			reverse(key.begin(), key.end());
			dict[key] = i;
		}
		if (dict.find("") != dict.end()){
			for (int i = 0; i < words.size(); i++){
				if (i == dict[""]) continue;
				if (is_pali(words[i])) ans.push_back({ dict[""], i }); // 1) if self is palindrome, here ans covers concatenate("", self) 
			}
		}
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++) {
				string left = words[i].substr(0, j);
				string right = words[i].substr(j);

				if (dict.find(left) != dict.end() && is_pali(right) && dict[left] != i) {
					ans.push_back({ i, dict[left] });     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
				}

				if (dict.find(right) != dict.end() && is_pali(left) && dict[right] != i) {
					ans.push_back({ dict[right], i });
				}
			}
		}
		return ans;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

