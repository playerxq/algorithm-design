// leetcode-496-503-找到数字或环形数组中指定数字的下一个最大元素.cpp : 定义控制台应用程序的入口点。
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
//数组
class Solution1 {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> n;
		unordered_map<int, int> mm;
		for (auto i : nums)
		{
			while (n.size() && n.top()<i)
			{
				mm[n.top()] = i;
				n.pop();
			}
			n.push(i);
		}
		vector<int> res;
		for (auto i : findNums)
		{
			if (mm.count(i))
				res.push_back(mm[i]);
			else
				res.push_back(-1);
		}
		return res;
	}
};
//环形
class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int nn = nums.size();
		vector<int> res(nn,-1);
		stack<int> n;
		for (int i = 0; i < 2 * nn; i++)
		{
			while (n.size() && nums[n.top()] < nums[i%nn])
			{
				if (res[n.top()] == -1)
					res[n.top()] = nums[i%nn];
				n.pop();
			}
			if (n.size() && n.top() == i%nn)
			{
				res[n.top()] = -1;
				break;
			}
			n.push(i%nn);
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> ve = {1,2,1};
	s.nextGreaterElements(ve);
	return 0;
}

