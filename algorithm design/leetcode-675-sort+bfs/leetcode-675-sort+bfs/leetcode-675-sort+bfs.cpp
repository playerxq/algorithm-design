// leetcode-675-sort+bfs.cpp : Defines the entry point for the console application.
//1) Sort tree positions based on tree height; 
//2) BFS to find shortest path between two points;
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
	int cutOffTree(vector<vector<int>>& forest) {
		if (forest.empty() || forest[0].empty()) return 0;
		int m = forest.size(), n = forest[0].size();
		vector<vector<int>> trees;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (forest[i][j] > 1) trees.push_back({ forest[i][j], i, j });
			}
		}
		sort(trees.begin(), trees.end());//默认按照第一个元素即forest[i][j]排序
		int ans = 0;
		int cur_row = 0;
		int cur_col = 0;
		for (int i = 0; i < trees.size(); i++)
		{
			int step = next_step(forest, cur_row, cur_col, trees[i][1], trees[i][2]);
			if (step == -1) return -1;
			cur_row = trees[i][1];
			cur_col = trees[i][2];
			ans += step;
		}
		return ans;
	}
private:
	//bfs
	int next_step(vector<vector<int>>& forest, int sr, int sc, int er, int ec)
	{
		if (sr == er && sc == ec) return 0;
		int m = forest.size(), n = forest[0].size();
		queue<pair<int, int>> myq;
		myq.push({ sr, sc });
		vector<vector<int>> visited(m, vector<int>(n, 0));
		visited[sr][sc] = 1;
		int step = 0;
		vector<int> dir = { -1, 0, 1, 0, -1 };
		while (!myq.empty())
		{
			step++;
			int sz = myq.size();
			for (int i = 0; i < sz; i++)//对队列中当前层次所有点位按四个方向扩展 bfs
			{
				int row = myq.front().first, col = myq.front().second;
				myq.pop();
				for (int i = 0; i < 4; i++)
				{
					int r = row + dir[i], c = col + dir[i + 1];
					if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue;
					if (r == er && c == ec) return step;
					visited[r][c] = 1;
					myq.push({ r, c });
				}
			}
		}
		return -1;
	}
};
int main()
{
    return 0;
}

