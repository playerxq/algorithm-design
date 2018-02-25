// leetcode-791-×Ö·û´®ÅÅÐò.cpp : Defines the entry point for the console application.
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
	string customSortString(string S, string T) {
		set<char> se;
		map<char, int> mp;
		string cur;
		for (int i = 0; i < T.size(); i++)
		{
			se.insert(T[i]);
			mp[T[i]]++;
		}
		for (int i = 0; i < S.size(); i++)
		{
			if (se.count(S[i]))
			{
				for (int j = 0; j < mp[S[i]]; j++)
					cur += S[i];
				mp[S[i]]=0;
			}
		}
		for (int i = 0; i < T.size(); i++)
		{
			if (mp[T[i]])
			{
				for (int j = 0; j < mp[T[i]]; j++)
					cur += T[i];
				mp[T[i]] = 0;
			}
		}
		return cur;
	}
};

int main()
{
	Solution s;
	s.customSortString("kqep","pekeq");
    return 0;
}

