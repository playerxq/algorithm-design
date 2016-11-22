// uva11292-dragon of loowater.cpp : 定义控制台应用程序的入口点。
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
int n,m;
int a[20001];
int b[20001];
int cmp(const void* a, const void* b)
{
	return *((int*)a)-*((int*)b);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0&&m==0)
			break;
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i = 0;i<m;i++)
			scanf("%d",&b[i]);
		qsort(a,n,sizeof(int),cmp);
		qsort(b,m,sizeof(int),cmp);
		int index = 0;
		int ok = 1;
		int sum =0;

		for(int i = 0;i<n;i++)
		{
			if(m-index<n-i)
			{
				ok = 0;
				break;
			}
			for(int j = index;j<m;j++)
			{
				if(b[j]>=a[i])
				{
					sum+=b[j];
					index = j+1;
					break;
				}
			}
		}
		if(ok)
			printf("%d\n",sum);
		else
			printf("Loowater is doomed!\n");
	}
}

