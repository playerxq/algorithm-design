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
class Solution {
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
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	struct ListNode a(2),b(4),c(3);
	struct ListNode d(5),e(6),f(4);
	a.next = &b;
	b.next = &c;
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

