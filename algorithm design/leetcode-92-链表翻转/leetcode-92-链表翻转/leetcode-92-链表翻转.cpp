// leetcode-92-链表翻转.cpp : 定义控制台应用程序的入口点。
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dump(0);
		dump.next = head;
		ListNode* dump_ptr = &dump;
		int cnt = 1;
		ListNode* cur = head;
		ListNode* pre = dump_ptr;
		ListNode* nn = head;
		ListNode* pp;
		while(cur!=NULL&&cnt<m)
		{
			pre = cur;
			cur = cur->next;
			cnt++;
		}
		nn = cur->next;
		pp = cur;
		while(nn!=NULL&&cnt<n)
		{
			ListNode* tt = nn->next;
			nn->next = pp;
			pp = nn;
			nn = tt;
			cnt++;
		}
		pre->next = pp;
		cur->next = nn;
		return dump_ptr->next;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

