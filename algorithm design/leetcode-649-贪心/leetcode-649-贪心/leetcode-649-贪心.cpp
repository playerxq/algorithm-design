// leetcode-649-Ì°ÐÄ.cpp : Defines the entry point for the console application.
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
	string predictPartyVictory(string senate) {
		int len = 0;
		int count = 0;
		while (senate.size() != len)
		{
			string s;
			len = senate.size();
			for (int i = 0; i < len; i++)
			{
				if (senate[i] == 'R')
				{
					if (count++ >= 0)
					{
						s += 'R';
					}
				}
				else
				{
					if (count-- <= 0)
					{
						s += 'D';
					}
				}
			}
			swap(s, senate);
		}
		if (senate[0] == 'R')
			return "Radiant";
		else
			return "Dire";
	}
};

int main()
{
    return 0;
}

