// leetcode-792-×Ó´®ÊýÄ¿.cpp : Defines the entry point for the console application.
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
	bool checkchild(string &s, string &t)
	{
		int j = 0;
		for (int i = 0; i < t.size(); i++)
		{
			while (j < s.size() && t[i] != s[j])
				j++;
			if (j == s.size())
				return false;
			j++;
		}
		return true;
	}
	int numMatchingSubseq(string S, vector<string>& words) {
		int sum = 0;
		map<string, int> mp;
		for (int i = 0; i < words.size(); i++)
		{
			mp[words[i]]++;
		}
		for (map<string, int>::iterator it = mp.begin();it!=mp.end();it++)
		{
			string t = it->first;
			if (checkchild(S, t))
				sum += it->second;
		}
		return sum;
	}
};
int main()
{
	vector<string> ve = { "a", "bb", "acd", "ace" };
	Solution s;
	s.numMatchingSubseq("abcde",ve);
    return 0;
}

