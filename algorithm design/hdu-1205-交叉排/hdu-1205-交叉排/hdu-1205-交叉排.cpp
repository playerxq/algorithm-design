// hdu-1205-交叉排.cpp : 定义控制台应用程序的入口点。
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
int n;
long long sum;
int a[1000001];
int cmp(const void* _a, const void* _b)
{
	int* a = (int*) _a;
	int* b = (int*) _b;
	return (*b)-(*a);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		qsort(a,n,sizeof(int),cmp);
		if(a[0]>(sum+1)/2)
			printf("No\n");
		else
			printf("Yes\n");
	}
}

