// leetcode-789-∆Â≈Ãæ‡¿Î.cpp : Defines the entry point for the console application.
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
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int step, i;
		step = abs(target[0]) + abs(target[1]);
		for (i = 0; i<ghosts.size() && abs(target[0] - ghosts[i][0]) + abs(target[1] - ghosts[i][1])>step; ++i);
		return i == ghosts.size();
	}
};
int main()
{
    return 0;
}

