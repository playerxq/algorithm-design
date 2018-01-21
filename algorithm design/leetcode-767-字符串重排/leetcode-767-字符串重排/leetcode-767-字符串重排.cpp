// leetcode-767-×Ö·û´®ÖØÅÅ.cpp : Defines the entry point for the console application.
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
	string reorganizeString(string S) {
		int n = S.size();
		if (!n)
			return "";
		if (n == 1)
			return S;
		if (n == 2)
			return S[0] == S[1] ? "" : S;
		vector<int> mp(26,0);
		for (int i = 0; i < S.size(); i++)
		{
			mp[S[i] - 'a'] = mp[S[i] - 'a'] + 1;
		}
		string res(n,0);
		int mx = 0;
		int idx = -1;
		for (int i = 0; i < 26; i++)
		{
			if (mp[i] > mx)
			{
				mx = mp[i];
				idx = i;
			}
		}
		res[0] = idx + 'a';
		mp[idx]--;
		for (int i = 1; i < n; i++)
		{
			char pre = res[i-1];
			int d = pre - 'a';
			mx = 0;
			idx = -1;
			for (int j = 0; j < 26; j++)
			{
				if (mp[j] > mx&&j!=d)
				{
					mx = mp[j];
					idx = j;
				}
			}
			if (mx == 0)
			{
				return "";
			}
			res[i] = idx + 'a';
			mp[idx]--;
		}
		return res;
	}
};
int main()
{
	Solution s;
	s.reorganizeString("bfrbs");
    return 0;
}

