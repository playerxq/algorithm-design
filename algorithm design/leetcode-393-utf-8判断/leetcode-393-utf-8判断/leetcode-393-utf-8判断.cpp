// leetcode-393-utf-8判断.cpp : 定义控制台应用程序的入口点。
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
	bool validUtf8(vector<int>& data) {
		int n = data.size();
		if (!n)
			return false;
		if (n == 1)
		{
			if (data[0] <= 127)
				return true;
			return false;
		}
		int cnt = 0;
		int fi = data[0];
		int i = 0;
		while (i < n)
		{
			fi = data[i];
			for (int k = 7; k >= 0; k--)
			{
				if (fi&(1 << k))
					cnt++;
				else
					break;
			}
			if (cnt == 0)
			{
				i++;
				continue;
			}
			if (cnt == 1||cnt>=5)
				return false;
			int j = i + cnt - 1;
			if (j >= n)
				return false;
			for (int k = i+1; k <= j; k++)
			{
				int t = data[k];
				int a = (t&128);
				int b = (t&64);
				if ((data[k] & (128)) && ((data[k] & (64)) == 0))
					continue;
				else
					return false;
			}
			i = j + 1;
			cnt = 0;
		}
		return true;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(250);
	ve.push_back(145);
	ve.push_back(145);
	ve.push_back(145);
	ve.push_back(145);
	Solution s;
	s.validUtf8(ve);
	return 0;
}

