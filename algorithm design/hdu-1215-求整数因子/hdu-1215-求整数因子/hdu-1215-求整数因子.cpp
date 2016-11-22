// hdu-1215-求整数因子.cpp : 定义控制台应用程序的入口点。
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
int n,T;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&T);
	//init();
	while(T--)
	{
		scanf("%d",&n);
		int sum = 1;
		int m = (int)sqrt(n*1.0);
		for(int i = 2;i<=m;i++)
		{
			if(n%i==0)
			{
				sum+=i;
				if(i*i!=n)
					sum+=n/i;
			}
		}
		printf("%d\n",sum);
	}
}

