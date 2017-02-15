// leetcode-372-a^b mod 1337.cpp : 定义控制台应用程序的入口点。
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
	int superPow(int a, vector<int>& b) {
		long long tmp = 1;
		if (b.size() == 0)
			return a % 1337;
		for (int i = 0; i <b.size(); i++)
		{
			long long tmp2 = tmp;
			for (int j = 1; j < 10; j++)
				tmp = (tmp*tmp2) % 1337;
			tmp2 = 1;
			for (int k = 1; k <= b[i]; k++)
			{
				tmp2 = (tmp2*a) % 1337;
			}
			tmp = (tmp2*tmp)%1337;
		}
		return tmp;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(1);
	ve.push_back(0);
	Solution s;
	s.superPow(2, ve);
	return 0;
}

