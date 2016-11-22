// leetcode-25-链表k组反转.cpp : 定义控制台应用程序的入口点。
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
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
			return head;
		ListNode dummy(0),*pre(&dummy),*st(&dummy),*ed(NULL);
		dummy.next = head;
		int t = k-1;
		ed = head;
		st = ed;
		while(st)
		{
			while(st->next&&t)
			{
				st = st->next;
				t--;
			}
			if(t)
				break;
			ListNode* nn = ed;
			ListNode* nx = ed->next;
			while(nx!=st)
			{
				ListNode* tmp = nx->next;
				nx->next=nn;
				nn = nx;
				nx = tmp;
			}
			ListNode* tmp2 = st->next;
			st->next = nn;
			pre->next = st;
			ed->next = tmp2;
			t = k-1;
			pre = ed;
			ed = ed->next;
			st = ed;
		}
		return dummy.next;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	ListNode a(1),b(2),c(3),d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	Solution s;
	s.reverseKGroup(&a,2);
}

