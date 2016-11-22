// hdu-1201-日期计算.cpp : 定义控制台应用程序的入口点。
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
int T;
int y,d,m;
int md[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int isleap(int y)
{
    if(y%4==0&&(y%100!=0||y%400==0))return 1;
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d-%d-%d",&y,&m,&d);
		int ny = y+18;
		int nm = m;
		int nd = d;
		int count = 0;
		if(isleap(y)&&m==2&&d==29&&!isleap(ny))
		{
			printf("-1\n");
			continue;
		}
		while(y!=ny)
		{
			if(isleap(y))
				md[1]=29;
			else
				md[1]=28;
			if(d<md[m-1])
			{
				d++;
				count++;
			}
			else if(d==md[m-1])
			{
				d=1;
				count++;
				m++;
				if(m>12)
				{
					m=1;
					y++;
				}
			}
		}
		while(m!=nm)
		{
			if(isleap(y))
				md[1]=29;
			else
				md[1]=28;
			if(d<md[m-1])
			{
				d++;
				count++;
			}
			else if(d==md[m-1])
			{
				d=1;
				count++;
				m++;
			}
		}
		while(d!=nd)
		{
			d++;
			count++;
		}
		printf("%d\n",count);
	}
}

