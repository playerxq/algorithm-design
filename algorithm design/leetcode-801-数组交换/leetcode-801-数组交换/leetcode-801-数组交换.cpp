// leetcode-801-Êý×é½»»».cpp : Defines the entry point for the console application.
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
	int dfs(int cur, vector<int>& A, vector<int>& B, vector<vector<int>>& vis, int f)
	{
		int len = A.size();
		if (cur > len - 1)
			return 0;
		if (vis[cur][f] != -1)
			return vis[cur][f];
		if (A[cur] == B[cur])
			return dfs(cur + 1, A, B, vis,0);
		int res = INT_MAX;
		if (A[cur - 1] < A[cur] && B[cur - 1] < B[cur])
			res = min(res, dfs(cur + 1, A, B, vis,0));
		if (A[cur - 1] < B[cur] && B[cur - 1] < A[cur])
		{
			swap(A[cur],B[cur]);
			res = min(res,dfs(cur+1,A,B, vis,1)+1);
			swap(A[cur],B[cur]);
		}
		vis[cur][f]=res;
		return res;
	}
	int minSwap(vector<int>& A, vector<int>& B) {
		int cnt = 0;
		vector<int> AA;
		AA.push_back(-1);
		for (int i = 0; i < A.size(); i++)
			AA.push_back(A[i]);
		vector<int> BB;
		BB.push_back(-1);
		for (int i = 0; i < B.size(); i++)
			BB.push_back(B[i]);
		vector<vector<int>> vis(AA.size(),vector<int>(2,-1));
		cnt = dfs(1,AA,BB, vis, 0);
		return cnt;
	}
};

int main()
{
	vector<int> A = { 0,7,8,10,10,11,12,13,19,18};
	vector<int> B = { 4,4,5,7,11,14,15,16,17,20 };
	Solution s;
	s.minSwap(A,B);
    return 0;
}

