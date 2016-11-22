// uva-585-trangle.cpp : �������̨Ӧ�ó������ڵ㡣
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
void dfs(int x, int y, int d, int dir)//x�� y��
{
	if(x<0||x>n)//����
	{
		ans = max(ans,d);
		return;
	}
	for(int i = y-d;i<=y+d;i++)//y����������չd����Ԫ
	{
		if(v[x][i]==-1)//��ǰx����������ɫ��  ��ʱ��dΪ��������¼������d
		{
			ans = max(ans,d);
			return;
		}
	}
	//��ǰx����չ-d:dû��������ɫ�� ����չһ��
	dfs(x+dir,y,d+1,dir);//��dir��������һ��
}
void solve()
{
	for(int i = 0;i<n;i++)
	{
		int t = 2*(n-i)+i-1;//���ϵ�0�㿪ʼ  ÿ������Ԫ 2n-1 2n-2 2n-3...
		for(int j = i;j<t;j++)//��i���i��ʼ�����Ԫ-1
		{
			if(v[i][j]==0)//δ��ɫ
			{
				if((i+j)%2==1)//����Ϊ����  ����
					dfs(i,j,0,1);//������ ��0��Ϊj d=0��һ��Ϊj-1 j j+1 ��d=1 ����һ��j-2 j-1 j j+1 j+2��d=2 ���� 
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

