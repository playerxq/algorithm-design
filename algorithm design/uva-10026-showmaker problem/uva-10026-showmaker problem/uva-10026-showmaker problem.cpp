// uva-10026-showmaker problem.cpp : 定义控制台应用程序的入口点。
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

int day,pay;
typedef struct per_pay
{
	int day;
	int pay;
	int id;
} per;
per a[1001];
void swap_s(int i, int j)
{
	per temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int cmp(int _p, int _q)  
{  
    per *p = (per *)&a[_p];  
    per *q = (per *)&a[_q];  
    int ans;  
  
	ans = p->pay* q->day - q->pay* p->day;  
  
    if (ans > 0)  
        return -1;  
    else if (ans < 0)  
      return 1;  
  
	return p->id-q->id;  
} 
int partion(int l,int r)
{
	int i = l-1;
	for(int j = l;j<r;j++)
	{
		if(cmp(j,r-1)<0)
		{
			i++;
			swap_s(i,j);
		}
	}
	swap_s(i+1,r-1);
	return i+1;//返回众多中卫数中第一个索引
}
void quick_sort(int l,int r)
{
	if(l<r)
	{
		int q = partion(l,r);
		quick_sort(l,q);
		quick_sort(q+1,r);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	int n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&(a[i].day),&(a[i].pay));
			a[i].id = i;
		}
		quick_sort(0,n);
		for(int i = 0;i<n;i++)
		{
			printf("%d",a[i].id+1);
			if(i<n-1)
				printf(" ");
			else
				printf("\n");
		}
		if(T)
			printf("\n");
	}
	return 0;
}
