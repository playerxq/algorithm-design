// uva-656-optimal programs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const char sign[5][5]={"ADD","DIV","DUP","MUL","SUB"};
const int N = 20;
const int tmp = 30000;
int n,b[N],e[N];
bool flag;
int ans,rec[N];
void init()
{
	ans = N;
	flag =true;
	memset(rec,0,sizeof(rec));
	for(int i = 0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i = 0;i<n;i++)
		scanf("%d",&e[i]);
}
bool judge(int d, int* path)
{
	for(int i = 1;i<n;i++)
	{
		int u,v;
		stack<int> s;
		s.push(b[i]);
		for(int j = 0;j<d;j++)
		{
			if(path[j]!=2)
			{
				u = s.top();s.pop();
				v=s.top();s.pop();
				switch(path[j])
				{
				case 0:
					if(abs(v+u)>tmp) return false;
					s.push(v+u);
					break;
				case 1:
					if(u==0||abs(v/u)>tmp) return false;
					s.push(v/u);
					break;
				case 3:
					if(abs(v*u)>tmp) return false;
					s.push(v*u);
					break;
				case 4:
					if(abs(v-u)>tmp) return false;
					s.push(v-u);
					break;
				}
			}
			else
			{
				u = s.top();
				s.push(u);
			}
		}
		u = s.top();
		if(u!=e[i])
			return false;
	}
	return true;
}
void dfs(int d, stack<int> s,int* path, int f)
{
	if(d>10||d>=ans) return;
	int u = s.top(),v;
	if(u==e[0]&&judge(d,path))//找到x0 y0路径  判断是否满足其他的
	{
		ans = d;
		flag = false;
		for(int i = 0;i<ans;i++)
			rec[i]=path[i];
		return;
	}
	if(s.size()>1)
	{
		s.pop();v=s.top();s.pop();
		if(abs(u+v)<=tmp)
		{
			path[d]=0;
			s.push(u+v);
			dfs(d+1,s,path,f);
			s.pop();
		}
		if(u&&abs(v/u)<=tmp)
		{
			path[d]=1;
			s.push(v/u);
			dfs(d+1,s,path,f);
			s.pop();
		}
		s.push(v);
		s.push(u);
	}
	if(f<5)
	{
		path[d]=2;
		s.push(u);
		dfs(d+1,s,path,f+1);
		s.pop();
	}
	if(s.size()>1)
	{
		s.pop();v=s.top();s.pop();
		if(abs(u*v)<=tmp)
		{
			path[d]=3;
			s.push(u*v);
			dfs(d+1,s,path,f);
			s.pop();
		}
		if(abs(v-u)<=tmp)
		{
			path[d]=4;
			s.push(v-u);
			dfs(d+1,s,path,f);
			s.pop();
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 1;
	while(scanf("%d",&n)==1&&n)
	{
		init();
		int path[N];
		stack<int> s;
		s.push(b[0]);
		dfs(0,s,path,0);
		printf("Program %d\n",kase++);
		if(flag)
			printf("Impossible\n");
		else if(ans==0)
			printf("Empty sequence\n");
		else
		{
			printf("%s",sign[rec[0]]);
			for(int i = 1;i<ans;i++)
				printf(" %s",sign[rec[i]]);
			printf("\n");
		}
		printf("\n");
	}
}
