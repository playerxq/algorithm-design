// uva-1533-moving pegs-bfs.cpp : 定义控制台应用程序的入口点。
//15个位置，可以用一个二进制数表示状态

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
const int M = 20;
const int N = 70000;
const int dir[15][6] = {   
    {-1, -1, -1, -1, 2, 3}, {-1, 1, -1, 3, 4, 5}, {1, -1, 2, -1, 5, 6},     
    {-1, 2, -1, 5, 7, 8}, {2, 3, 4, 6, 8, 9}, {3, -1, 5, -1, 9, 10},     
    {-1, 4, -1, 8, 11, 12}, {4, 5, 7, 9, 12, 13}, {5, 6, 8, 10, 13, 14},     
    {6, -1, 9, -1, 14, 15}, {-1, 7, -1, 12, -1, -1}, {7, 8, 11, 13, -1, -1},     
    {8, 9, 12, 14, -1, -1}, {9, 10, 13, 15, -1, -1}, {10, -1, 14, -1, -1, -1}  };  
struct state
{
	int far;
	int val;//状态
	int x,y,d;//x 跳离的点 y跨过的点
}q[N];
int n,pTow[M],v[N];
bool judge(int u, int c, int tmp,state& now)//从c号位朝tmp方向跳
{
	int s = c;//准备跳离的点
	bool flag = false;//为true时表示合理的跳跃
	u-=pTow[c];//从当前状态中减去2^c即c号位为空  离开  
	c=dir[c][tmp]-1;//dir[c][tmp]-1号坑位将作为中间跨过点改变状态
	while(c>-1)//合理的跳跃 只有原来的c处有而dir[c][tmp]-1中间点处有 目标点空的情况 则目标点变为有 起始点和中间点消去为空
	{
		if((u&pTow[c])==0)//之前本身为空
		{
			if(!flag) return false;//如果发生在中间跨越的点  则返回假 说明中间的是空的 不是合理跳跃
			//为目标点为空  设置成有
			now.val = u+pTow[c];//记录改变后的状态  表示空变有
			now.x=s;
			now.y=c;//跨过的点
			return true;
		}
		u-=pTow[c];//再从c处跳离 表示从中间点跨过  消去中间点
		c=dir[c][tmp]-1;//此时才是目标点
		flag = true;
	}
	return false;
}
bool handle(state c, int l, int& r)
{
	int u = c.val;//c对应的坑位状态
	state cur;
	for(int i = 0;i<15;i++)//枚举15个坑
	{
		if((u&pTow[i])==0) continue;//若u和2^i与为0 则i位为0 为空坑
		//找到一个为1不空的坑 号为i
		for(int j = 0;j<6;j++)//i的周围6个点
		{
			if(dir[i][j]==-1) continue;//不可以到达
			//i号坑跳往j号方向  则dir[i][j]-1（从1开始转为从0开始）位将改变状态
			if(judge(u,i,j,cur)&&!v[cur.val])
			{//入队
				cur.far = 1;
				v[cur.val]=1;
				cur.d=q[l].d+1;
				q[r++]=cur;
				if(cur.val==pTow[n-1]) return true;
			}
		}
	}
	return false;
}
void solve()
{
	scanf("%d",&n);//为空的坑位
	int start = pTow[15]-1-pTow[n-1];//2^15-1-2^(n-1)  15个位置 最大2^15-1  状态表示为2^15-1-2^(n-1)为n坑为空的情况 即n-1位为0
	int l = 0,r=0;
	memset(v,0,sizeof(v));
	v[start]=1;
	q[r].far=0;
	q[r].val=start;//当前坑的状态
	q[r].d=0;
	r++;//入队
	while(l<r)
	{
		state u = q[l];
		l++;
		if(handle(u,l-1,r)) break;
	}
	printf("%d\n",q[r-1].d);
	int cnt = 0,p[M];
	for(int i = r-1;i;i = q[i].far) p[cnt++]=i;
	printf("%d %d",q[p[cnt-1]].x+1,q[p[cnt-1]].y+1);
	for(int i = cnt-2;i>=0;i--) printf(" %d %d",q[p[i]].x+1,q[p[i]].y+1);
	printf("\n");
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 0;
	scanf("%d",&kase);
	pTow[0] = 1;
	for(int i = 1;i<=16;i++)
		pTow[i]=pTow[i-1]*2;//2^i
	while(kase--)
		solve();
}

