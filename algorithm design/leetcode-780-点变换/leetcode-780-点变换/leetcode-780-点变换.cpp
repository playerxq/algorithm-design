// leetcode-780-µã±ä»».cpp : Defines the entry point for the console application.
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
#include <xfunctional>
using namespace std;
class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (tx >= sx && ty >= sy) {
			if (tx > ty) {
				if (sy == ty) return (tx - sx) % ty == 0;
				tx -= (tx / ty) * ty;
			}
			else {
				if (sx == tx) return (ty - sy) % tx == 0;
				ty -= (ty / tx) * tx;
			}
		}

		return false;
	}
};
int main()
{
	Solution s;
	s.reachingPoints(35,13,455955547,420098884);
    return 0;
}

