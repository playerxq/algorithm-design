// leetcode-2.cpp : 定义控制台应用程序的入口点。
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* res = NULL;
        ListNode* pre = res;
        while(l1!=NULL&&l2!=NULL)
        {
            int vv = l1->val+l2->val+c;
            int x = vv%10;
            c = vv/10;
            ListNode* nn = new ListNode(x);
            if(res==NULL)
            {
                res = nn;
                pre = res;
            }
            else
            {
                pre->next = nn;
                pre = pre->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            int vv = l1->val+c;
            int x = vv%10;
            c = vv/10;
            ListNode* nn = new ListNode(x);
            if(res==NULL)
            {
                res = nn;
                pre = res;
            }
            else
            {
                pre->next = nn;
                pre = pre->next;
            }
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            int vv = l2->val+c;
            int x = vv%10;
            c = vv/10;
            ListNode* nn = new ListNode(x);
            if(res==NULL)
            {
                res = nn;
                pre = res;
            }
            else
            {
                pre->next = nn;
                pre = pre->next;
            }
            l2 = l2->next;
        }
        return res;
    }
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int c1 = 0;
		int c2 = 0;
		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		if (cur1 == NULL)
			return cur2;
		if (cur2 == NULL)
			return cur1;
		while (cur1 != NULL)
		{
			c1++;
			cur1 = cur1->next;
		}
		while (cur2 != NULL)
		{
			c2++;
			cur2 = cur2->next;
		}
		ListNode* res;
		ListNode* pre=NULL;
		int c = max(c1, c2) - min(c1,c2);
		cur1 = l1;
		cur2 = l2;
		while (c)
		{
			int x = c1 > c2 ? cur1->val : cur2->val;
			ListNode* nn = new ListNode(x);
			if (pre == NULL)
			{
				pre = nn;
				res = pre;
			}
			else
			{
				pre->next = nn;
				pre = pre->next;
			}
			if (c1 > c2)
				cur1 = cur1->next;
			else
				cur2 = cur2->next;
			c--;
		}
		while (cur1 != NULL)
		{
			int x = cur1->val + cur2->val;
			ListNode* nn = new ListNode(x);
			if (pre == NULL)
			{
				pre = nn;
				res = pre;
			}
			else
			{
				pre->next = nn;
				pre = pre->next;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		ListNode* cur = res;
		ListNode* nx = cur->next;
		cur->next = NULL;
		while (cur != pre)
		{
			ListNode* nnx = nx->next;
			nx->next = cur;
			cur = nx;
			nx = nnx;
		}
		int cc = 0;
		while (cur != NULL)
		{
			int x = (cur->val + cc);
			cur->val = x % 10;
			cc = x / 10;
			cur = cur->next;
		}
		while (cc)
		{
			ListNode* nn = new ListNode(cc%10);
			cc /= 10;
			res->next = nn;
			res = res->next;
		}
		cur = pre;
		nx = cur->next;
		cur->next = NULL;
		while (cur != res)
		{
			ListNode* nnx = nx->next;
			nx->next = cur;
			cur = nx;
			nx = nnx;
		}
		return res;
	}
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	struct ListNode a(7),b(2),c(4),z(3);
	struct ListNode d(5),e(6),f(4);
	a.next = &b;
	b.next = &c;
	c.next = &z;
	d.next = &e;
	e.next = &f;
	ListNode* res = s.addTwoNumbers(&a,&d);
	while(res!=NULL)
	{
		printf("%d-",res->val);
		res = res->next;
	}
	getchar();
}

