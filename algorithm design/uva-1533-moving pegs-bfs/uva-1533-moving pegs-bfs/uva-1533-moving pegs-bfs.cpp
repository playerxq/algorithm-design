// uva-1533-moving pegs-bfs.cpp : �������̨Ӧ�ó������ڵ㡣
//15��λ�ã�������һ������������ʾ״̬

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
	int val;//״̬
	int x,y,d;//x ����ĵ� y����ĵ�
}q[N];
int n,pTow[M],v[N];
bool judge(int u, int c, int tmp,state& now)//��c��λ��tmp������
{
	int s = c;//׼������ĵ�
	bool flag = false;//Ϊtrueʱ��ʾ�������Ծ
	u-=pTow[c];//�ӵ�ǰ״̬�м�ȥ2^c��c��λΪ��  �뿪  
	c=dir[c][tmp]-1;//dir[c][tmp]-1�ſ�λ����Ϊ�м�����ı�״̬
	while(c>-1)//�������Ծ ֻ��ԭ����c���ж�dir[c][tmp]-1�м�㴦�� Ŀ���յ���� ��Ŀ����Ϊ�� ��ʼ����м����ȥΪ��
	{
		if((u&pTow[c])==0)//֮ǰ����Ϊ��
		{
			if(!flag) return false;//����������м��Խ�ĵ�  �򷵻ؼ� ˵���м���ǿյ� ���Ǻ�����Ծ
			//ΪĿ���Ϊ��  ���ó���
			now.val = u+pTow[c];//��¼�ı���״̬  ��ʾ�ձ���
			now.x=s;
			now.y=c;//����ĵ�
			return true;
		}
		u-=pTow[c];//�ٴ�c������ ��ʾ���м����  ��ȥ�м��
		c=dir[c][tmp]-1;//��ʱ����Ŀ���
		flag = true;
	}
	return false;
}
bool handle(state c, int l, int& r)
{
	int u = c.val;//c��Ӧ�Ŀ�λ״̬
	state cur;
	for(int i = 0;i<15;i++)//ö��15����
	{
		if((u&pTow[i])==0) continue;//��u��2^i��Ϊ0 ��iλΪ0 Ϊ�տ�
		//�ҵ�һ��Ϊ1���յĿ� ��Ϊi
		for(int j = 0;j<6;j++)//i����Χ6����
		{
			if(dir[i][j]==-1) continue;//�����Ե���
			//i�ſ�����j�ŷ���  ��dir[i][j]-1����1��ʼתΪ��0��ʼ��λ���ı�״̬
			if(judge(u,i,j,cur)&&!v[cur.val])
			{//���
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
	scanf("%d",&n);//Ϊ�յĿ�λ
	int start = pTow[15]-1-pTow[n-1];//2^15-1-2^(n-1)  15��λ�� ���2^15-1  ״̬��ʾΪ2^15-1-2^(n-1)Ϊn��Ϊ�յ���� ��n-1λΪ0
	int l = 0,r=0;
	memset(v,0,sizeof(v));
	v[start]=1;
	q[r].far=0;
	q[r].val=start;//��ǰ�ӵ�״̬
	q[r].d=0;
	r++;//���
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

