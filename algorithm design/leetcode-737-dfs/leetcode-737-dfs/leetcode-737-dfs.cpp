// leetcode-737-dfs.cpp : Defines the entry point for the console application.
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
	bool isSimilar(string& s1, string& s2, unordered_map<string, unordered_set<string>>& p, unordered_set<string>& visited)
	{
		if (s1 == s2) return true;
		visited.emplace(s1);
		for (auto s : p[s1])
		{
			if (!visited.count(s) && isSimilar(s, s2, p, visited))
				return true;
		}
		return false;
	}
	bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
		if (words1.size() != words2.size()) return false;
		unordered_map<string, unordered_set<string>> p;
		for (auto &vp : pairs) {
			p[vp.first].emplace(vp.second);
			p[vp.second].emplace(vp.first);
		}
		for (int i = 0; i < words1.size(); i++)
		{
			unordered_set<string> visited;
			if (isSimilar(words1[i], words2[i], p, visited)) continue;
			else return false;
		}
		return true;
	}
};
int main()
{
    return 0;
}

