// leetcode-611-数组中三角形个数.cpp : 定义控制台应用程序的入口点。
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
	int triangleNumber(vector<int>& nums) {
		int n = nums.size();
		int k = n - 1;
		sort(nums.begin(),nums.end());
		int cnt = 0;
		for (; k >1; k--)
		{
			int i = 0;
			int j = k - 1;
			while (i < j)
			{
				if (nums[i] + nums[j]>nums[k])
				{
					cnt += (j - i);
					j--;
				}
				else
					i++;
			}
		}
		return cnt;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

