// uva-524-prime ring.cpp : 定义控制台应用程序的入口点。
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
int prime[32];
int visit[18];
int queue[18];
int size[18];
int ans[18][100000][18];
void dfs(int d, int n)
{
	if(d==n&&!prime[queue[d-1]+1])
	{
		for(int i = 1;i<n;i++)
		{
			ans[n][size[n]][i]=queue[i];
		}
		size[n]++;
		return;
	}
	for(int i = d%2+1;i<=n;i+=2)
	{
		if(!visit[i]&&!prime[queue[d-1]+i])
		{
			visit[i]=1;
			queue[d]=i;
			dfs(d+1,n);
			visit[i]=0;
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	memset(prime,0,sizeof(prime));
	prime[0]=prime[1]=1;
	for(int i = 2;i<32;i++)
	{
		if(!prime[i])
		{
			for(int j = 2*i;j<32;j+=i)
				prime[j]=1;
		}
	}
	memset(visit,0,sizeof(visit));
	visit[1]=1;
	queue[0]=1;
	memset(size,0,sizeof(size));
	for(int i = 2;i<=16;i+=2)
		dfs(1,i);
	int n,m,t=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(t++) printf("\n");
		printf("Case %d:\n",t);
		m = size[n];
		for(int i = 0;i<m;i++)
		{
			printf("1");
			for(int j = 1;j<n;j++)
			{
				printf(" %d",ans[n][i][j]);
			}
			printf("\n");
		}
	}
}

