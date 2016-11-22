// uva-225-golygons-dfs����.cpp : �������̨Ӧ�ó������ڵ㡣
//�ӣ�0��0��������ÿ����1��2��3...,n���ܻص�ԭ��ķ�����ÿ��������Ҫ�ı䷽��Ҳ�����������ߡ�Ȼ������k���ϰ�������ꡣ�����Ծ����ϰ������ͣ���ĵط��������ظ���������з����������ֵ���
//��֦�����ǵ�ǰλ��̫Զʣ������в����������ص�ԭ��
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
const char sign[5]="ensw";//����
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
bool judge(int x, int y, int d, int k)//kΪ����  dΪ����
{
	for(int i = 1;i<=k;i++)
	{
		x+=dir[d][0];
		y+=dir[d][1];//��d������k��
		if(abs(x)>tmp||abs(y)>tmp) continue;
		if(g[x+tmp][y+tmp]==-1) return true;
	}
	if(abs(x)+abs(y)>sum[20]-sum[k]) return true;//�Ѿ�����1 2.����k�� ��sum[k] ʣ������sum[20]-sum[k]����x,y�ص�ԭ��
	return false;
}
void dfs(int x, int y, int d, int f)//��x,y��ʼ��d��
{
	if(d>n)
	{
		if(x==0&&y==0)//�ص�ԭ��
		{
			for(int i = 1;i<=n;i++)
				printf("%c",sign[v[i]]);
			printf("\n");
			ans++;
		}
		return;
	}
	int& i = v[d];
	for(i = 0;i<4;i++)//��d��  ��ensw����������ɲ�
	{
		if(i==f||i+f==3) continue;//���ϴ�ͬ��������
		if(judge(x,y,i,d)) continue;
		int p = x+dir[i][0]*d;//��d��
		int q = y+dir[i][1]*d;
		if(g[p+tmp][q+tmp]) continue;
		g[p+tmp][q+tmp]=1;
		dfs(p,q,d+1,i);//�´���d+1��
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

