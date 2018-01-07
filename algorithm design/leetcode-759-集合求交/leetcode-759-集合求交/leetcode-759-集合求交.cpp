// leetcode-759-集合求交.cpp : Defines the entry point for the console application.
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

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
		vector<Interval> res;
		if (avails.empty()) return res;
		vector<Interval> current = avails[0];
		for (int k = 1; k<avails.size(); k++) {
			// merge interval current, next.
			vector<Interval> &next = avails[k];
			vector<Interval> temp;
			int i = 0, j = 0;
			while (i < current.size() || j < next.size()) {
				if (j == next.size() || (i < current.size() && current[i].start < next[j].start)) {
					//current[i].start is to be merged.
					if (temp.empty() || temp.back().end < current[i].start) {
						temp.push_back(current[i++]);
					}
					else {
						temp.back().end = max(temp.back().end, current[i++].end);
					}
				}
				else {
					//next[j].start is to be merged.
					if (temp.empty() || temp.back().end < next[j].start) {
						temp.push_back(next[j++]);
					}
					else {
						temp.back().end = max(temp.back().end, next[j++].end);
					}
				}
			}
			swap(current, temp);
		}
		
		int t = 0;
		for (int i = 1; i<current.size(); i++) {
			res.push_back(Interval(current[i - 1].end, current[i].start));
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<Interval>> a = { {{1, 3},{6, 7}},{{2, 4}},{{2, 5},{9, 12}} };
	s.employeeFreeTime(a);
    return 0;
}

