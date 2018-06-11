// leetcode-838-¶àÃ×Åµ¹ÇÅÆBFS.cpp : Defines the entry point for the console application.
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
	string pushDominoes(string dominoes) {
		int n = dominoes.size();
		vector<int> le(n,INT_MAX);
		vector<int> ri(n,INT_MAX);
		string res;
		queue<int> leq;
		queue<int> riq;
		int step = 0;
		for (int i = 0; i < n; i++)
		{
			if (dominoes[i] == 'L')
			{
				leq.push(i);
				le[i] = 0;
			}
			else if (dominoes[i] == 'R')
			{
				riq.push(i);
				ri[i] = 0;
			}
		}
		while (!leq.empty() || !riq.empty())
		{
			step++;
			int le_size = leq.size();
			while (le_size > 0)
			{
				le_size--;
				int pos = leq.front();
				leq.pop();
				if (pos > 0 && le[pos - 1] == INT_MAX&&dominoes[pos - 1] != 'R')
				{
					le[pos - 1] = step;
					leq.push(pos-1);
				}
			}
			int ri_size = riq.size();
			while (ri_size > 0)
			{
				ri_size--;
				int pos = riq.front();
				riq.pop();
				if (pos +1<n && ri[pos + 1] == INT_MAX&&dominoes[pos + 1] != 'L')
				{
					ri[pos + 1] = step;
					riq.push(pos + 1);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (le[i] == ri[i])
				res.append(".");
			else if (le[i] < ri[i])
				res.append("L");
			else
				res.append("R");
		}
		return res;
	}
};
int main()
{
    return 0;
}

