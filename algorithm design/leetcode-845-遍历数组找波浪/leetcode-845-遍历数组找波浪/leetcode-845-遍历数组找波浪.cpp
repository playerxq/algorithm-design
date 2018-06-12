// leetcode-845-±È¿˙ ˝◊È’“≤®¿À.cpp : Defines the entry point for the console application.
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
	int longestMountain(vector<int>& A) {
		if (A.size() < 3)
			return 0;
		int len = A.size();
		int mxlen = 0;
		int up = 0, dow = 0;
		for (int i = 1; i < len; i++)
		{
			if (A[i] > A[i - 1])
			{
				if (dow > 0)
					up = 0;
				dow = 0;
				up++;
			}
			else if (A[i] < A[i - 1])
			{
				dow++;
			}
			else
				up = dow = 0;
			if (up > 0 && dow > 0)
				mxlen = max(mxlen, up + dow + 1);
		}
		return mxlen;
	}
};
int main()
{
    return 0;
}

