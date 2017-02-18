// leetcode-386-字典序输出1-n.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:	
	vector<int> lexicalOrder(int n) {
		if (n <= 0) return{};
		vector<int> res(n, 0);
		res[0] = 1;
		for (int i = 1; i < n; i++)
		{
			if (res[i - 1] * 10 <= n)
				res[i] = res[i - 1] * 10;
			else if (res[i - 1] + 1 <= n)
			{
				int num = res[i-1];
				while (num&&num % 10 == 9)
					num /= 10;
				res[i] = num+1;
			}
			else if (res[i - 1] == n)
			{
				int num = res[i - 1] / 10;
				while (num&&num % 10 == 9)
					num /= 10;
				res[i] = num + 1;
			}
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.lexicalOrder(18);
	return 0;
}

