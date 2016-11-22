// uva-818-cutting chain.cpp : 定义控制台应用程序的入口点。
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
const int N = 20;
const int INF = 0x3f3f3f3f;
int n,cn,g[N][N],vis[N];
void init()
{
	int a,b;
	memset(g,0,sizeof(g));
	while(scanf("%d%d",&a,&b)!=EOF&&a!=-1&&b!=-1)
		g[b-1][a-1]=g[a-1][b-1]=1;
}
bool two(int s)//判断为0的位是否有多于2个分支
{
	for(int i = 0;i<n;i++)
	{
		if(s&(1<<i)) continue;
		int num = 0;
		for(int j = 0;j<n;j++)
		{
			if(s&(1<<j)) continue;
			if(g[i][j]) num++;
		}
		if(num>2) return true;
	}
	return false;
}
bool dfs(int s, int now, int fa)
{
	vis[now]=1;
	for(int i = 0;i<n;i++)
	{
		if(!g[now][i]||(s&(1<<i))||i==fa) continue;
		if(vis[i]) return true;//判断是否有环
		if(dfs(s,i,now)) return true;
	}
	return false;
}
bool circle(int s)//是否有环
{
	for(int i = 0;i<n;i++)
	{
		if(vis[i]||(s&(1<<i))) continue;
		cn++;//记录分支的个数
		if(dfs(s,i,-1)) return true;//当前分支有环
	}
	return false;
}
int cal(int s)
{
	return s==0?0:cal(s/2)+(s&1);//计算s中1的个数
}
int solve()
{
	int ans = INF;
	int s = 1<<n;
	for(int i = 0;i<s;i++)
	{
		cn=0;
		memset(vis,0,sizeof(vis));
		if(two(i)||circle(i)) continue;//有环或者有多于2个分支的点
		if(cal(i)>=cn-1)
			ans=min(cal(i),ans);//保存i中1个数最小值
	}
	return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		init();
		printf("Set %d: Minimum links to open is %d\n",++kase,solve());
	}
}

