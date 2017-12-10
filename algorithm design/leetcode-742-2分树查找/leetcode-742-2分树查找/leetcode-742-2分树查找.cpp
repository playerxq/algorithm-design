// leetcode-742-2∑÷ ˜≤È’“.cpp : Defines the entry point for the console application.
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void dfs(TreeNode* root, vector<vector<int>>& mp,vector<int>& leaf)
	{
		if (root == NULL)
			return;
		if (root->left != NULL)
		{
			mp[root->val].push_back(root->left->val);
			mp[root->left->val].push_back(root->val);
			dfs(root->left,mp,leaf);
		}
		if (root->right != NULL)
		{
			mp[root->val].push_back(root->right->val);
			mp[root->right->val].push_back(root->val);
			dfs(root->right, mp,leaf);
		}
		if (root->left == NULL&&root->right == NULL)
			leaf[root->val] = 1;
	}
	int findClosestLeaf(TreeNode* root, int k) {
		vector<vector<int>> mp(1001);
		queue<int> Q;
		vector<int> vis(1001,0);
		vector<int> dp(1001, 0);
		vector<int> leaf(1001, 0);
		dfs(root,mp,leaf);
		Q.push(k);
		vis[k] = 1;
		dp[k] = 0;
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			int m = mp[cur].size();
			for (int i = 0; i < m; i++)
			{
				if (vis[mp[cur][i]] == 0 || dp[mp[cur][i]] > dp[cur] + 1)
				{
					vis[mp[cur][i]] = 1;
					dp[mp[cur][i]] = dp[cur] + 1;
					Q.push(mp[cur][i]);
				}
			}
		}
		int minx = 1001;
		int idx = 0;
		for (int i = 1; i <= 1000; i++)
		{
			if (leaf[i] == 1 && dp[i] <= minx)
			{
				minx = dp[i];
				idx = i;
			}
		}
		return idx;
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right= new TreeNode(5);
	root->right->left->left = new TreeNode(6);
	root->right->left->left->left = new TreeNode(8);
	root->right->left->left->right = new TreeNode(9);
	root->right->right->right = new TreeNode(7);
	root->right->right->right->left = new TreeNode(10);
	s.findClosestLeaf(root,4);
    return 0;
}

