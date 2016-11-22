// leetcode-7-数字倒转.cpp : 定义控制台应用程序的入口点。
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
    int reverse(int x) {
        long long r = 0,flag=0;
		if(x<=-2147483648)
			return 0;
		if(x>=2147483647)
			return 0;
        if(x<0)
            flag=1;
        x = abs(x);
        while(x)
        {
            int t = x%10;
            r = r*10+t;
			if(r>2147483647)
			{
				r = 0;
				break;
			}
			else if((-1)*r<-2147483648)
			{
				r = 0;
				break;
			}
            x/=10;
        }
        if(flag)
            r = (-1)*r;
        return r;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.reverse(-2147483648);
}

