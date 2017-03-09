// leetcode-488-暴力.cpp : 定义控制台应用程序的入口点。
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
#define MAX_STEP 6 
class Solution {
public:
	string shrink(string s)
	{
		int i = 0;
		int start = 0;
		while (s.size()>0)
		{
			bool f = true;
			start = 0;
			for (i = 0; i <= s.size(); i++)
			{
				if (i == s.size() || s[i] != s[start])
				{
					if (i - start >= 3)
					{
						s = s.substr(0, start) + s.substr(i);
						f = false;
						break;
					}
					start = i;
				}
			}
			if (f)
				break;
		}
		return s;
	}
	int helper(string b, string h)
	{
		int res = MAX_STEP;
		if (b.size() == 0)
			return 0;
		if (h.size() == 0)
			return MAX_STEP;
		for (int i = 0; i < h.size(); i++)
		{
			int j = 0;
			int n = b.size();
			while (j < n)
			{
				auto bpos = b.find(h[i],j);
				if (bpos == string::npos)
					break;
				if (bpos < n - 1 && b[bpos] == b[bpos + 1])
				{
					string nb = b.substr(0,bpos)+b.substr(bpos+2);
					nb = shrink(nb);
					if (nb.size() == 0)
						return 1;
					string nh = h;
					nh.erase(i,1);
					res = min(res,helper(nb,nh)+1);
					bpos++;
				}
				else if (i>0 && h[i] == h[i - 1])
				{
					string nb = b.substr(0, bpos) + b.substr(bpos + 1);
					nb = shrink(nb);
					if (nb.size() == 0)
						return 2;
					string nh = h;
					nh = nh.erase(i, 1);
					nh = nh.erase(i-1,1);
					res = min(res, helper(nb, nh) + 2);
				}
				j = bpos + 1;
			}
		}
		return res;
	}
	int findMinStep(string board, string hand) {
		sort(hand.begin(), hand.end());
		int res = helper(board, hand);
		return res > hand.size() ? -1 : res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

