// leetcode-676-×ÖµäÉè¼Æ.cpp : Defines the entry point for the console application.
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

class MagicDictionary {
public:
	/** Initialize your data structure here. */
	MagicDictionary() {

	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (string &s : dict) words.insert(s);
	}

	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		for (int i = 0; i < word.size(); i++)
		{
			char c = word[i];
			for (int j = 0; j < 26; j++)
			{
				if (c == j + 'a') continue;
				word[i] = j + 'a';
				if (words.count(word)) return true;
			}
			word[i] = c;
		}
		return false;
	}
private:
	unordered_set<string> words;
};
int main()
{
    return 0;
}

