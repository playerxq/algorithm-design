// leetcode-554-hash.cpp : 定义控制台应用程序的入口点。
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
	int leastBricks(vector<vector<int>>& wall) {
		int n = wall.size();
		int w = 0;
		for (int i = 0; i < wall[0].size(); i++)
			w += wall[0][i];
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			int now = wall[i][0];
			for (int j = 1; j < wall[i].size(); j++)
			{
				++m[now];
				now += wall[i][j];
			}
		}
		int ans = n;
		for (auto it = m.begin(); it != m.end(); ++it)
			if (it->first != 0 && it->first != w)
				ans = min(ans, n - it->second);
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

