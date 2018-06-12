// leetcode-846-dfs.cpp : Defines the entry point for the console application.
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
	bool dfs(map<int, int>& mp, int W)
	{
		if (mp.empty())
			return true;
		vector<int> cur;
		for (auto& p : mp)
		{
			if (cur.empty() || cur.back() == p.first - 1)
			{
				cur.push_back(p.first);
				p.second--;
				if (p.second == 0)
					mp.erase(p.first);
			}
			else
				break;
			if (cur.size() == W)
				break;
		}
		if (cur.size() < W)
			return false;
		return dfs(mp,W);
	}
	bool isNStraightHand(vector<int>& hand, int W) {
		int n = hand.size();
		if (n%W)
			return false;
		map<int, int> mp;
		for (int i = 0; i < n; i++)
			mp[hand[i]]++;
		return dfs(mp,W);
	}
};

int main()
{
    return 0;
}

