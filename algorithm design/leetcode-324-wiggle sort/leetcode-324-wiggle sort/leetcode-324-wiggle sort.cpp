// leetcode-324-wiggle sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();

		// Find a median.
		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;

		// Index-rewiring.
#define A(i) nums[(1+2*(i)) % (n|1)]

		// 3-way-partition-to-wiggly in O(n) time with O(1) space.
		int i = 0, j = 0, k = n - 1;
		while (j <= k) {
			if (A(j) > mid)
				swap(A(i++), A(j++));
			else if (A(j) < mid)
				swap(A(j), A(k--));
			else
				j++;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(2);
	ve.push_back(6);
	ve.push_back(7);
	ve.push_back(1);
	ve.push_back(4);
	ve.push_back(3);
	Solution s;
	s.wiggleSort(ve);
	return 0;
}

