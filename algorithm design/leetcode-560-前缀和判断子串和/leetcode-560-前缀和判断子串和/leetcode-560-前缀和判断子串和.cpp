// leetcode-560-前缀和判断子串和.cpp : 定义控制台应用程序的入口点。
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
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		int sum = 0;
		m[0] = 1;
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (m.find(sum - k) != m.end())
				res += m[sum-k];
			m[sum]++;
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

