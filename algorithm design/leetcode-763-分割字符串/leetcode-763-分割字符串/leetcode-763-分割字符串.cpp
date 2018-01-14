// leetcode-763-·Ö¸î×Ö·û´®.cpp : Defines the entry point for the console application.
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
	int partion(string s, map<int, int>& ct)
	{
		int ed = 0;
		/*
		map<int, int> tt(26,0);
		while (ed < s.length())
		{
			tt[s[ed] - 'a']++;
			int f = 0;
			for (int i = 0; i < 26; i++)
			{
				if (tt[i] != 0 && tt[i] < ct[i])
				{
					f = 1;
					break;
				}
			}
			if (!f)
				break;
			ed++;
		}
		*/
		return ed + 1;
	}
	vector<int> partitionLabels(string S) {
		map<int, int> ct(26,0);
		vector<int> res;
		int n = S.length();
		if (!n)
			return res;
		if (n == 1)
		{
			//res.push_back(1);
			return res;
		}
		for (int i = 0; i < n; i++)
		{
			//ct[S[i] - 'a']++;
		}
		int ed = 0;
		/*
		while (S.length())
		{
			int len = partion(S,ct);
			res.push_back(len);
			S = S.substr(len);
		}
		*/
		return res;
	}
};

int main()
{
	Solution s;
	//s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}

