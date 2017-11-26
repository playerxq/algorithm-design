// leetcode-735-vector asteriod.cpp : Defines the entry point for the console application.
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
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> st;
		for (int i = 0; i < asteroids.size(); i++)
		{
			if (st.empty() || asteroids[i] > 0)
			{
				st.push_back(asteroids[i]);
				continue;
			}
			while (true)
			{
				int prev = st.back();
				if (prev < 0)
				{
					st.push_back(asteroids[i]);
					break;
				}
				if (prev == -asteroids[i])
				{
					st.pop_back();
					break;
				}
				if (prev > -asteroids[i])
				{
					break;
				}
				else
				{
					st.pop_back();
					if (st.empty())
					{
						st.push_back(asteroids[i]);
						break;
					}
				}

			}
		}
		return st;
	}
};
int main()
{
    return 0;
}

