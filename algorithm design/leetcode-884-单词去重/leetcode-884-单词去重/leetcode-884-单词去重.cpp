// leetcode-884-单词去重.cpp : 定义控制台应用程序的入口点。
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
	vector<string> uncommonFromSentences(string A, string B) {
		int len1 = A.length();
		int len2 = B.length();
		unordered_map<string, int> ss;
		vector<string> res;
		stringstream sss(A+' '+B);
		string tmp;
		while (sss >> tmp)
		{
			ss[tmp]++;
		}
		for (auto ssss : ss)
		{
			if(ssss.second==1)
				res.push_back(ssss.first);
		}
		return res;
	}
};

int main()
{
    return 0;
}

