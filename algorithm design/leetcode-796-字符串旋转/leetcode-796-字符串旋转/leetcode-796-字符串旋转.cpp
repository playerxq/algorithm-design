// leetcode-796-×Ö·û´®Ðý×ª.cpp : Defines the entry point for the console application.
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
	bool rotateString(string A, string B) {
		int len1 = A.size();
		int len2 = B.size();
		if (len1 != len2)
			return false;
		if (!len1)
			return true;
		for (int i = 0; i < len1; i++)
		{
			string temp = A.substr(1);
			temp += A[0];
			if (temp == B)
				return true;
			A = temp;
		}
		return false;
	}
};
int main()
{
	Solution s;
	s.rotateString("abcde","abced");
    return 0;
}

