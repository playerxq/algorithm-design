// uva-225-golygons-dfs暴力.cpp : 定义控制台应用程序的入口点。
//从（0，0）出发，每次走1，2，3...,n。能回到原点的方案，每次走完需要改变方向，也不可以往回走。然后会给出k个障碍物的坐标。不可以经过障碍物。并且停留的地方不可以重复。输出所有方案，按照字典序。
//剪枝，就是当前位置太远剩余的所有步数都不够回道原点
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
const int N = 250;
const int tmp = 105;
const int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int n,ans;
int g[N][N],v[N],sum[tmp];
const char sign[5]="ensw";//方向
void init()
{
	ans = 0;
	memset(g,0,sizeof(g));
	int a,b,k;
	scanf("%d%d",&n,&k);
	for(int i = 0;i<k;i++)
	{
		scanf("%d%d",&a,&b);
		if(abs(a)>tmp||abs(b)>tmp) continue;
		g[a+tmp][b+tmp]=-1;
	}
}
bool judge(int x, int y, int d, int k)//k为步数  d为方向
{
	for(int i = 1;i<=k;i++)
	{
		x+=dir[d][0];
		y+=dir[d][1];//朝d方向走k步
		if(abs(x)>tmp||abs(y)>tmp) continue;
		if(g[x+tmp][y+tmp]==-1) return true;
	}
	if(abs(x)+abs(y)>sum[20]-sum[k]) return true;//已经走了1 2.。。k步 共sum[k] 剩余至多sum[20]-sum[k]不够x,y回到原点
	return false;
}
void dfs(int x, int y, int d, int f)//从x,y开始走d步
{
	if(d>n)
	{
		if(x==0&&y==0)//回到原点
		{
			for(int i = 1;i<=n;i++)
				printf("%c",sign[v[i]]);
			printf("\n");
			ans++;
		}
		return;
	}
	int& i = v[d];
	for(i = 0;i<4;i++)//第d步  从ensw方向遍历若干步
	{
		if(i==f||i+f==3) continue;//与上次同向或者相对
		if(judge(x,y,i,d)) continue;
		int p = x+dir[i][0]*d;//走d步
		int q = y+dir[i][1]*d;
		if(g[p+tmp][q+tmp]) continue;
		g[p+tmp][q+tmp]=1;
		dfs(p,q,d+1,i);//下次走d+1步
		g[p+tmp][q+tmp]=0;

	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	sum[0]=0;
	for(int i = 1;i<=20;i++)
		sum[i]=sum[i-1]+i;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		dfs(0,0,1,-1);
		printf("Found %d golygon(s).\n\n",ans);
	}
}

