// leetcode-661-网格平均数.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int r = M.size();
		int c = 0;
		if (r >= 1)
			c = M[0].size();
		int dir[8][2] = { {-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1} };
		vector<vector<int>> res(r,vector<int>(c,0));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int sum = M[i][j];
				int cnt = 1;
				for (int k = 0; k < 8; k++)
				{
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if (x>=0&&x<r&&y>=0&&y<c)
					{
						cnt++;
						sum += M[x][y];
					}
				}
				res[i][j] = sum / cnt;
			}
		}
		return res;
	}
};
int main()
{
    return 0;
}

