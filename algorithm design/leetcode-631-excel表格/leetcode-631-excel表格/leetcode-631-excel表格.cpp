// leetcode-631-excel±í¸ñ.cpp : Defines the entry point for the console application.
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
class Excel {
public:
	unordered_map<int, unordered_map<int, int>> fward;
	unordered_map<int, unordered_set<int>> bward;
	vector<vector<int>> Exl;
	Excel(int H, char W) {
		Exl = vector<vector<int>>(H + 1, vector<int>(W - 'A' + 1, 0));
		fward.clear();
		bward.clear();
	}
	// update a cell and all the sum related, using BFS
	// weights are used to improve efficiency for overlapping ranges
	void update(int r, int col, int v) {
		int prev = Exl[r][col];
		Exl[r][col] = v;
		// myq is keys for cells in next level, and update is the increment for each cell
		queue<int> myq, update;
		myq.push(r * 26 + col);
		update.push(v - prev);
		while (!myq.empty()) {
			int key = myq.front(), dif = update.front();
			myq.pop();
			update.pop();
			if (fward.count(key)) {
				for (auto it = fward[key].begin(); it != fward[key].end(); it++) {
					int k = it->first;
					myq.push(k);
					update.push(dif*(it->second));
					Exl[k / 26][k % 26] += dif*(it->second);
				}
			}
		}
	}
	void set(int r, char c, int v) {
		int col = c - 'A', key = r * 26 + col;
		// update its value and all the sum related
		update(r, col, v);
		// This is a reset, so break all the forward links if existing
		if (bward.count(key)) {
			for (int k : bward[key]) {
				fward[k].erase(key);
			}
			bward[key].clear();
		}
	}

	int get(int r, char c) {
		return Exl[r][c - 'A'];
	}

	int sum(int r, char c, vector<string> strs) {
		// this is another reset, so break all the forward links
		int col = c - 'A', key = r * 26 + col, ans = 0;
		if (bward.count(key)) {
			for (int k : bward[key]) {
				fward[k].erase(key);
			}
			bward[key].clear();
		}
		// get the sum over multiple ranges
		for (string str : strs) {
			int p = str.find(':'), left, right, top, bot;
			left = str[0] - 'A';
			right = str[p + 1] - 'A';
			if (p == -1)
				top = stoi(str.substr(1));
			else
				top = stoi(str.substr(1, p - 1));
			bot = stoi(str.substr(p + 2));
			for (int i = top; i <= bot; ++i) {
				for (int j = left; j <= right; ++j) {
					ans += Exl[i][j];
					fward[i * 26 + j][key]++;
					bward[key].insert(i * 26 + j);
				}
			}
		}
		// update this cell and all the sum related
		update(r, col, ans);
		return ans;
	}
};

int main()
{
    return 0;
}

