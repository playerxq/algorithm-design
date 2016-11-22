// hdu-1222-公约数.cpp : 定义控制台应用程序的入口点。
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
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		int d = gcd(n,m);
		if(d==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

