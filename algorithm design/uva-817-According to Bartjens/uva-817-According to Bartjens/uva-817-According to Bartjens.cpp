// uva-817-According to Bartjens.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <set>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int N = 20;
char sign[4]={'*','+','-',0};
int n,c[N];
bool flag;
char str[N];
set<string> s;
void init()
{
	s.clear();
	n = strlen(str)-2;
	flag = true;
}
bool judge(char* t)
{
	int len = strlen(t);
	char op[N];
	int num[N],cNum = 0,cOp = 0;
	int sum = 0;
	bool bo = false;
	bool ok = false;
	for(int i = 0;i<=len;i++)
	{
		if(t[i]>='0'&&t[i]<='9')
		{
			sum = sum*10+t[i]-'0';
			if(bo) return false;//出现0开头的数字
			if(sum==0) bo = true;
		}
		else if(ok)
		{
			int u = num[--cNum];
			num[cNum++]=sum*u;
			sum = 0;
			bo = false;
			if(t[i]!='*'&&t[i]!='\0')//先计算乘法再计算加减  故先保存加减
			{
				op[cOp++]=t[i];
				ok = false;
			}
		}
		else if(t[i]=='*')
		{
			num[cNum++]=sum;
			sum = 0;
			ok = true;//保存了乘法的第一个操作数
			bo = false;
		}
		else
		{
			num[cNum++]=sum;
			sum = 0;
			if(t[i]!='\0')//先计算乘法再计算加减  故先保存加减
			{
				op[cOp++]=t[i];
				bo = false;
			}
		}
	}
	sum = num[0];
	for(int i = 1;i<cNum;i++)
	{
		if(op[i-1]=='-') sum-=num[i];
		else sum+=num[i];
	}
	if(sum==2000)
		return true;
	return false;
}
void handle()
{
	char f[N];
	int t = 0;
	for(int i = 0;i<=n;i++)
	{
		f[t++]=str[i];
		if(i!=n&&c[i]!=3) f[t++]=sign[c[i]];
	}
	f[t]='\0';
	if(judge(f))
	{
		string g = f;
		s.insert(g);
		flag = false;
	}
}
void dfs(int d)
{
	if(d>=n)
	{
		handle();
		return;
	}
	for(c[d] = 0;c[d]<4;c[d]++)
	{
		dfs(d+1);
	}
}
void solve()
{
	if(strcmp(str,"2000=")==0)
	{
		printf("  IMPOSSIBLE\n");
		return;
	}
	dfs(0);
	if(flag)
		printf("  IMPOSSIBLE\n");
	else
	{
		set<string>::iterator it;
		for(it = s.begin();it!=s.end();it++)
		{
			cout<<"  "<<*it<<"="<<endl;
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 1;
	while(scanf("%s",str)==1&&strcmp(str,"="))
	{
		printf("Problem %d\n",kase++);
		init();
		solve();
	}
}
