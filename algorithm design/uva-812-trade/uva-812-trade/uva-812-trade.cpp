// uva-812-trade.cpp : �������̨Ӧ�ó������ڵ㡣
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
const int tmp = 10;
const int N = 60;
const int M = 1005;
const int INF = 0x3f3f3f3f;
int n,ans,cnt[M];
vector<int> v[N];
void init()
{
	ans = 0;
	memset(cnt,0,sizeof(cnt));
	int m,num;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&m);
		v[i].clear();
		int sum = 0,Max = 0;
		v[i].push_back(0);
		for(int j = 0;j<m;j++)
		{
			scanf("%d",&num);
			sum+=(tmp-num);
			if(sum>Max)
			{
				v[i].clear();
				v[i].push_back(j+1);//v[i]������Բ������͵���������
				Max = sum;
			}
			else if(sum==Max)
			{
				v[i].push_back(j+1);
			}
		}
		ans+=Max;
	}
}
void dfs(int d, int s)
{
	if(d>=n)
	{
		cnt[s]=1;//�������n�е�������
		return;
	}
	int top = v[d].size();//v[d].size()=1ʱ��ֻ������һ�����͵���������  ����v[d][i]����һ����������ͬ�ĺ�
	for(int i = 0;i<top;i++)//
	{
		dfs(d+1,s+v[d][i]);//��ÿ��������ͬ�͵����� �ۼӵ�s����ȵݹ�
	}
}
void solve()
{
	dfs(0,0);
	int c = 0;
	for(int i = 0;i<M;i++)
	{
		if(c>=tmp) break;//�����10��
		if(cnt[i]){printf(" %d",i);c++;}
	}
	printf("\n");
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 0;
	while(scanf("%d",&n)==1&&n)
	{
		init();
		if(kase) printf("\n");
		printf("Workyards %d\n",++kase);
		printf("Maximum profit is %d.\n",ans);
		printf("Number of pruls to buy:");
		solve();
	}
}

