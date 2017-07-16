// leetcode-644-数组最大平均数.cpp : Defines the entry point for the console application.
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
	double findMaxAverage(vector<int>& nums, int k) {
		vector<double> sum(nums.size()-k+1,0);
		for (int i = 0; i < k; i++)
			sum[0] += nums[i];
		double ans = sum[0] / k;
		for (int i = k; i < nums.size(); i++)
		{
			sum[i - k + 1] = sum[i - k] + nums[i];
			double temp = sum[i - k + 1];
			if (temp > ans*(i + 1))
				ans = temp / (i+1);
			for (int j = 0; j <= i - k; j++)
			{
				temp -= nums[j];
				if (temp > ans*(i - j))
				{
					ans = temp / (i-j);
				}
			}
		}
		return ans;
	}
};
int main()
{
    return 0;
}

