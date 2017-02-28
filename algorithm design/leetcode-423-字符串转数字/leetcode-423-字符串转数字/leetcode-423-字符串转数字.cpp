// leetcode-423-�ַ���ת����.cpp : �������̨Ӧ�ó������ڵ㡣
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	string originalDigits(string s) {
		vector<int> a(10, 0);
		vector<int> alpha(128, 0);
		for (char c : s)
			alpha[c]++;
		a[0] = alpha['z'];
		a[2] = alpha['w'];
		a[4] = alpha['u'];
		a[6] = alpha['x'];
		a[8] = alpha['g'];
		a[3] = alpha['h'] - a[8];
		a[5] = alpha['f'] - a[4];
		a[7] = alpha['v'] - a[5];
		a[1] = alpha['o'] - a[0] - a[2] - a[4];
		a[9] = alpha['i'] - a[5] - a[6] - a[8];
		string ans;
		for (int i = 0; i < 10; i++) {
			if (a[i] > 0)
				ans += string(a[i], '0' + i);
		}
		return ans;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

