// leetcode-848-×Ö·û´®Ìæ»».cpp : Defines the entry point for the console application.
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
	char shift_char(char c, unsigned long s)
	{
		s = s % 26;
		if (c + s > 'z')
			return 'a' + c + s - 'z' - 1;
		return c + s;
	}
	string shiftingLetters(string S, vector<int>& shifts) {
		string res;
		int len = S.size();
		unsigned long sum = 0;
		for (int i = 0; i < len; i++)
			sum += shifts[i];
		for (int i = 0; i < len; i++)
		{
			char t = shift_char(S[i], sum);
			res += t;
			sum -= shifts[i];
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> ve = {3,5,9};
	s.shiftingLetters("abc",ve);
    return 0;
}

