// leetcode-94-inorder travel.cpp : 定义控制台应用程序的入口点。
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
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> ve;
		vector<int> res;
		TreeNode* cur = root;
		TreeNode* pre=NULL;
		while(cur!=NULL)
		{
			ve.push_back(cur);
			cur = cur->left;
		}
		while(!ve.empty())
		{
			res.push_back(ve.back()->val);
			cur = ve.back()->right;
			ve.pop_back();
			while(cur!=NULL)
			{
				ve.push_back(cur);
				cur = cur->left;
			}
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

