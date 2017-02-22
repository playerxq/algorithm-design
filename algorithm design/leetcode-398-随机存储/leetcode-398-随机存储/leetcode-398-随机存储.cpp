// leetcode-398-����洢.cpp : �������̨Ӧ�ó������ڵ㡣
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
	vector<int> ve;
	Solution(vector<int> nums) {
		ve = nums;
	}

	int pick(int target) {
		int cnt = 0;
		int cur = -1;
		for (int i = 0; i < ve.size(); i++)
		{
			if (target != ve[i])
				continue;
			if (cnt == 0)
			{
				cur = i;
				cnt++;
			}
			else
			{
				cnt++;
				int t = rand() % cnt;
				if (t == 0)
					cur = i;
			}
		}
		return cur;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

