// uva-108-max sum.cpp : 定义控制台应用程序的入口点。
//

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
int a[101][101];
int b[101];
int n;
int one_D()
{
	int maxn = 0;
	int start = 0;
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		sum+=b[i];
		if(sum<0)
			sum = 0;
		if(sum>maxn)
			maxn = sum;
	}
	return maxn;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int maxn = 0;
	for(int i = 0;i<n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j = i;j<n;j++)
		{
			for(int k = 0;k<n;k++)
			{
				b[k]+=a[k][j];
			}
			int res = one_D();
			if(res>maxn)
				maxn = res;
		}
	}
	printf("%d\n",maxn);
	return 0;
}

