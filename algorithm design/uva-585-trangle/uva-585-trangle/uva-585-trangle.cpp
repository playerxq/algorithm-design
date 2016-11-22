// uva-585-trangle.cpp : 定义控制台应用程序的入口点。
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
const int N = 205;
int n, ans, v[N][N];
void init()
{
	char str[N*2];
	ans = 0;
	memset(v,-1,sizeof(v));
	for(int i = 0;i<n;i++)
	{
		gets(str);
		int len = strlen(str);
		for(int j = 0;j<len;j++)
			if(str[j]=='-')
				v[i][j] = 0;
	}
}
void dfs(int x, int y, int d, int dir)//x行 y列
{
	if(x<0||x>n)//出界
	{
		ans = max(ans,d);
		return;
	}
	for(int i = y-d;i<=y+d;i++)//y列向左右扩展d个单元
	{
		if(v[x][i]==-1)//当前x行遇到有颜色的  此时的d为层数，记录最大层数d
		{
			ans = max(ans,d);
			return;
		}
	}
	//当前x行扩展-d:d没有遇到颜色的 再扩展一行
	dfs(x+dir,y,d+1,dir);//沿dir方向考虑下一行
}
void solve()
{
	for(int i = 0;i<n;i++)
	{
		int t = 2*(n-i)+i-1;//从上第0层开始  每层的最大单元 2n-1 2n-2 2n-3...
		for(int j = i;j<t;j++)//第i层从i开始到最大单元-1
		{
			if(v[i][j]==0)//未上色
			{
				if((i+j)%2==1)//坐标为奇数  向下
					dfs(i,j,0,1);//三角形 第0行为j d=0下一行为j-1 j j+1 即d=1 再下一行j-2 j-1 j j+1 j+2即d=2 类推 
				else
					dfs(i,j,0,-1);
			}
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 1;
	while(scanf("%d%*c",&n)==1&&n)
	{
		init();
		solve();
		printf("Triangle #%d\n",kase++);
		printf("The largest triangle area is %d.\n\n",ans*ans);
	}
}

