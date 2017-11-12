// leetcode-726-分子数目-递归+unordered-map.cpp : Defines the entry point for the console application.
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
	unordered_map<string, int> dfs(string formula, int& i)
	{
		unordered_map<string, int> mp;
		while (i < formula.size())
		{
			if (formula[i] == ')')
			{
				i = i + 1;
				int total = 0;
				while (i < formula.size() && isdigit(formula[i])) { total = total * 10 + formula[i++] - '0'; }
				if (total > 0) { for (auto m : mp) { mp[m.first] = m.second * total; } }
				break;
			}
			else if (formula[i] == '(')
			{
				i++;
				auto mp_2 = dfs(formula, i);
				for (auto m : mp_2)
				{
					if (mp.find(m.first) == mp.end()) mp[m.first] = 0;
					mp[m.first] += m.second;
				}
			}
			else
			{
				string element = "";
				int number = 0;
				if (formula[i] - 'A' >= 0 && formula[i] - 'A' < 26)
				{
					element += formula[i];
					i++;
					while (i < formula.size() && formula[i] - 'a' >= 0 && formula[i] - 'a' < 26)
					{
						element += formula[i];
						i++;
					}
					if (i < formula.size() && isdigit(formula[i]))
					{
						while (i < formula.size() && isdigit(formula[i]))
						{
							number = number * 10 + formula[i++] - '0';
						}
					}
					else
						number = 1;
				}
				if (mp.find(element) == mp.end()) mp[element] = 0;
				mp[element] += number;
			}
		}
		return mp;
	}
	string countOfAtoms(string formula) {
		int i = 0;
		string s = '(' + formula + ')';
		auto mp = dfs(s,i);
		vector<pair<string, int>> rec;
		for (auto m : mp)
			rec.push_back(m);
		sort(rec.begin(), rec.end(), [](pair<string, int>& a, pair<string, int>& b) {return a.first < b.first; });
		string res = "";
		for (auto v : rec) {
			res += v.first;
			if (v.second > 1) res += to_string(v.second);
		}
		return res;
	}
};
int main()
{
    return 0;
}

