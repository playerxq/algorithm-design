// uva-269-counting.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 100005;
const int maxm = 15;
int s[maxn][maxm];
int n,k,key,cnt,a[maxm];
void put(int s[])
{
	printf("(%d",s[0]);
	for(int i = 1;i<n;i++)
		printf(",%d",s[i]);
	printf(")\n");
}
bool cmp(int l[], int r[])
{
	for(int i = 0;i<n;i++)
	{
		if(l[i]!=r[i])
			return l[i]>r[i];
	}
	return false;
}
void check()
{
	int b[maxm*2];
	for(int i = 0;i<n;i++)
		b[i]=b[i+n]=a[i];
	for(int i = 0;i<n;i++)
		if(b[i]==a[0]&&cmp(b+i,a))
			return;
	for(int i = 0;i<2*n;i++)
		b[i]=-b[i];
	for(int i = 0;i<n;i++)
		if(b[i]==a[0]&&cmp(b+i,a))
			return;
	for(int i = 0;i<n;i++)
		swap(b[i],b[2*n-1-i]);
	for(int i = 0;i<n;i++)
		if(b[i]==a[0]&&cmp(b+i,a))
			return;
	for(int i = 0;i<2*n;i++)
		b[i]=-b[i];
	for(int i = 0;i<n;i++)
		if(b[i]==a[0]&&cmp(b+i,a))
			return;
	memcpy(s[cnt++],a,sizeof(a));
}
void dfs(int d, int sum)
{
	if(d==n)
	{
		if(sum==0)
		{
			check();
		}
		return;
	}
	if(abs(sum)>(n-d)*a[0])
		return;
	for(a[d]=-key;a[d]<key;a[d]++)
	{
		if(a[d-1]==key&&a[d]>a[1])
			return;
		dfs(d+1,sum+a[d]);
	}
	if(a[d]==key&&a[d-1]<=a[1])
		dfs(d+1,sum+a[d]);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 0;
	while(scanf("%d%d",&n,&k)==2&&n)
	{
		cnt = 1;
		for(a[0]=1;a[0]<=k;a[0]++)
		{
			key=a[0];
			dfs(1,key);
		}
		if(kase++)
			printf("\n");
		printf("%d\n",cnt);
		for(int i = 0;i<cnt;i++)
			put(s[i]);
	}
}

