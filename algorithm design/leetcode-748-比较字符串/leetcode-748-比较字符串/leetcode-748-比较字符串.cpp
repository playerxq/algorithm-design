// leetcode-748-±È½Ï×Ö·û´®.cpp : Defines the entry point for the console application.
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
	string shortestCompletingWord(string ls, vector<string>& words) {
		map<char, int> mp;
		vector<string> res;
		int n = ls.length();
		for (int i = 0; i < n; i++)
		{
			if ((ls[i] >= 'a'&&ls[i] <= 'z') || (ls[i] >= 'A'&&ls[i] <= 'Z'))
			{
				if (mp.count(toupper(ls[i])))
					mp[toupper(ls[i])]++;
				else
					mp.insert(make_pair(toupper(ls[i]),1));
			}
		}
		int k = words.size();
		for (int i = 0; i < k; i++)
		{
			map<char, int> tmp;
			int l = words[i].size();
			for (int j = 0; j < l; j++)
			{
				if ((words[i][j] >= 'a'&&words[i][j] <= 'z') || (words[i][j] >= 'A'&&words[i][j] <= 'Z'))
				{
					if (tmp.count(toupper(words[i][j])))
						tmp[toupper(words[i][j])]++;
					else
						tmp.insert(make_pair(toupper(words[i][j]), 1));
				}
			}
			int f = 0;
			for (int j = 0; j < n; j++)
			{
				if ((ls[j] >= 'a'&&ls[j] <= 'z') || (ls[j] >= 'A'&&ls[j] <= 'Z'))
				{
					if (mp[toupper(ls[j])] > tmp[toupper(ls[j])])
					{
						f = 1;
						break;
					}
				}
			}
			if (!f)
				res.push_back(words[i]);
		}
		int s = res.size();
		string ress;
		int ss = res[0].size();
		ress = res[0];
		for (int i = 1; i < s; i++)
		{
			if (res[i].size() < ss)
			{
				ss = res[i].size();
				ress = res[i];
			}
		}
		return ress;
	}
};
int main()
{
	Solution s;
	vector<string> ve = { "looks","pest","stew","show"};
	s.shortestCompletingWord("1s3 456",ve);
    return 0;
}

