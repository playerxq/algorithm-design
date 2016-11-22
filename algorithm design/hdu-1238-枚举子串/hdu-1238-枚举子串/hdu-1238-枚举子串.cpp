// hdu-1238-枚举子串.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
char str[105][105];
char str1[105];
char str2[105];
int minlen,minind,len;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		minlen = 1000;
		int MAX = 0;
		for(int i = 0;i<n;i++)
		{
			scanf("%s",str[i]);
			len = strlen(str[i]);
			if(len<minlen)
			{
				minlen = len;
				minind = i;
			}
		}
		len = strlen(str[minind]);
		int flag = 1;
		MAX = 0;
		for(int i = 0;i<len;i++)
		{
			for(int j = i;j<len;j++)
			{
				for(int k = i;k<=j;k++)
				{
					str1[k-i]=str[minind][k];
					str2[j-k]=str[minind][k];
				}
				str1[j-i+1]='\0';
				str2[j-i+1]='\0';
				int l = strlen(str1);
				for(int k = 0;k<n;k++)
				{
					if(!strstr(str[k],str1)&&!strstr(str[k],str2))
					{
						flag = 0;
						break;
					}
				}
				if(l>MAX&&flag)
					MAX = l;
				flag = 1;
			}
		}
		printf("%d\n",MAX);
	}
}

