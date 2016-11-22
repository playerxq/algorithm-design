// uva-11039-building design.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 500000+10;
int a[maxn];
int b[maxn];
int len1,len2;
int maxlen;
int cmp(const void* _a, const void* _b)
{
	int* a = (int*)_a;
	int* b = (int*)_b;
	return abs(*a)-abs(*b);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int p;
	scanf("%d",&p);
	while(p--)
	{
		int n,i,j;
		maxlen = len1 = len2 = 0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i = 0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp<0)
				a[len1++]=temp;
			else
				b[len2++]=temp;
		}
		qsort(a,len1,sizeof(a[0]),cmp);
		qsort(b,len2,sizeof(b[0]),cmp);
		if(len1==0||len2==0)
		{
			printf("1\n");
			continue;
		}
		int cnt = 0;
		int pre = 0;
		int pre_co = 0;
		int ans = 0;
		do
		{
			i = 1-cnt;j = cnt;
			pre_co = cnt;
			pre = cnt==0?abs(a[0]):b[0];
			maxlen = 1;
			while(i<len1&&j<len2)
			{
				if(pre_co==0)
				{
					while(j<len2&&b[j]<=pre) j++;
					if(j==len2)
						break;
					pre = b[j++];
					pre_co = 1;
					maxlen++;
				}
				else
				{
					while(i<len1&&abs(a[i])<=pre) i++;
					if(i==len1)
						break;
					pre = abs(a[i++]);
					pre_co = 0;
					maxlen++;
				}
			}
			while(i<len1&&abs(a[i])<=pre&&pre_co==1)
			{
				i++;
			}
			if(i<len1&&abs(a[i])>pre&&pre_co==1)
				maxlen++;
			while(j<len2&&b[j]<=pre&&pre_co==0)
			{
				j++;
			}
			if(j<len2&&b[j]>pre&&pre_co==0)
				maxlen++;
			ans = max(ans,maxlen);
			cnt++;
		}while(cnt<2);
		printf("%d\n",ans);
	}
}

