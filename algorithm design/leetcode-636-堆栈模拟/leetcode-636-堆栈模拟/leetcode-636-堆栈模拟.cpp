// leetcode-636-¶ÑÕ»Ä£Äâ.cpp : Defines the entry point for the console application.
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
struct Log {
	int id;
	string status;
	int timestamp;
};
class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> times(n,0);
		stack<Log> st;
		for (int i = 0; i < logs.size(); i++)
		{
			stringstream ss(logs[i]);
			string t1, t2, t3;
			getline(ss,t1,':');
			getline(ss, t2, ':');
			getline(ss, t3, ':');
			Log item={stoi(t1),t2,stoi(t3)};
			if (item.status == "start")
			{
				st.push(item);
			}
			else
			{
				assert(st.top().id==item.id);
				int t_a = item.timestamp - st.top().timestamp + 1;
				times[item.id] += t_a;
				st.pop();
				if (!st.empty())
				{
					assert(st.top().status=="start");
					times[st.top().id] -= t_a;
				}
			}
		}
		return times;
	}
};
int main()
{
    return 0;
}

