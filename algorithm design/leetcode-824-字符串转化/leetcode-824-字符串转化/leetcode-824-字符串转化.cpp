// leetcode-824-×Ö·û´®×ª»¯.cpp : Defines the entry point for the console application.
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
	string toGoatLatin(string S) {
		int n = S.size();
		vector<string> ve;
		int st = 0;
		for (int i = 0; i < n; i++)
		{
			if (S[i] == ' ')
			{
				ve.push_back(S.substr(st,i-st));
				st = i + 1;
			}
		}
		ve.push_back(S.substr(st));
		vector<string> vv;
		int id = 1;
		for (auto s : ve)
		{
			int len = s.size();
			if (toupper(s[0]) == 'A' || toupper(s[0]) == 'E' || toupper(s[0]) == 'I' || toupper(s[0]) == 'O' || toupper(s[0]) == 'U')
			{
				s.append("ma");
			}
			else
			{
				char t = s[0];
				s = s.substr(1);
				s += t;
				s.append("ma");
			}
			for (int i = 0; i < id; i++)
				s += 'a';
			vv.push_back(s);
			id++;
		}
		string res;
		for (int i = 0; i < vv.size(); i++)
		{
			res += vv[i];
			if (i < vv.size() - 1)
				res += " ";
		}
		return res;
	}
};
int main()
{
	Solution s;
	s.toGoatLatin("The quick brown fox jumped over the lazy dog");
    return 0;
}

