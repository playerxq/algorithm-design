// hdu-1207-汉诺塔.cpp : 定义控制台应用程序的入口点。
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
int step,n;
const int INF=99999999;
int f[65];
int calc(int n)
{
	if(n==0)
		return 0;
	if(n==1)
	{
		return 1;
	}
	if(f[n]!=-1)
		return f[n];
	int minx = INF;
	for(int x = 1;x<n;x++)
	{
		if(2*calc(x)+pow(2.0,n-x)-1<minx)
		{
			minx = 2*calc(x)+pow(2.0,n-x)-1;
		}
	}
	f[n]=minx;
	return f[n];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		memset(f,-1,sizeof(f));
		calc(n);
		printf("%d\n",f[n]);
	}
}

