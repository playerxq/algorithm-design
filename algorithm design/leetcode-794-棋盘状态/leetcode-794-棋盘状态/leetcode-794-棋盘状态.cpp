// leetcode-794-ÆåÅÌ×´Ì¬.cpp : Defines the entry point for the console application.
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
	int check_succ(vector<vector<int>> mp, int f)
	{
		for (int i = 0; i < 3; i++)
		{
			if (mp[i][0] == f&&mp[i][1] == f&&mp[i][2] == f)
				return 1;
		}
		for (int i = 0; i < 3; i++)
		{
			if (mp[0][i] == f&&mp[1][i] == f&&mp[2][i] == f)
				return 1;
		}
		if (mp[0][0] == f&&mp[1][1] == f&&mp[2][2] == f)
			return 1;
		if (mp[0][2] == f&&mp[1][1] == f&&mp[2][0] == f)
			return 1;
		return 0;
	}
	bool validTicTacToe(vector<string>& board) {
		int num_o = 0;
		int num_x = 0;
		int succ_o = 0;
		int succ_x = 0;
		vector<vector<int>> mp = { {0,0,0},{0,0,0},{0,0,0} };
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == 'X')
				{
					num_x++;
					mp[i][j] = 1;
				}
				else if (board[i][j] == 'O')
				{
					num_o++;
					mp[i][j] = 2;
				}
				else
					continue;
			}
		}
		if (num_o > num_x)
			return false;
		if (num_x > num_o + 1)
			return false;
		succ_o = check_succ(mp,2);
		succ_x = check_succ(mp,1);
		if (num_o == num_x&&succ_x == 1)
			return false;
		if (num_o + 1 == num_x&&succ_o == 1)
			return false;
		if (succ_x == 1 && succ_o == 1)
			return false;
		return true;

	}
};

int main()
{
	Solution s;
	vector<string> board = { "XOX", "O O", "XOX" };
	s.validTicTacToe(board);
    return 0;
}

