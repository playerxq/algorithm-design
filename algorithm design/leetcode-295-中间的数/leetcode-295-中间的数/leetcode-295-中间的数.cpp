// leetcode-295-中间的数.cpp : 定义控制台应用程序的入口点。
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

class MedianFinder {
	priority_queue<long> small, large;
public:

	void addNum(int num) {
		small.push(num);
		large.push(-small.top());
		small.pop();
		if (small.size() < large.size()) {
			small.push(-large.top());
			large.pop();
		}
	}

	double findMedian() {
		return small.size() > large.size()
			? small.top()
			: (small.top() - large.top()) / 2.0;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	MedianFinder mf;
	mf.addNum(1);
	mf.addNum(2);
	mf.addNum(4);
	return 0;
}

