// leetcode-820-Æ´½Ó×Ö·û´®.cpp : Defines the entry point for the console application.
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
class TrieNode {
public:
	unordered_map<char, TrieNode*> next;
};
class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		TrieNode *root = new TrieNode;
		vector<pair<TrieNode *, int>> leaves;
		for (auto & w : unordered_set<string>(words.begin(), words.end()))
		{
			TrieNode *cur = root;
			for (int i = w.length() - 1; i >= 0; --i)
			{
				if (cur->next.count(w[i]) == 0)
					cur->next[w[i]] = new TrieNode;
				cur = cur->next[w[i]];
			}
			leaves.push_back(make_pair(cur, w.length() + 1));
		}
		int res = 0;
		for (auto leaf : leaves) if ((leaf.first->next).size() == 0) res += leaf.second;
		return res;
	}
};

int main()
{
    return 0;
}

