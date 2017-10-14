// leetcode-692-multimap.cpp : Defines the entry point for the console application.
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
	class dict
	{
	public:
		string mystr;
		int fre;
		dict(string str, int k): mystr(str), fre(k) {}
	};
	class cmp
	{
	public:
		bool operator()(const dict& a, const dict& b)
		{
			if (a.fre != b.fre)
				return a.fre < b.fre;
			else
			{
				if (a.mystr.compare(b.mystr) > 0)
					return true;
				return false;
			}
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res;
		unordered_map<string, int> mp;
		for (string s : words)
		{
			if (mp.count(s) == 0)
				mp[s] = 1;
			else
				mp[s]++;
		}
		auto iter = mp.begin();
		multimap<dict, string, cmp> mmp;
		for (int i = 0; i < k; i++)
		{
			int ff = iter->second;
			string ss = iter->first;
			dict dd(ss,ff);
			mmp.insert({dd,ss});
			iter++;
		}
		for (int i = k; i < mp.size(); i++)
		{
			int ff = iter->second;
			string ss = iter->first;
			dict dd(ss, ff);
			mmp.insert({ dd,ss });
			mmp.erase(mmp.begin());
			iter++;
		}
		for (auto it = mmp.rbegin(); it != mmp.rend(); it++)
		{
			res.push_back(it->second);
		}
		return res;
	}
};

int main()
{
    return 0;
}

