// leetcode-782-∆Â≈ÃΩªªª.cpp : Defines the entry point for the console application.
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
	void swap_cols(vector<vector<int>> &board, int c1, int c2) {
		int n = board.size();
		for (int i = 0; i<n; i++) {
			swap(board[i][c1], board[i][c2]);
		}
	}

	void swap_rows(vector<vector<int>> &board, int r1, int r2) {
		int n = board.size();
		for (int i = 0; i<n; i++) {
			swap(board[r1][i], board[r2][i]);
		}
	}

	bool verify(vector<vector<int>> &board) {
		int n = board.size();
		int b = board[0][0];

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if ((i + j) % 2 == 0 && board[i][j] != b) return false;
				if ((i + j) % 2 != 0 && board[i][j] == b) return false;
			}
		}

		return true;
	}

	int can_cols_swap(vector<vector<int>> board, int black) {
		int n = board.size();
		vector<int> blks, whites;
		int moves = 0;
		for (int i = 0; i<n; i++) {
			if (board[0][i] == black && i % 2 != 0) blks.push_back(i);
			if (board[0][i] != black && i % 2 == 0) whites.push_back(i);
		}

		if (blks.size() == whites.size()) {
			moves += blks.size();

			for (int i = 0; i<blks.size(); i++) {
				swap_cols(board, blks[i], whites[i]);
			}
			if (!verify(board)) moves = INT_MAX;
		}
		else moves = INT_MAX;

		return moves;
	}

	int can_rows_swap(vector<vector<int>> board, int black) {
		int moves = 0, n = board.size();
		vector<int> blks, whites;
		for (int i = 0; i<n; i++) {
			if (board[i][0] == black && i % 2 != 0) blks.push_back(i);
			if (board[i][0] != black && i % 2 == 0) whites.push_back(i);
		}

		if (blks.size() == whites.size()) {
			moves += blks.size();

			for (int i = 0; i<blks.size(); i++) {
				swap_rows(board, blks[i], whites[i]);
			}

			int col_moves = min(can_cols_swap(board, 0), can_cols_swap(board, 1));
			if (col_moves == INT_MAX) moves = INT_MAX;
			else moves += col_moves;
		}
		else moves = INT_MAX;

		return moves;
	}

	int movesToChessboard(vector<vector<int>>& board) {
		int ans = min(can_rows_swap(board, 0), can_rows_swap(board, 1));
		return ans == INT_MAX ? -1 : ans;
	}
};

int main()
{
    return 0;
}

