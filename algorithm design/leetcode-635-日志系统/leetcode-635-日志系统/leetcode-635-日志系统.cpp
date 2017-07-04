// leetcode-635-日志系统.cpp : Defines the entry point for the console application.
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
class LogSystem {
public:
	unordered_map<string, int> mp;
	unordered_map<string, int> mapping;
	LogSystem() {
		mapping["Year"] = 0;
		mapping["Month"] = 1;
		mapping["Day"] = 2;
		mapping["Hour"] = 3;
		mapping["Minute"] = 4;
		mapping["Second"] = 5;
	}

	void put(int id, string timestamp) {
		mp[timestamp] = id;
	}
	vector<int> split(string t) {
		vector<int> words;
		istringstream iss(t);
		string s;
		while (getline(iss, s, ':')) {
			words.push_back(stoi(s));
		}
		return words;
	}
	bool smaller(string t1, string t2, string grad) {
		auto w1 = split(t1);
		auto w2 = split(t2);
		for (int i = 0; i <= mapping[grad]; i++) {
			if (w1[i] > w2[i]) return false;
			else if (w1[i] < w2[i]) return true;
		}
		return true;
	}
	bool bigger(string t1, string t2, string grad) {
		auto w1 = split(t1);
		auto w2 = split(t2);
		for (int i = 0; i <= mapping[grad]; i++) {
			if (w1[i] < w2[i]) return false;
			else if (w1[i] > w2[i]) return true;
		}
		return true;
	}
	vector<int> retrieve(string s, string e, string gra) {
		vector<int> result;
		for (auto p : mp) {
			string tp = p.first;
			if (bigger(tp, s, gra) && smaller(tp, e, gra)) result.push_back(p.second);
		}
		return result;
	}
};

int main()
{
    return 0;
}

