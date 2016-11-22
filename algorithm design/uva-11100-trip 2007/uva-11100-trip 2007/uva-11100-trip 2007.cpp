// uva-11100-trip 2007.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 1000001;
int a[maxn];
int vis[maxn];
int cnt;
int maxcnt;
int n;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T = 0;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		cnt = 1;
		maxcnt = 0;
		for(int i = 0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
				cnt++;
			else
				cnt = 1;
			if(cnt>maxcnt)
				maxcnt = cnt;
		}
		if(T++)
			printf("\n");
		printf("%d\n",maxcnt);
		int i;
		cnt = 0;
		while(1)
		{
			if(cnt>=n)
				break;
			for(i = 0;i<n;i++)
				if(!vis[i])
					break;
			vis[i] = 1;
			cnt++;
			printf("%d",a[i]);
			i+=maxcnt;
			for(;i<n;i+=maxcnt)
				if(!vis[i])
				{
					printf(" %d",a[i]);
					vis[i] = 1;
					cnt++;
				}
			printf("\n");
		}
	}
	return 0;
}

