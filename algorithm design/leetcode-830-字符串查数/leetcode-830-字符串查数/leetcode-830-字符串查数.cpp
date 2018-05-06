// leetcode-830-×Ö·û´®²éÊý.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> largeGroupPositions(string S) {
		int len = S.size();
		vector<vector<int>> res;
		if (!len)
			return res;
		int st  = 0;
		int ed = 0;
		int cnt = 0;
		for (int i = 0; i < len; i++)
		{
			if (S[i] == S[st])
			{
				ed = i;
				cnt++;
			}
			else
			{
				if (cnt >= 3)
				{
					vector<int> temp = {st,ed};
					res.push_back(temp);
				}
				st = i;
				ed = i;
				cnt = 1;
			}
		}
		if (cnt >= 3)
		{
			vector<int> temp = { st,ed };
			res.push_back(temp);
		}
		sort(res.begin(),res.end());
		return res;
	}
};

int main()
{
	Solution s;
	s.largeGroupPositions("abcdddeeeeaabbbcddddd");
    return 0;
}

