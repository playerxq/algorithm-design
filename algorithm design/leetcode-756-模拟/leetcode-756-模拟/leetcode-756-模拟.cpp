// leetcode-756-Ä£Äâ.cpp : Defines the entry point for the console application.
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
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		vector<int> st(bottom.size(), 0);
		for (int i = 0; i < bottom.size(); i++)
			st[i] = (1 << (bottom[i] - 'A'));
		vector<vector<int>> T(7, vector<int>(7, 0));
		for (int i = 0; i < allowed.size(); i++)
		{
			T[allowed[i][0] - 'A'][allowed[i][1] - 'A'] |= (1 << (allowed[i][2] - 'A'));
		}
		int n = bottom.size();
		while (--n>0)
		{
			for (int i = 0; i < n; i++)
			{
				int temp = 0;
				for (int k = 0; k < 7; k++)
				{
					if (((st[i] >> k) & 1) != 0)
					{
						for (int k1 = 0; k1 < 7; k1++)
						{
							if (((st[i + 1] >> k1) & 1) != 0)
							{
								for (int k2 = 0; k2 < 7; k2++)
									temp |= (((T[k][k1] >> k2) & 1) << k2);
							}
						}
					}
				}
				st[i] = temp;
			}
		}
		return (st[0] > 0);
	}
};
int main()
{
    return 0;
}

