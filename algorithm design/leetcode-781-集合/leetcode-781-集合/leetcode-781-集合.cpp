// leetcode-781-¼¯ºÏ.cpp : Defines the entry point for the console application.
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
#include <xfunctional>
using namespace std;
class Solution {
public:
	int numRabbits(vector<int>& answers) {
		if (answers.size() == 0)
			return 0;
		sort(answers.begin(),answers.end());
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < answers.size(); i++)
		{
			if (answers[i] == 0)
				sum++;
			else if(i==0)
			{
				sum += (answers[i] + 1);
				cnt = (answers[i] + 1);
				cnt--;
			}
			else if (answers[i] == answers[i - 1])
			{
				cnt--;
				if (cnt >= 0)
				{
					continue;
				}
				else
				{
					sum += (answers[i] + 1);
					cnt = (answers[i] + 1);
					cnt--;
				}
			}
			else
			{
				sum += (answers[i] + 1);
				cnt = (answers[i] + 1);
				cnt--;
			}
		}
		return sum;
	}
};

int main()
{
	vector<int> ve = { 2, 1, 2, 2, 2, 2, 2, 2, 1, 1 };
	Solution s;
	s.numRabbits(ve);
    return 0;
}

