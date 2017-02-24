// leetcode-406-队列重排.cpp : 定义控制台应用程序的入口点。
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
struct Node
{
	Node* left;
	Node* right;
	int label;
	int cnt;
	int height;
	Node(int height, int cnt, int la)
	{
		this->height = height;
		left = NULL;
		right = NULL;
		this->cnt = cnt;
		this->label = la;

	}
};
class Binary_tree
{
public:
	Node* root;
	Binary_tree()
	{
		root = NULL;
	}
	void insert(int height, int pos)
	{
		root = insert(root, height, pos, pos);
	}
	void inorder(Node* root, vector<pair<int, int>> & result)
	{
		if (root == NULL)
			return;
		inorder(root->left, result);
		result.push_back(make_pair(root->height, root->label));
		inorder(root->right, result);
	}
private:
	Node* insert(Node* cur, int height, int cnt, int la)
	{
		if (cur == NULL)
		{
			return new Node(height,1,la);
		}
		else if (cnt < cur->cnt)
		{
			cur->left = insert(cur->left,height,cnt,la);
			cur->cnt++;
		}
		else
		{
			cur->right = insert(cur->right, height, cnt - cur->cnt,la);
		}
		return cur;
	}

};
bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
}
class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(),people.end(),compare);
		Binary_tree btree;
		for (int i = 0; i < people.size(); i++)
		{
			btree.insert(people[i].first, people[i].second);
		}
		vector<pair<int, int>> res;
		btree.inorder(btree.root,res);
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

