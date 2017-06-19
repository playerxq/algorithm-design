// leetcode-621-任务排序.cpp : 定义控制台应用程序的入口点。
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
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int>mp;
		int count = 0;
		for (auto e : tasks)
		{
			mp[e]++;
			count = max(count, mp[e]);
		}

		int ans = (count - 1)*(n + 1);
		for (auto e : mp) if (e.second == count) ans++;
		return max((int)tasks.size(), ans);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<char> tasks = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	Solution s;
	s.leastInterval(tasks,2);
	return 0;
}

