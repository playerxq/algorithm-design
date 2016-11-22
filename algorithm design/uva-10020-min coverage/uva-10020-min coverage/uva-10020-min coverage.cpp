// uva-10020-min coverage.cpp : 定义控制台应用程序的入口点。
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
int M;
int res_index;
int res[100001];
typedef struct point
{
	int L,R;
	int L_o,R_o;
} po;
po seg[100001];
int cmp(const void* _a, const void* _b)
{
	po* a = (po*)_a;
	po* b = (po*)_b;
	if(a->L<b->L)
		return -1;
	else if(a->L>b->L)
		return 1;
	else
		return 0;
}
int ok;
int dfs(int cur,int start,int len)
{
	if(start>=M)
		return 1;
	int maxn = -1;
	int max_index = -1;
	int ok = 0;
	for(int i = cur;i<len;i++)
	{
		if(seg[i].L<=start)
		{
			seg[i].L=start;
			if(seg[i].L>seg[i].R)
				continue;
			ok = 1;
			if(seg[i].R>maxn)
			{
				maxn = seg[i].R;
				max_index = i;
			}
		}
	}
	if(!ok)
		return 0;
	res[res_index++] = max_index;
	if(dfs(cur+1,seg[max_index].R,len))
		return 1;
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&M);
		memset(seg,0,sizeof(seg));
		memset(res,0,sizeof(res));
		int i = 0;
		int max_R = 0;
		int L,R;
		while(scanf("%d%d",&L,&R))
		{
			if(L==0&&R==0)
				break;
			seg[i].L_o = L;
			seg[i].R_o = R;
			if(L<0)
				L = 0;
			if(R>M)
				R = M;
			seg[i].L = L;
			seg[i++].R = R;
			if(L>R)
			{
				i--;
				continue;
			}
			if(max_R<R)
				max_R = R;
		}
		qsort(seg,i,sizeof(seg[0]),cmp);
		if(seg[0].L>0)
			printf("0\n");
		else if(max_R<M)
			printf("0\n");
		else
		{
			res_index = 0;
			int r = dfs(0,0,i);
			if(!r)
				printf("0\n");
			else
			{
				printf("%d\n",res_index);
				for(int j = 0;j<res_index;j++)
					printf("%d %d\n",seg[res[j]].L_o,seg[res[j]].R_o);
			}
		}
		if(T)
			printf("\n");
	}
	return 0;
}
