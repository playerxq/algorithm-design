// leetcode-683-查找数组中的指定间隔-ordered-set.cpp : Defines the entry point for the console application.
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
	bool hasKSlots(const vector<bool>& blooming, int k, int position)
	{
		if (position <= k && blooming.size() - 1 - position <= k) return false;//position前后不会有k个slot flower
		if (position > k)//往前搜索
		{
			int pos = position - 1;
			int cnt = 0;
			while (pos >= 0 && !blooming[pos]) {
				++cnt;
				--pos;
			}
			if (cnt == k) return true;
		}
		if (blooming.size() - 1 - position > k)//向后
		{
			int pos = position + 1;
			int cnt = 0;
			while (pos < blooming.size() && !blooming[pos]) {
				++cnt;
				++pos;
			}
			if (cnt == k) return true;
		}
		return false;
	}
	int kEmptySlots(vector<int>& flowers, int k) {
		if (flowers.empty()) return -1;
		vector<bool> blooming(flowers.size(), false);
		for (int i = 0; i < flowers.size(); ++i)//枚举每一天
		{
			int position = flowers[i] - 1;//第i天开花的位置
			blooming[position] = true;
			if (hasKSlots(blooming, k, position))//有间隔为k
				return i + 1;
		}
		return -1;
	}
};
int main()
{
    return 0;
}

