// uva-687-lattice.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int N = 20;
const int M = 50;
int ans,g[N];
set<string> rec;
int d[M],c[M];
char sta[M][N];
void handle()
{
	for(int i = 0;i<32;i++)//i均为5位
	{//将i分解为二进制  放入sta[i]中
		int k = i;
		int t = 0;
		for(int j = 0;j<5;j++)
		{
			int m = k%2;
			k/=2;
			t = 2*t+m;
			sta[i][4-j]='0'+m;//sta[i]存放i的二进制低5位  sta[i][4]为个位 sta[i][0]为高位
		}
		d[i]=t;//d[i]为i的二进制反转得到的数
	}
}
void rechange(int id, char* str)
{
	int t = 0,k = 0;
	for(int i = 0;i<5;i++)
	{
		t = 2*t+str[i]-'0';//str[0]str[1]..str[4]组成的数
		k = 2*k+str[4-i]-'0';//str[4]str[3]..str[0]组成的数
	}
	c[t]++;
	c[k]++;
}
bool init()
{
	rec.clear();
	ans = 0;
	memset(c,0,sizeof(c));
	char str[N];
	for(int i = 0;i<10;i++)
	{
		scanf("%s",str);
		if(strcmp(str,"END")==0) return false;
		rechange(i,str);//分别计算str正反方向的二进制值的个数
	}
	return true;
}
void add(char (*x)[N],char (*y)[N])
{
	string str;
	for(int i = 0;i<5;i++)
		str = str+x[i];
	for(int i = 0;i<5;i++)
		str = str+y[i];
	rec.insert(str);//x,y拼接放入set
}
void ret(char (*x)[N])//将第一行放入最后一列  第二行放倒数第二列。。。即矩阵顺时针转
{
	char y[N][N];
	for(int i = 0;i<5;i++)
		strcpy(y[i],x[i]);
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			x[j][4-i]=y[i][j];
		}
	}
}
void del()
{
	ans++;//得到一组解
	char x[N][N],y[N][N];
	for(int i = 0;i<5;i++)//g[i] g[i+5]为对应的横向和竖向两个数
	{
		strcpy(x[i],sta[g[i]]);//二进制数放入x,y
		strcpy(y[i],sta[g[i+5]]);
	}
	for(int i = 0;i<4;i++)//将当前x,y保存的5个数 分别顺时针转4次 记录不同的旋转值
	{
		add(x,y);
		ret(x);
		ret(y);
	}
	for(int i = 0;i<5;i++)
	{
		strcpy(x[i],sta[g[4-i]]);//横向5个数上下换位
		strcpy(y[i],sta[d[g[i+5]]]);//横向的数g[i]上下换位对应竖向的数g[i+5]高低位反转  即d[g[i+5]]
	}
	for(int i = 0;i<4;i++)//同理顺时针转
	{
		add(x,y);
		ret(x);
		ret(y);
	}
}
bool judge()//对横向放的5个5位二进制数  求其对应的竖向放的数 相应位为取反
{
	int r[M];
	memset(r,0,sizeof(r));
	for(int i = 0;i<5;i++)//横向的第i列  对应竖向第i个数  遍历每个横向数的第i位
	{
		int k = 0;
		for(int j = 0;j<5;j++)//横向第j个数
		{
			k = k*2+((g[j]&(1<<i))?0:1);//每个横向数的第i位  取反为竖向第i个数第j位的值
		}
		if(r[k]>=c[k]) return false;//不够取
		g[i+5]=k;//从5个横向数后面放置
		r[k]++;//记录使用次数
		r[d[k]]++;
	}
	string str;
	for(int i = 0;i<10;i++)
	{
		str = str+sta[g[i]];
	}
	if(rec.find(str)!=rec.end()) return false;
	return true;
}
void dfs(int deep)
{
	if(deep>=5)//得到若干横向放的数
	{
		if(judge()) del();
		return;
	}
	for(int i =0;i<32;i++)//5位数  至多31
	{
		if(c[i]==0) continue;//数出现过
		c[i]--;
		c[d[i]]--;
		g[deep]=i;//g[]放暂存的i
		dfs(deep+1);
		c[i]++;
		c[d[i]]++;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	handle();
	while(init())
	{
		dfs(0);
		printf("%d\n",ans/2);
	}
}

