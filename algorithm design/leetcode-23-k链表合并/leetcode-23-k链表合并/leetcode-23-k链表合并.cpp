// leetcode-23-k链表合并.cpp : 定义控制台应用程序的入口点。
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size()==0)
			return NULL;
		auto cmp = [](pair<ListNode *, int> n1, pair<ListNode *, int> n2) {
            return n1.first->val > n2.first->val;
        };
		priority_queue<pair<ListNode *, int>, vector<pair<ListNode *, int>>, decltype(cmp)> pq(cmp);
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) pq.push({lists[i], i});
        }
		ListNode pre_head(0);
        ListNode * cur = &pre_head;
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            cur->next = p.first;
            cur = cur->next;
            lists[p.second] = lists[p.second]->next;
            if(lists[p.second] != NULL) pq.push({lists[p.second], p.second});
        }
        return pre_head.next;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

