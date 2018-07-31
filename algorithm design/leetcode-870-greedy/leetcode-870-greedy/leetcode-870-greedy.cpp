// leetcode-870-greedy.cpp : Defines the entry point for the console application.
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
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		int n = A.size();
		vector<int> res;
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			mp[A[i]]++;
		}
		for (auto b : B)
		{
			int cur = mp.upper_bound(b) != mp.end() ? (mp.upper_bound(b))->first : mp.begin()->first;
			res.push_back(cur);
			mp[cur]--;
			if (mp[cur] == 0)
				mp.erase(cur);
		}
		return res;
	}
};

int main()
{
    return 0;
}

