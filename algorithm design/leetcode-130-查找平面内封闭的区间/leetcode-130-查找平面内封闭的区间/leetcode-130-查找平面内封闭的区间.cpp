// leetcode-130-查找平面内封闭的区间.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	queue<pair<int,int>> Q;
	int ok(int x, int y, int r, int c)
	{
		if(x>=0&&x<r&&y>=0&&y<c)
			return 1;
		return 0;
	}
    void solve(vector<vector<char>>& board) {
		int row = board.size();
		if(!row)
			return;
		int col = board[0].size();
		
		int** dir = new int*[4];
		for(int i = 0;i<4;i++)
		{
			dir[i] = new int[2];
		}
		dir[0][0] = -1;
		dir[0][1] = 0;
		dir[1][0] = 1;
		dir[1][1] = 0;
		dir[2][0] = 0;
		dir[2][1] = -1;
		dir[3][0] = 0;
		dir[3][1] = 1;
		int flag = 1;
		for(int i = 0;i<row;i++)
		{
			if(board[i][0]=='O')
			{
				Q.push(make_pair(i,0));
			}
			if(board[i][col-1]=='O')
			{
				Q.push(make_pair(i,col-1));
			}
		}
		for(int i = 0;i<col;i++)
		{
			if(board[0][i]=='O')
			{
				Q.push(make_pair(0,i));
			}
			if(board[row-1][i]=='O')
			{
				Q.push(make_pair(row-1,i));
			}
		}
		while(!Q.empty())
		{
			pair<int,int> p = Q.front();
			Q.pop();
			int x = p.first;
			int y = p.second;
			board[x][y] = 'Y';
			for(int i = 0;i<4;i++)
			{
				int nx = x+dir[i][0];
				int ny = y+dir[i][1];
				if(!ok(nx,ny,row,col))
				{
					continue;
				}
				if(board[nx][ny]=='O')
				{
					Q.push(make_pair(nx,ny));
					continue;
				}
				else
					continue;
			}
		}
		for(int i = 0;i<row;i++)
		{
			for(int j = 0;j<col;j++)
			{
				if(board[i][j]=='Y')
					board[i][j] = 'O';
				else if(board[i][j]=='O')
					board[i][j] = 'X';
			}
		}
		return;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<vector<char>> board;
	vector<char> v;
	v.push_back('X');
	v.push_back('X');
	v.push_back('X');
	v.push_back('X');
	board.push_back(v);
	vector<char> v1;
	v1.push_back('X');
	v1.push_back('O');
	v1.push_back('O');
	v1.push_back('X');
	board.push_back(v1);
	vector<char> v2;
	v2.push_back('X');
	v2.push_back('X');
	v2.push_back('O');
	v2.push_back('X');
	board.push_back(v2);
	vector<char> v3;
	v3.push_back('X');
	v3.push_back('O');
	v3.push_back('X');
	v3.push_back('X');
	board.push_back(v3);
	s.solve(board);
}

