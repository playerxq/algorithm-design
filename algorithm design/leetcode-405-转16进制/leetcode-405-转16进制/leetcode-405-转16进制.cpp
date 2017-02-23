// leetcode-405-转16进制.cpp : 定义控制台应用程序的入口点。
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
	string toHex(int num) {
		if (num == 0)
			return "0";
		string res;
		vector<int> cnt(32, 0);
		
		if (num>0)
		{
			for (int i = 0; i < 32; i++)
			{
				cnt[i] = ((num & (1 << i)) ? 1 : 0);
			}
			int i = 31;
			int tmp = 0;
			int c = 0;
			while (i >= 0)
			{
				tmp *= 2;
				tmp += cnt[i];
				i--;
				c++;
				if (c == 4)
				{
					c = 0;
					if (tmp < 10)
					{
						res += '0' + tmp;
					}
					else
					{
						res += 'a' + tmp - 10;
					}
					tmp = 0;
				}
			}
			while (!res.empty() && res[0] == '0') res.erase(res.begin());
		}
		else
		{
			num = -1 * num;
			for (int i = 0; i < 32; i++)
			{
				cnt[i] = ((num & (1 << i)) ? 1 : 0);
			}
			for (int i = 0; i < 32; i++)
			{
				cnt[i] = 1-cnt[i];
			}
			int i = 0;
			while (i < 32 && cnt[i] == 1)
			{
				cnt[i] = 0;
				i++;
			}
			cnt[i] = 1;
			i = 31;
			int tmp = 0;
			int c = 0;
			while (i >= 0)
			{
				tmp *= 2;
				tmp += cnt[i];
				i--;
				c++;
				if (c == 4)
				{
					c = 0;
					if (tmp < 10)
					{
						res += '0' + tmp;
					}
					else
					{
						res += 'a' + tmp - 10;
					}
					tmp = 0;
				}
			}
			while (!res.empty() && res[0] == '0') res.erase(res.begin());
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.toHex(-1);
	return 0;
}

