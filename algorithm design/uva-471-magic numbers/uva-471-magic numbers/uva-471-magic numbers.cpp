// uva-471-magic numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
vector<long long> sum;
char vis[11];
void cal(long long cnt)
{
	sum.push_back(cnt);
	for(long long i = 0;i<=9;i++)
	{
		if(vis[i]=='1')
			continue;
		vis[i]='1';
		cal(cnt*10+i);
		vis[i]='0';
	}
}
int check(long long num)
{
	int tmp[10];
	memset(tmp,0,sizeof(tmp));
	while(num)
	{
		int t = num%10;
		num/=10;
		if(tmp[t])
			return 0;
		tmp[t]=1;
	}
	return 1;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	for(long long i = 1;i<=9;i++)
	{
		vis[i]='1';
		cal(i);
		vis[i]='0';
	}
	int t;
	long long n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		set<long long> ans;
		for(long long i = 0;i<sum.size();i++)
		{
			if(sum[i]%n==0)
			{
				if(check(sum[i]/n))
					ans.insert(sum[i]/n);
			}
		}
		set<long long>::iterator it;
		for(it = ans.begin();it!=ans.end();it++)
		{
			long long p = *it;
			printf("%lld / %lld = %lld\n",n*p,p,n);
		}
		if(t)
			printf("\n");
	}
}

