// leetcode-843-猜单词.cpp : Defines the entry point for the console application.
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
class Master {
	public:
		int guess(string word)
		{}
};
class Solution {
public:
	vector<vector<unordered_set<int>>> matches;//for word[i], all the other words has j chars matched with it, 
	vector<bool> visited;
	unordered_map<int, int> restriction;//restriction[i] = k: ith word has k matches with secret
	int match(string &w1, string &w2) {
		int m = 0;
		for (int i = 0; i < w1.size(); ++i) {
			if (w1[i] == w2[i]) {
				++m;
			}
		}
		return m;
	}
	int find_next(int guess_id, int m)
	{
		auto &set = matches[guess_id][m];//与当前guess_id单词有m个相同字符的单词集
		for (auto it = set.begin(); it != set.end(); ++it)
		{
			if (visited[*it]) continue;
			bool found = true;
			for (auto iter = restriction.begin(); iter != restriction.end(); ++iter)
			{
				if (matches[iter->first][iter->second].count(*it) == 0)
				{
					found = false;
					break;
				}
			}
			if (found) {
				return *it;
			}
		}
		return -1;
	}
	void findSecretWord(vector<string>& wordlist, Master& master) {
		int n = wordlist.size();
		int len = wordlist.at(0).size();
		matches = vector<vector<unordered_set<int>>>(n, vector<unordered_set<int>>(len + 1, unordered_set<int>()));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				int m = match(wordlist[i], wordlist[j]);
				matches[i][m].insert(j);
				matches[j][m].insert(i);
			}
		}
		visited = vector<bool>(n, false);
		int guess_id = 0;
		visited[guess_id] = true;
		int m = master.guess(wordlist[guess_id]);
		restriction[guess_id] = m;
		while (m != len)
		{
			guess_id = find_next(guess_id, m);
			if (guess_id < 0) return;
			m = master.guess(wordlist[guess_id]);
			restriction[guess_id] = m;
		}
	}
};
int main()
{
    return 0;
}

