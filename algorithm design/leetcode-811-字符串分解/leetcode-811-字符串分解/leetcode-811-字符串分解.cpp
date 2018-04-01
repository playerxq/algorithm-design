// leetcode-811-×Ö·û´®·Ö½â.cpp : Defines the entry point for the console application.
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
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		vector<string> res;
		int n = cpdomains.size();
		map<string, int> mp;
		for (int i = 0; i < n; i++)
		{
			string cur = cpdomains[i];
			size_t id = cur.find_first_of(" ");
			int num = stoi(cur.substr(0,id));
			string dom = cur.substr(id+1);
			size_t last = 0;
			size_t nx = dom.find_first_of(".",last);
			while (nx != string::npos)
			{
				string nw = dom.substr(nx+1);
				if (!mp.count(nw))
				{
					mp.insert(make_pair(nw,num));
				}
				else
				{
					mp[nw] += num;
				}
				last = nx + 1;
				nx = dom.find_first_of(".",last);
			}
			if (!mp.count(dom))
			{
				mp.insert(make_pair(dom, num));
			}
			else
			{
				mp[dom] += num;
			}
		}
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			res.push_back(to_string(it->second)+" "+it->first);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> ve = { "9001 discuss.leetcode.com" };
	s.subdomainVisits(ve);
    return 0;
}

