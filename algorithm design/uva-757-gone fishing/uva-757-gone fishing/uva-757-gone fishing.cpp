// uva-757-gone fishing.cpp : �������̨Ӧ�ó������ڵ㡣
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
int n,h;
int f[30];
int d[30];
int t[30];
int fk[30];
int save[30];
int maxn;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 0;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		memset(t,0,sizeof(t));
		scanf("%d",&h);
		for(int i = 0;i<n;i++)
			scanf("%d",&f[i]);
		for(int i = 0;i<n;i++)
			scanf("%d",&d[i]);
		for(int i = 1;i<n;i++)
		{
			scanf("%d",&t[i]);
			t[i]+=t[i-1];
		}
		if(ncase++)
			printf("\n");
		memset(save,0,sizeof(save));
		maxn = 0;
		int sum_t = 0;
		for(int i=0;i<n;i++)
		{
			int sum = 0;//��Զ����i������
			int tt = 12*h-t[i];//5 mins a unit
			if(tt<=0)
				break;
			memset(fk,0,sizeof(fk[0])*(i+1));//�Ѿ�����ĳ��������ʱ��
			while(1)
			{
				int max_fish = 0;
				int max_j = 0;
				int flag = 0;
				for(int j = 0;j<=i;j++)
				{
					int fx = f[j]-fk[j]*d[j];//һ����λʱ�����ܵõ�����Ŀ
					if(fx>max_fish)
					{
						max_fish = fx;
						max_j = j;
						flag = 1;
					}
				}
				if(!flag)//ÿ�����Ǹ���
					break;
				sum+=max_fish;
				fk[max_j]++;//�˴���һ��λȥ�õ���
				--tt;
				if(tt<=0)
					break;
			}
			if(sum>maxn)
			{
				maxn = sum;
				sum_t = tt;  
                for(int j = 0; j <= i; j++)  
                    save[j] = fk[j]; 
			}
		}
		save[0] *= 5;  
        if(sum_t > 0)  
            save[0] += sum_t * 5;
		if(!maxn)  // �����ֵΪ0��������һ������ص��ʼֵΪ0��ͬʱʱ�����޷�����ڶ�������ص㣬�������⴦��  
            save[0] = h * 60;
		printf("%d", save[0]);  
        for(int i = 1; i < n; i++)  
            printf(", %d", 5 * save[i]);  
        printf("\nNumber of fish expected: %d\n", maxn); 
	}
	return 0;
}

