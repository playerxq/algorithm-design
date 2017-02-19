// leetcode-390-交错删除.cpp : 定义控制台应用程序的入口点。
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
	int lastRemaining(int n) {
		int tmp = n;
		int rnd = 1;
		int cnt = n;
		int dif = 1;
		while (cnt != 1)
		{
			if (rnd % 2 == 1)
			{
				if (cnt % 2 == 0)
					tmp = tmp;
				else
					tmp -= dif;
				cnt = cnt / 2;
			}
			else
			{
				if ((tmp/2) % 2 == 1)
				{
					cnt = cnt / 2;
					tmp = tmp - dif;
				}
				else
				{
					cnt = cnt / 2;
					tmp = tmp - dif;
				}
			}
			rnd++;
			dif *= 2;
		}
		return tmp;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.lastRemaining(10);
	return 0;
}

