// leetcode-373-优先队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
//#include <priority_queue>
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
	struct com
	{
		bool operator()(pair<int, int>& a, pair<int, int>& b)
		{
			return (a.first + a.second) < (b.first+b.second);
		}
	};
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> res;
		priority_queue<pair<int, int>, vector<pair<int, int>>, com> pi;
		for (int i = 0; i < min(k, (int)nums1.size()); i++)
		{
			for (int j = 0; j < min(k, (int)nums2.size()); j++)
			{
				if (pi.size() < k)
					pi.push(make_pair(nums1[i],nums2[j]));
				else if (nums1[i] + nums2[j] < pi.top().first + pi.top().second)
				{
					pi.push(make_pair(nums1[i], nums2[j]));
					pi.pop();
				}
			}
		}
		while (!pi.empty())
		{
			res.push_back(pi.top());
			pi.pop();
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

