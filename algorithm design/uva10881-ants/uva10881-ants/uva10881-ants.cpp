// uva10881-ants.cpp : 定义控制台应用程序的入口点。
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
const int maxn=10005;
struct Ant
{
	int id;
	int p;
	int d;
	bool operator < (const Ant& a) const
	{
		return p<a.p;
	}
} before[maxn], after[maxn];
const char dirName[][10]={"L","Turning","R"};
int order[maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int K;
	scanf("%d",&K);
	for(int kase=1;kase<=K;kase++)
	{
		int L,T,n;
		printf("Case #%d:\n",kase);
		scanf("%d%d%d",&L,&T,&n);
		for(int i = 0;i<n;i++)
		{
			int p,d;
			char c;
			scanf("%d %c",&p,&c);
			d=(c=='L'?-1:1);
			Ant bf;
			Ant af;
			bf.d=d;
			bf.p=p;
			bf.id=i;
			af.id=0;
			af.d=d;
			af.p=p+T*d;
			before[i]=bf;
			after[i]=af;//由于假设碰撞时对穿而过  必有一个蚂蚁处于p+T*d位置
		}
		sort(before,before+n);
		for(int i = 0;i<n;i++)
			order[before[i].id]=i;//起始顺序  相对始终保持不变  id号蚂蚁在起始位置中处于相对位置i号
		sort(after,after+n);//对最终位置排序  再按起始的相对位置给每个最终位置赋予id号
		for(int i = 0;i<n-1;i++)
			if(after[i].p==after[i+1].p)
				after[i].d=after[i+1].d	=0;
		for(int i = 0;i<n;i++)//遍历id号
		{
			int a = order[i];//i号蚂蚁在起始位置中为a号处 在运动过程中 i号蚂蚁始终处于所有蚂蚁相对位置的a号处
			if(after[a].p<0||after[a].p>L)//在after[]中 a号处的位置p就是id=i号蚂蚁的位置
				printf("Fell off\n");
			else
				printf("%d %s\n",after[a].p,dirName[after[a].d+1]);//d包含-1 从+1开始计算
		}
		printf("\n");
	}
}

