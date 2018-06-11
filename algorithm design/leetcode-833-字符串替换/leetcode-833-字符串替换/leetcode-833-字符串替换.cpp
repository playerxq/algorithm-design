// leetcode-833-×Ö·û´®Ìæ»».cpp : Defines the entry point for the console application.
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
	string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		vector<pair<int, int>> sorted;
		for (int i = 0; i < indexes.size(); i++) sorted.push_back(make_pair(indexes[i], i));
		sort(sorted.rbegin(), sorted.rend());
		for (auto ind : sorted) {
			int i = ind.first;
			string s = sources[ind.second], t = targets[ind.second];
			if (S.substr(i, s.length()) == s) S = S.substr(0, i) + t + S.substr(i + s.length());
		}
		return S;
	}
};

int main()
{
    return 0;
}

