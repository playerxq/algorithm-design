// leetcode-421-O(n)求异或.cpp : 定义控制台应用程序的入口点。
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
int a[10];
typedef struct Node Node;
struct Node
{
	struct Node* next[2];
};
struct Node* root;
void build_trie(Node* root, int s)
{
	struct Node* temp = root;
	for(int i = 30;i>=0;i--)
	{
		int bit = (s&(1<<i));
		int flag = bit==0?0:1;
		if(temp->next[flag]==0)
		{
			temp->next[flag]=new Node;
			temp->next[flag]->next[0]=temp->next[flag]->next[1]=0;
		}
		temp = temp->next[flag];
	}
}
int fff(Node* root, int s)
{
	int res = 0;
	struct Node* temp = root;
	for(int i = 30;i>=0;i--)
	{
		int bit = s&(1<<i);
		int flag = bit==0?0:1;
		if(temp->next[1-flag]==0)
		{
			temp = temp->next[flag];
			res += flag<<i;
		}
		else
		{
			temp = temp->next[1-flag];
			res += (1-flag)<<i;
		}
	}
	return res^s;
}
int findMaximumXOR(int* nums, int numsSize) {
   if(numsSize==0)
	   return 0;
   else if(numsSize==2)
	   return nums[0]^nums[1];
   else
   {
	   int res = -1;
	   Node* root = new Node();
	   root->next[0] = root->next[1]=0;
	   for(int i = 0;i<numsSize;i++)
	   {
		   build_trie(root, nums[i]);
	   }
	   for(int i = 0;i<numsSize;i++)
	   {
		   int tt = fff(root, nums[i]);
		   if(tt>res)
			   res = tt;
	   }
	   return res;
   }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int r = findMaximumXOR(a,n);
	printf("%d",r);
}

