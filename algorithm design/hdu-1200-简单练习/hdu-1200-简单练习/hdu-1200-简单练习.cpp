// hdu-1200-简单练习.cpp : 定义控制台应用程序的入口点。
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
char str[201],str1[201],str2[201];
int n,m,len;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
			break;
		memset(str,0,sizeof(str));
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		scanf("%s",str);
		len = strlen(str);
		m = len/n;
		int k = 0;
		for(int i = 0;i<m;i++)
		{
			if(i%2==0)
			{
				for(int j = i*n;j<i*n+n;j++)
				{
					str1[k++]=str[j];
				}
			}
			else
			{
				for(int j = i*n+n-1;j>=i*n;j--)
				{
					str1[k++]=str[j];
				}
			}
		}
		k = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				str2[k++]=str1[i+j*n];
			}
		}
		printf("%s\n",str2);
	}
}

