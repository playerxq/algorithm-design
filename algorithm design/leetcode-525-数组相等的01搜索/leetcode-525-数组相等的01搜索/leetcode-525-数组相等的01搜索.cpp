// leetcode-525-������ȵ�01����.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int findMaxLength(vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return 0;
		int cnt = 0;
		int res = 0;
		vector<int> sum(2*n+1,0);
		int balance = n;
		for (int i = 0; i < n; i++)
		{
			balance += nums[i] == 0 ? -1 : 1;
			if (balance == n) res = i + 1;
			else
			{
				if (sum[balance] != 0) res = max(res, i - sum[balance] + 1);
				else
					sum[balance] = i+1;
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

