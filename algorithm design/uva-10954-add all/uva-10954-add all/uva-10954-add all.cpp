// uva-10954-add all.cpp : 定义控制台应用程序的入口点。
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
int n;
int a[5001];
int cost;
int get_ans()
{
	int i = 0;
	cost = 0;
	while(i<n-1)
	{
		int temp=(a[i]+a[i+1]);
		int j = i+1;
		while(j<n&&a[j]<temp)
		{
			a[j-1] = a[j];
			j++;
		}
		a[j-1] = temp;
		cost+=temp;
		i++;
	}
	return cost;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		memset(a,0,sizeof(a));
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		cost = get_ans();
		printf("%d\n",cost);
	}
	return 0;
}

