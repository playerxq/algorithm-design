// leetcode-477-数组汉明距离和.cpp : 定义控制台应用程序的入口点。
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
	int totalHammingDistance(vector<int>& nums) {
		int n = nums.size();
		if (n == 0||n==1)
			return 0;
		int* zeroc = new int[2];
		zeroc[0] = zeroc[1] = 0;
		int zerocnt = 0;
		int sum = 0;
		while (1)
		{
			zerocnt = 0;
			zeroc[0] = zeroc[1] = 0;
			for (int i = 0; i < n; i++)
			{
				zeroc[nums[i] % 2]++;
				nums[i] >>= 1;
				if (nums[i] == 0)
					zerocnt++;
			}
			sum += zeroc[0] * zeroc[1];
			if (zerocnt == n)
				break;
		}
		return sum;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

