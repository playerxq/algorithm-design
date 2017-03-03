// leetcode-451-字符串排序.cpp : 定义控制台应用程序的入口点。
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
	string frequencySort(string s) {
		if (s.size() == 0)
			return s;
		map<char, int> fre;
		vector<string> buck(s.size()+1);
		for (auto i : s)
		{
			fre[i]++;
		}
		for (auto& it : fre)
		{
			buck[it.second].append(it.second,it.first);
		}
		string res;
		for (int i = s.size(); i >= 0; i--)
		{
			if (!buck[i].empty())
				res += buck[i];
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.frequencySort("Aabb");
	return 0;
}

