// uva-1422-processor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int N = 10005;
int t,n;
struct Work
{
	double r,d,w;
	friend bool operator < (Work a, Work b)
	{
		return a.d>b.d;
	}
}work[N];
bool cmp(Work a, Work b)
{
	return a.r<b.r;
}
void init()
{
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%lf%lf%lf",&work[i].r,&work[i].d,&work[i].w);
	sort(work,work+n,cmp);
}
bool judge(int mid)
{
	priority_queue<Work> Q;
	int wn = 0;
	for(int i = 1;i<=20000;i++)
	{
		int sum = mid;
		while(work[wn].r<i&&wn!=n) Q.push(work[wn++]);
		while(sum!=0&&!Q.empty())
		{
			Work save = Q.top();
			Q.pop();
			if(i>save.d) return false;
			if(save.w>sum)
			{
				save.w-=sum;
				sum = 0;
				Q.push(save);
			}
			else
			{
				sum-=save.w;
			}
		}
		if(wn==n&&Q.empty()) break;
	}
	if(wn==n&&Q.empty()) return true;
	return false;
}
int solve()
{
	int l = 0;int r = 10000000,mid;
	while(l<r)
	{
		if(r-l==1)break;
		mid=(l+r)>>1;
		if(!judge(mid)) l = mid;
		else r =mid;
	}
	return r;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		init();
		printf("%d\n",solve());
	}
}
