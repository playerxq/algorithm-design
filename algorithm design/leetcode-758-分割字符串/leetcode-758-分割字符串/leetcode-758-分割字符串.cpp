// leetcode-758-·Ö¸î×Ö·û´®.cpp : Defines the entry point for the console application.
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
	string boldWords(vector<string>& words, string S) {
		int n = S.size();
		if (words.size() == 0)
			return S;
		int len = words.size();
		vector<pair<int, int>> temp;
		for (int i = 0; i < len; i++)
		{
			int l = words[i].length();
			for (int j = 0; j + l <= n; j++)
			{
				if (words[i] == S.substr(j, l))
					temp.push_back(make_pair(j,j+l-1));
			}
		}
		int len1 = temp.size();
		vector<int> col(n,0);
		for (int i = 0; i < len1; i++)
		{
			int st = temp[i].first;
			int ed = temp[i].second;
			for (int j = st; j <= ed; j++)
				col[j] = 1;
		}
		string res;
		for (int i = 0; i < n; i++)
		{
			if (col[i] == 0)
			{
				if (!i||col[i-1]==0)
				{
					res += S[i];
				}
				else if (col[i - 1] == 1)
				{
					res += "</b>";
					res += S[i];
				}
			}
			if (col[i] == 1)
			{
				if (!i||col[i-1]==0)
				{
					res += "<b>";
					res += S[i];
				}
				else if (col[i - 1] == 1)
				{
					res += S[i];
				}
			}
		}
		if (col[n - 1] == 1)
			res += "</b>";
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> w = { "ccb","b","d","cba","dc"};
	string S = "eeaadadadc";
	s.boldWords(w,S);
    return 0;
}

