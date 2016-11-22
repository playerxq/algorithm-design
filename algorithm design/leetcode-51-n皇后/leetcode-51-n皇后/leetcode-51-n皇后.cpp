// leetcode-51-n�ʺ�.cpp : �������̨Ӧ�ó������ڵ㡣
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
		int **vis = new int*[3]; //��һά��

		for( int i=0; i<3; i++)
		{
		    vis[i] = new int[2*n];  //����ڶ�ά��ÿһ�еĿռ䡣
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

