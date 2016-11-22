// leetcode-39-求和.cpp : 定义控制台应用程序的入口点。
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
	vector<vector<int>> ve;
	int dfs(int tar, vector<int>& cur,vector<int>& candidates,int st)
	{
		if(tar==0)
		{
			ve.push_back(cur);
			return 1;
		}
		if(tar<candidates[st])
			return 0;
		for(int i = st;i<candidates.size();i++)
		{
			if(tar>=candidates[i])
			{
				cur.push_back(candidates[i]);
				dfs(tar-candidates[i],cur,candidates,i+1);
				int k = i+1;
				while(k<candidates.size()&&candidates[k]==candidates[i])
					k++;
				i = k-1;
				cur.pop_back();
			}
		}
		return 0;
	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		int n = candidates.size();
		//candidates.erase(std::unique(candidates.begin(), candidates.end()), candidates.end());
		sort(candidates.begin(),candidates.end());
		vector<int> cur;
		dfs(target,cur,candidates,0);
		return ve;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> v;
	v.push_back(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(6);
	v.push_back(1);
	v.push_back(5);
	//v.push_back(7);
	Solution s;
	s.combinationSum2(v,8);
}

