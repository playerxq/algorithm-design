// leetcode-854-dfs-string½»»»×Ö·û.cpp : Defines the entry point for the console application.
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
	int kSimilarity(string A, string B) {
		if (!A.compare(B))
			return 0;
		queue<string> Q;
		Q.push(A);
		int res = 0;
		set<string> vis;
		vis.insert(A);
		while (!Q.empty())
		{
			res++;
			int sz = Q.size();
			for (int i = 0; i < sz; i++)
			{
				string temp = Q.front();
				Q.pop();
				int k = 0;
				while (temp[k] == B[k])
					k++;
				int j = k + 1;
				for (; j < temp.length(); j++)
				{
					if (temp[j] == B[j] || B[j] != temp[k])
						continue;
					string cur = temp;
					swap(cur[k],cur[j]);
					if (cur.compare(B) == 0)
						return res;
					if (vis.find(cur)==vis.end())
					{
						Q.push(cur);
						vis.insert(cur);
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	s.kSimilarity("abac", "baca");
    return 0;
}

