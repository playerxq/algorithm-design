// uva-757-gone fishing.cpp : 定义控制台应用程序的入口点。
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
			int sum = 0;//最远到第i个池塘
			int tt = 12*h-t[i];//5 mins a unit
			if(tt<=0)
				break;
			memset(fk,0,sizeof(fk[0])*(i+1));//已经用在某个池塘的时间
			while(1)
			{
				int max_fish = 0;
				int max_j = 0;
				int flag = 0;
				for(int j = 0;j<=i;j++)
				{
					int fx = f[j]-fk[j]*d[j];//一个单位时间内能得到的数目
					if(fx>max_fish)
					{
						max_fish = fx;
						max_j = j;
						flag = 1;
					}
				}
				if(!flag)//每个都是负的
					break;
				sum+=max_fish;
				fk[max_j]++;//此处用一单位去得到鱼
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
		if(!maxn)  // 若最大值为0，即：第一个钓鱼地点初始值为0，同时时间上无法到达第二个钓鱼地点，则需特殊处理  
            save[0] = h * 60;
		printf("%d", save[0]);  
        for(int i = 1; i < n; i++)  
            printf(", %d", 5 * save[i]);  
        printf("\nNumber of fish expected: %d\n", maxn); 
	}
	return 0;
}

