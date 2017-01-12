// leetcode-233-小于n的整数中1的个数.cpp : 定义控制台应用程序的入口点。
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
    int countDigitOne(int n) {
        long long res = 0;
		int bign = n;
		int lown = 0;
		int lowc = 1;
		int curn = 0;
		while(bign)
		{
			curn = bign%10;
			bign = bign/10;
			if(curn>1)
			{
				res+=(bign+1)*lowc;
			}
			else if(curn==1)
			{
				res+=bign*lowc;
				res+=(lown+1);
			}
			else
			{
				res+=bign*lowc;
			}
			lown = lowc*curn+lown;
			lowc*=10;
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

