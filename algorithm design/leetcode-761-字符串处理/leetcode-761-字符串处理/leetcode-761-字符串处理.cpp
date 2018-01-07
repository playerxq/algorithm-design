// leetcode-761-×Ö·û´®´¦Àí.cpp : Defines the entry point for the console application.
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
	bool is_special(string s)
	{
		int n = s.size();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
				cnt++;
			else
				cnt--;

			if (cnt<0)
				return false;
		}
		return cnt==0;
	}
	string swap_s(string s, int i, int j, int k, int l)
	{
		string res;
		for (int e = 0; e< i; e++)
			res += s[e];
		for (int e = k; e <= l; e++)
			res += s[e];
		for (int e = i; e <= j; e++)
			res += s[e];
		for (int e = l + 1; e < s.length(); e++)
			res += s[e];
		return res;
	}
	string makeLargestSpecial(string S) {
		if (S.length() == 0) {
			return "";
		}
		string res = S;
		int n = S.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				string tmp = S.substr(i,j-i+1);
				if (is_special(tmp))
				{
					for (int k = j + 1; k < n; k++)
					{
						string tmp1 = S.substr(j+1,k-j);
						if (is_special(tmp1))
						{
							string ss = swap_s(S,i,j,j+1,k);
							if (ss.compare(res) > 0)
								res = ss;
						}
					}
				}
			}
		}
		if (res == S)
			return res;
		else
			return makeLargestSpecial(res);
	}
};

int main()
{
    return 0;
}

