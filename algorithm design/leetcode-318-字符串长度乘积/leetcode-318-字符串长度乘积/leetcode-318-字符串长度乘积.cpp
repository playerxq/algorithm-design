// leetcode-318-字符串长度乘积.cpp : 定义控制台应用程序的入口点。
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

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int n = words.size();
		vector<int> num(n+1,0);
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int len = words[i].length();
			for (int k = 0; k < len; k++)
				num[i] |= (1 << (words[i][k] - 'a'));
			for (int j = i - 1; j >= 0; j--)
			{
				if (j >= 0 && ((num[i] & num[j])==0))
				{
					int t = len*(words[j].length());
					ans = max(ans, t);
				}
			}
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

