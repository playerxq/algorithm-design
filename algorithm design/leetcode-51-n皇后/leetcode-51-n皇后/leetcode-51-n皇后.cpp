// leetcode-51-n皇后.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int dfs(int cur,int n,vector<vector<string>>& res, vector<string>& ans,int** vis)
	{
		int i,j;
		if(cur==n)
		{
			res.push_back(ans);
			return 1;
		}
		else for(i = 0;i<n;i++)
		{
			if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n-1])
			{
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n-1] = 1;
				string str(n,'.');
				str[i]='Q';
				ans.push_back(str);
				dfs(cur+1,n,res,ans,vis);
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n-1] = 0;
				ans.pop_back();
			}
		}
		return 1;
	}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
		vector<string> ans;
		int **vis = new int*[3]; //第一维，

		for( int i=0; i<3; i++)
		{
		    vis[i] = new int[2*n];  //分配第二维，每一行的空间。
		}
		for(int i = 0;i<3;i++)
		{
			for(int j = 0;j<2*n;j++)
				vis[i][j] = 0;
		}
		dfs(0,n,res,ans,vis);
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.solveNQueens(4);
}

