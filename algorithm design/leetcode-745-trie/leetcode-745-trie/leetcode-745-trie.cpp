// leetcode-745-trie.cpp : Defines the entry point for the console application.
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

struct Trie {
	vector<int> words; // index of words
	vector<Trie *> children;
	Trie() {
		children = vector<Trie *>(26, nullptr);
	}
};
class WordFilter {
public:
	Trie *forwardTrie, *backwardTrie;
	void add(Trie *t, string word, int index) {
		(t->words).push_back(index);
		if (word.length() >= 1) {
			if (!t->children[word[0] - 'a']) {
				t->children[word[0] - 'a'] = new Trie();
			}
			add(t->children[word[0] - 'a'], word.substr(1, word.length() - 1), index);
		}
	}
	vector<int> find(Trie *t, string prefix) {
		if (!t) {
			return{};
		}
		if (prefix.length() == 0) {
			return t->words;
		}
		else {
			return find(t->children[prefix[0] - 'a'], prefix.substr(1, prefix.length() - 1));
		}
	}
	WordFilter(vector<string> words) {
		forwardTrie = new Trie();
		backwardTrie = new Trie();
		for (int i = 0; i < words.size(); i++) {
			string word = words[i];
			add(forwardTrie, word, i);
			reverse(word.begin(), word.end());
			add(backwardTrie, word, i);
		}
	}

	int f(string prefix, string suffix) {
		auto forwardMatch = find(forwardTrie, prefix);
		reverse(suffix.begin(), suffix.end());
		auto backwardMatch = find(backwardTrie, suffix);
		auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();
		while (fIter != forwardMatch.rend() && bIter != backwardMatch.rend())
		{
			if (*fIter == *bIter)
				return *fIter;
			else if (*fIter > *bIter)
				fIter++;
			else
				bIter++;
		}
		return -1;
	}
};
int main()
{
    return 0;
}

