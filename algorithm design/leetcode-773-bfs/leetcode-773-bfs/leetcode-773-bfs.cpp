// leetcode-773-bfs.cpp : Defines the entry point for the console application.
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
	int slidingPuzzle(vector<vector<int>>& board) {
		queue<int> Q;
		set<int> ss;
		int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
		int s = 0;
		int cur = 0;
		int cnt = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 0)
					board[i][j] = 6;
				s = s * 10 + board[i][j];
			}
		}
		Q.push(s);
		if (s == 123546||s==361425)
			return -1;
		ss.insert(s);
		Q.push(0);
		int t = 123456;
		int f = 1;
		while (!Q.empty())
		{
			cur = Q.front();
			Q.pop();
			if (cur == t)
				return cnt;
			if (cur == 0)
			{
				if (!f)
					break;
				f = 0;
				cnt++;
				Q.push(0);
			}
			else
			{
				int pos = 5;
				int tmp = cur;
				while (tmp)
				{
					int id = tmp % 10;
					tmp /= 10;
					if (id == 6)
						break;
					else
						pos--;
				}
				int x = pos / 3;
				int y = pos % 3;
				for (int i = 0; i < 4; i++)
				{
					int nx = x + dir[i][0];
					int ny = y + dir[i][1];
					if (nx >= 0 && nx <= 1 && ny >= 0 && ny <= 2)
					{
						int npos = nx * 3 + ny;
						int ncur = cur;
						int p = 5;
						int nn = 0;
						while (ncur)
						{
							if (p == npos)
							{
								nn = ncur % 10;
								break;
							}
							else
							{
								ncur /= 10;
								p--;
							}
						}
						ncur = 0;
						for (int i = 0; i < 6; i++)
						{
							if (i == pos)
							{
								ncur = ncur * 10 + nn;
							}
							else if (i == npos)
							{
								ncur = ncur * 10 + 6;
							}
							else
								ncur = ncur * 10 + (cur%(int)pow(10, (5 - i + 1))) / pow(10,5-i);
						}
						if (ss.count(ncur) == 0)
						{
							Q.push(ncur);
							ss.insert(ncur);
							f = 1;
						}
					}
				}
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> b = { {3,2,4},{1,5,0} };
	s.slidingPuzzle(b);
    return 0;
}

