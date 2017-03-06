// leetcode-480-multiset使用.cpp : 定义控制台应用程序的入口点。
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
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		multiset<int> mt;
		vector<double> res;
		for (int i = 0; i < k - 1; i++)
			mt.insert(nums[i]);
		for (int i = k - 1; i < nums.size(); i++)
		{
			mt.insert(nums[i]);
			multiset<int>::iterator itb = mt.begin();
			advance(itb,(k-1)/2);
			multiset<int>::iterator ite = mt.end();
			advance(ite,-(k+1)/2);
			double ave = ((long)(*itb) + *ite) / 2;
			res.push_back(ave);
			mt.erase(mt.find(nums[i-k+1]));
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

