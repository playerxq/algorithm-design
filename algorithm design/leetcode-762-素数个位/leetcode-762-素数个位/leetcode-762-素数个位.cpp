// leetcode-762-ËØÊý¸öÎ».cpp : Defines the entry point for the console application.
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
	bool is_prime(int a)
	{
		int b = sqrt(a);
		for (int i = 2; i <= b; i++)
		{
			if (a%i == 0)
				return false;
		}
		return true;
	}
	int countPrimeSetBits(int L, int R) {
		int cnt = 0;
		for (int i = L; i <= R; i++)
		{
			int sum = 0;
			int t = i;
			while (t)
			{
				if (t & 1)
					sum++;
				t >>= 1;
			}
			if (sum == 1 || sum == 0)
				continue;
			if (is_prime(sum))
				cnt++;
		}
		return cnt;
	}
};


int main()
{
	Solution s;
	s.countPrimeSetBits(10,15);
    return 0;
}

