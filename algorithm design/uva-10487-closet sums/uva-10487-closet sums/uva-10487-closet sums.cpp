// uva-10487-closet sums.cpp : 定义控制台应用程序的入口点。
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
int a[1001];
int b[30];
int sum[1000000+2];
int k;
void get_sum()
{
	k = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			sum[k++] = a[i]+a[j];
		}
	}
	sort(sum,sum+k);
}
int get_ans(int des)
{
	int x = 0;
	int y = k;
	if(sum[0]>=des)
		return sum[0];
	else if(sum[k-1]<=des)
		return sum[k-1];
	while(x<y)
	{
		int mid = x+(y-x)/2;
		if(sum[mid]==des)
		{
			return sum[mid];
		}
		else if(des>sum[mid])
			x = mid+1;
		else 
			y = mid;
	}
	//x==y
	int t = sum[x-1];
	if(x <k)  
	{
        t = abs(sum[x] - des) > abs(sum[k-1]- des) ? sum[k-1] : sum[x];
	}
	if(x-1>0)
	{
		t = abs(sum[x-2] - des) > abs(t - des) ? t : sum[x-2];
	}
	t = abs(sum[x-1]-des)>abs(t-des)?t:sum[x-1];
	return t;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i = 0;i<m;i++)
			scanf("%d",&b[i]);
		printf("Case %d:\n",ncase++);
		get_sum();
		for(int i = 0;i<m;i++)
		{
			int res = get_ans(b[i]);
			printf("Closest sum to %d is %d.\n",b[i],res);
		}
	}
	return 0;
}
