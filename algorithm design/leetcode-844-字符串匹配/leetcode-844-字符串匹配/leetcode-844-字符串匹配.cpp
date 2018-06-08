// leetcode-844-×Ö·û´®Æ¥Åä.cpp : Defines the entry point for the console application.
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
	bool backspaceCompare(string S, string T) {
		string s;
		int len1 = S.size();
		if (len1 == 1)
			s = S;
		else
		{
			int st = 0;
			while (st < len1)
			{
				int nx = st;
				while (nx<len1&&S[nx] != '#')
					nx++;
				int ed = nx - 1;
				int cnt = 0;
				while (nx < len1&&S[nx] == '#')
				{
					cnt++;
					nx++;
				}
				s.append(S.substr(st, ed - st + 1));
				if (s.length() >= cnt)
					s = s.substr(0, s.length() - cnt);
				else
					s = "";
				st = nx;
				ed = st;
			}
		}
		string t;
		int len2 = T.size();
		if (len2 == 1)
			t = T;
		else
		{
			int st = 0;
			while (st < len2)
			{
				int nx = st;
				while (nx<len2&&T[nx] != '#')
					nx++;
				int ed = nx - 1;
				int cnt = 0;
				while (nx < len2&&T[nx] == '#')
				{
					cnt++;
					nx++;
				}
				t.append(T.substr(st, ed - st + 1));
				if (t.length() >= cnt)
					t = t.substr(0, t.length() - cnt);
				else
					t = "";
				st = nx;
				ed = st;
			}
		}
		return s == t;
	}
};
int main()
{
	Solution s;
	s.backspaceCompare("bxj##tw","bxo#j##tw");
    return 0;
}

