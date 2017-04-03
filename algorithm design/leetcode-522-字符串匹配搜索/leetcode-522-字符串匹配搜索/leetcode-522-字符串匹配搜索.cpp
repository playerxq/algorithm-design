// leetcode-522-字符串匹配搜索.cpp : 定义控制台应用程序的入口点。
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
	//This is used to determine if a has common subsequence in b
	bool hasCommon(string a, string b){
		int remine = 0;
		int remine2 = 0;
		for (; remine<a.size() && remine2<b.size();){
			int i = a.size() - remine;
			int j = b.size() - remine2;
			if (a.at(remine) == b.at(remine2)){
				remine++; remine2++;
			}
			else{
				remine2++;
			}
		}
		return remine == a.size();
	}
	int findLUSlength(vector<string>& strs) {
		int maxLen = -1;
		for (int i = 0; i<strs.size(); ++i){
			int currentLen = strs[i].length();
			bool all = true;
			for (int j = 0; j<strs.size(); ++j){
				if (i != j&&hasCommon(strs[i], strs[j])){
					all = false;
					break;
				}
			}
			if (all){
				maxLen = maxLen<currentLen ? currentLen : maxLen;
			}
		}
		return maxLen;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

