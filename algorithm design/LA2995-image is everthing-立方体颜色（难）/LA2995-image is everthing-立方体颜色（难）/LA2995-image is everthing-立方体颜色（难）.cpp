// LA2995-image is everthing-立方体颜色（难）.cpp : 定义控制台应用程序的入口点。
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
#define REP(i,n) for(int i = 0;i<(n);i++)
const int maxn = 10;
int n;
char pos[maxn][maxn][maxn];
char view[maxn][maxn][maxn];
char read_char()
{
	char ch;
	for(;;)
	{
		ch = getchar();
		if((ch>='A'&&ch<='Z')||ch=='.')
			return ch;
	}
}
void get(int k, int i, int j,int len, int &x,int &y,int &z)//得到从k视图的角度看到(i,j)贯通len距离的方块坐标(x,y,z)
{
	if(k==0){x=len;y=j;z=i;}//前视图 x改变  y,z与j,i一致
	if(k==1){x=n-1-j;y=len;z=i;}//左视图 y为贯通的距离 z显然为i x为i与n-1相对距离 （坐标原点与i起始点相反）
	if(k==2){x=n-1-len;y=n-1-j;z=i;}//后视图 与前视图相反
	if(k==3){x=j;y=n-1-len;z=i;}//右视图 z不变 x,y与左视图相反
	if(k==4){x=n-1-i;y=j;z=len;}//顶视图 z为贯通距离 
	if(k==5){x=i;y=j;z=n-1-len;}//贯通距离与顶视图相反
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)==1&&n)
	{
		REP(i,n) REP(k,6) REP(j,n) view[k][i][j]=read_char();//k为前左后右顶底6个视图 view[k][i][j]为k号视图的i,j坐标颜色
		REP(i,n) REP(j,n) REP(k,n) pos[i][j][k]='#';//先假设每个位置都有方块
		REP(k,6) REP(i,n) REP(j,n) if(view[k][i][j]=='.')//k视图的(i,j)为空
			REP(p,n){//k视图方向 (i,j)应贯通
				int x,y,z;
				get(k,i,j,p,x,y,z);//k视图方向的(i,j)贯通距离上所有块消去
				pos[x][y][z]='.';
		}
		for(;;)
		{
			bool done = true;
			REP(k,6) REP(i,n) REP(j,n) if(view[k][i][j]!='.')//不为空
			{
				REP(p,n)
				{
					int x,y,z;
					get(k,i,j,p,x,y,z);
					if(pos[x][y][z]=='.') continue;//已经被挖去  继续
					if(pos[x][y][z]=='#')//还有方块  且未上色
					{
						pos[x][y][z]=view[k][i][j];//第一次涂色：颜色应为从k视图看去的相应位置
						break;
					}
					if(pos[x][y][z]==view[k][i][j]) break;//颜色与之前涂色相同  继续
					pos[x][y][z]='.';//若(x,y,z)处之前循环已经涂色且颜色不同  挖去
					done=false;
				}
			}
			if(done) break;
		}
		int ans = 0;
		REP(i,n) REP(j,n) REP(k,n)
			if(pos[i][j][k]!='.') ans++;
		printf("Maximum weight: %d gram(s)\n",ans);
	}
}

