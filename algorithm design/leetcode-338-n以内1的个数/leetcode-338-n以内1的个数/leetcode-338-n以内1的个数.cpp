// leetcode-338-n以内1的个数.cpp : 定义控制台应用程序的入口点。
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
	vector<int> countBits(int num) {
		vector<int> res;
		res.push_back(0);
		if (num == 0)
		{
			return res;
		}
		if (num >= 1)
		{
			res.push_back(1);
			if (num==1)
				return res;
		}
		int i = 2;
		while (i <= num)
		{
			int st = i;
			int ed = 2 * i - 1;
			i = ed + 1;
			if (ed > num)
				ed = num;
			int k = 1;
			for (int j = st; j <= ed; j++)
			{
				if (j % 2 == 0)
				{
					int t = j&(j-1);
					int tmp = res[t];
					res.push_back(tmp+1);
					k = res.back();
				}
				else
					res.push_back(++k);
			}
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.countBits(16);
	return 0;
}

