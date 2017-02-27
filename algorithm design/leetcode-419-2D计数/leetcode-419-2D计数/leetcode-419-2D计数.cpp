// leetcode-419-2D计数.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		if (board.empty() || board[0].empty()) { return 0; }
		int m = board.size(), n = board[0].size(), cnt = 0;

		for (int r = 0; r < m; r++)
			for (int c = 0; c < n; c++)
				cnt += board[r][c] == 'X' && (r == 0 || board[r - 1][c] != 'X') && (c == 0 || board[r][c - 1] != 'X');

		return cnt;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

