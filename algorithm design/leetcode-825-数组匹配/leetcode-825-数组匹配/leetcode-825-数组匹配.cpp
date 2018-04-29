// leetcode-825-Êý×éÆ¥Åä.cpp : Defines the entry point for the console application.
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
	int numFriendRequests(vector<int>& ages) {
		int n = ages.size();
		if (!n)
			return 0;
		sort(ages.begin(),ages.end());
		int res = 0;
		map<int, int> mp;
		for (int i = 0; i < ages.size(); i++)
		{
			if (mp.count(ages[i]))
			{
				res += mp[ages[i]];
				continue;
			}
			int ed = i+1;
			while (ed < ages.size() && (ages[i]*0.5+7<ages[ed]&&ages[ed] == ages[i]))
				ed++;
			ed--;
			int st = i - 1;
			while (st >= 0 && (ages[st] > ages[i]*0.5+7&&ages[st]<=ages[i]))
				st--;
			st++;
			if (ages[i] < 100)
			{
				while (ed > i&&ages[ed] > 100)
					ed--;
			}
			if (ed == i)
				ed = i - 1;
			if (st == i)
				st = i + 1;
			if (ed < st)
			{
				mp[ages[i]] = 0;
				continue;
			}
			int t = ed - st + 1;
			if (ed > i&&st < i)
				t--;
			res += t;
			mp[ages[i]] = t;
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> ve = { 8,24,69,85,85 };
	//vector<int> ve = { 20,30,100,110,120 };
	s.numFriendRequests(ve);
    return 0;
}

