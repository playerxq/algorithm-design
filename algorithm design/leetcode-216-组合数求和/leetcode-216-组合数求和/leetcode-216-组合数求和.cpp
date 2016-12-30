// leetcode-216-组合数求和.cpp : 定义控制台应用程序的入口点。
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
	void dfs(int st, int k, int n,vector<vector<int>>& res, vector<int>& ve, int re)
	{
		if(st>9&&n!=0)
			return;
		if(k<=0&&n!=0)
			return;
		if(re<n)
			return;
		if(k!=0&&n==0)
			return;
		if(k==0&&n==0)
		{
			res.push_back(ve);
			return;
		}
		for(int i = st;i<10;i++)
		{
			if(i>n)
				break;
			ve.push_back(i);
			dfs(i+1,k-1,n-i,res,ve,re-i);
			ve.pop_back();
		}
		return;
	}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
		vector<int> ve;
		int* sum = new int[11];
		int ss = 0;
		for(int i = 1;i<=9;i++)
		{
			sum[i] = ss+i;
			ss+=i;
		}
		for(int i = 1;i<10;i++)
		{
			if(i>n)
				break;
			ve.push_back(i);
			dfs(i+1,k-1,n-i,res,ve,sum[9]-sum[i]);
			ve.pop_back();
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

