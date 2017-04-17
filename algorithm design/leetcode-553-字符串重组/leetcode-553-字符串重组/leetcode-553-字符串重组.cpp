// leetcode-553-字符串重组.cpp : 定义控制台应用程序的入口点。
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
	string optimalDivision(vector<int>& nums) {
		string res;
		int len = nums.size();
		if (len == 0)
			return res;
		res += to_string(nums[0]);
		if (len == 1)
			return res;
		if (len == 2)
			return res + "/" + to_string(nums[1]);
		res += "/(" + to_string(nums[1]);
		for (int i = 2; i < len; i++)
		{
			res += "/"+to_string(nums[i]);
		}
		res += ")";
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

