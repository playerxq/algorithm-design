// uva-10382-water grass.cpp : 定义控制台应用程序的入口点。
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
int n,l,w;
typedef struct circle
{
	int pos;
	int r;
	int L;
	int R;
} cir;
cir a[10001];
int cnt;
int k;
int cmp(const void* _i, const void* _j)
{
	cir* i = (cir*)_i;
	cir* j = (cir*)_j;
	return i->L-j->L;
}
double get_start(int index)
{
	double temp = a[index].r*a[index].r-(double)w*(double)w/4.0;
	return a[index].pos+sqrt((double)temp);
}
double get_left(int index)
{
	double temp = a[index].r*a[index].r-(double)w*(double)w/4.0;
	return a[index].pos-sqrt((double)temp);
}
const double eps = 1e-9;  
int dfs(int cur,double start)
{
	if(start>=l)
		return 1;
	double maxn = -1;
	int max_index = -1;
	int ok = 0;
	for(int i = cur;i<k;i++)//搜索剩余的矩形区域
	{
		if(a[i].L-start<eps)//最近的一个区域
		{
			ok = 1;
			if(a[i].R-maxn>eps)//更新最远点
			{
				maxn = a[i].R;
				max_index = i;
			}
		}
	}
	if(!ok)
		return 0;
	if(dfs(cur+1,a[max_index].R))
	{
		cnt++;
		return 1;
	}
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&n,&l,&w)!=EOF)
	{
		int temp_r,temp_pos;
		k = 0;
		cnt = 0;
		memset(a,0,sizeof(a));
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&temp_pos,&temp_r);
			if(2*temp_r<=w)
				continue;
			double _dis = sqrt((double)temp_r * temp_r -(double)w * w / 4.0);  //矩形变长
            a[k].L = temp_pos - _dis;  //矩形区域
            a[k].R = temp_pos + _dis;  
            ++k;
		}
		qsort(a,k,sizeof(a[0]),cmp);//按矩形左边界限排序
		if(a[0].L>0)
			printf("-1\n");
		else
		{
			if(dfs(0,0))
				printf("%d\n",cnt);
			else
				printf("-1\n");
		}
	}
	return 0;
}

