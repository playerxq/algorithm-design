// uva11300-spreading wealth 中位数.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int maxn = 1000000+10;
long long A[maxn],C[maxn],tot,M;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n;
	while(scanf("%d",&n)==1)
	{
		tot=0;
		for(int i = 1;i<=n;i++)
		{
			scanf("%lld",&A[i]);
			tot+=A[i];
		}
		M=tot/n;
		C[0]=0;
		for(int i = 1;i<n;i++)
		{
			C[i]=C[i-1]+A[i]-M;
		}
		sort(C,C+n);
		long long x1=C[n/2];
		long long ans = 0;
		for(int i = 0;i<n;i++)
			ans+=(long long)abs((long)(x1-C[i]));
		printf("%lld\n",ans);
	}
}

