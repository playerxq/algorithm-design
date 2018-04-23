// leetcode-822-·­×ª¿¨Æ¬.cpp : Defines the entry point for the console application.
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
	int flipgame(vector<int>& f, vector<int>& b) {
		unordered_set<int> same;
		int res = 3000;
		for (int i = 0; i < f.size(); ++i) if (f[i] == b[i]) same.insert(f[i]);
		for (int & i : f) if (same.count(i) == 0) res = min(res, i);
		for (int & i : b) if (same.count(i) == 0) res = min(res, i);
		return res % 3000;
	}
};

int main()
{
	Solution s;
	vector<int> f = {2,2};
	vector<int> b = {3,5};
	s.flipgame(f,b);
    return 0;
}

