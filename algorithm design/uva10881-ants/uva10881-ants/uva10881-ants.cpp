// uva10881-ants.cpp : �������̨Ӧ�ó������ڵ㡣
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
const int maxn=10005;
struct Ant
{
	int id;
	int p;
	int d;
	bool operator < (const Ant& a) const
	{
		return p<a.p;
	}
} before[maxn], after[maxn];
const char dirName[][10]={"L","Turning","R"};
int order[maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int K;
	scanf("%d",&K);
	for(int kase=1;kase<=K;kase++)
	{
		int L,T,n;
		printf("Case #%d:\n",kase);
		scanf("%d%d%d",&L,&T,&n);
		for(int i = 0;i<n;i++)
		{
			int p,d;
			char c;
			scanf("%d %c",&p,&c);
			d=(c=='L'?-1:1);
			Ant bf;
			Ant af;
			bf.d=d;
			bf.p=p;
			bf.id=i;
			af.id=0;
			af.d=d;
			af.p=p+T*d;
			before[i]=bf;
			after[i]=af;//���ڼ�����ײʱ�Դ�����  ����һ�����ϴ���p+T*dλ��
		}
		sort(before,before+n);
		for(int i = 0;i<n;i++)
			order[before[i].id]=i;//��ʼ˳��  ���ʼ�ձ��ֲ���  id����������ʼλ���д������λ��i��
		sort(after,after+n);//������λ������  �ٰ���ʼ�����λ�ø�ÿ������λ�ø���id��
		for(int i = 0;i<n-1;i++)
			if(after[i].p==after[i+1].p)
				after[i].d=after[i+1].d	=0;
		for(int i = 0;i<n;i++)//����id��
		{
			int a = order[i];//i����������ʼλ����Ϊa�Ŵ� ���˶������� i������ʼ�մ��������������λ�õ�a�Ŵ�
			if(after[a].p<0||after[a].p>L)//��after[]�� a�Ŵ���λ��p����id=i�����ϵ�λ��
				printf("Fell off\n");
			else
				printf("%d %s\n",after[a].p,dirName[after[a].d+1]);//d����-1 ��+1��ʼ����
		}
		printf("\n");
	}
}

