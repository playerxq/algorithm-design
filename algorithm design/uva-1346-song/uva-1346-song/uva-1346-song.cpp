// uva-1346-song.cpp : 定义控制台应用程序的入口点。
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
typedef struct Song
{
	int id;
	int len;
	double f;
}song;
int cmp(const void* _a, const void* _b)
{
	song* a = (song*)_a;
	song* b = (song*)_b;
	if(b->f*a->len<a->f*b->len)
		return -1;
	return 1;
}
song sss[80000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<n;i++)
		{
			int id,len;
			double f;
			scanf("%d%d%lf",&id,&len,&f);
			song ss;
			ss.f=f;
			ss.id=id;
			ss.len=len;
			sss[i]=ss;
		}
		qsort(sss,n,sizeof(sss[0]),cmp);
		int po;
		scanf("%d",&po);
		printf("%d\n",sss[po-1].id);
	}
}

