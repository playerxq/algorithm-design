// leetcode-388-hash map找最长文件路径.cpp : 定义控制台应用程序的入口点。
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
	int lengthLongestPath(string input) {
		int fin = input.length();
		int ln = 1;
		int maxx = 0;
		int cnt = 0;
		bool isfile = false;
		vector<int> lev(200);
		for (int i = 0; i < fin; i++)
		{
			while (input[i] == '\t')
			{
				ln++;
				i++;
			}
			while (input[i] != '\n'&&i < fin)
			{
				if (input[i] == '.')
					isfile = true;
				++cnt;
				++i;
			}
			if (isfile)
			{
				maxx = max(maxx,lev[ln-1]+cnt);
			}
			else
			{
				lev[ln] = lev[ln - 1] + cnt + 1;
			}
			cnt = 0;
			isfile = false;
			ln = 1;
		}
		return maxx;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

