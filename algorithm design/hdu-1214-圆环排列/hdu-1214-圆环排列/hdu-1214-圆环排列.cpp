// hdu-1214-圆环排列.cpp : 定义控制台应用程序的入口点。
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
int n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		int count = 0;
		if(n==1||n==2||n==3)
			printf("1\n");
		if(n==4)
			printf("2\n");
		else
		{
			if(n%2==0)
			{
				for(int i = 1;i<=n/2-1;i++)
					count+=i;
				count*=2;
			}
			else
			{
				for(int i = 1;i<=n/2;i++)
					count+=i;
				for(int i = n/2-1;i>=1;i--)
					count+=i;
			}
			printf("%d\n",count);
		}
	}
}

