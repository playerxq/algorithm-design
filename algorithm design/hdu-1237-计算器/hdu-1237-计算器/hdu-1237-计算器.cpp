// hdu-1237-计算器.cpp : 定义控制台应用程序的入口点。
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
char str[201];
double a[201];
char b[201];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(gets(str))
	{
		if(str[0]=='0'&&strlen(str)==1)
			break;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n;
		int len = strlen(str);
		double sum = 0;
		int pre = 0;
		int ind =0 ;
		int ind1 =0 ;
		for(int i = 0;i<len;i++)
		{
			if(str[i]!=' '&&str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/')
			{
				int temp = 0;
				while(str[i]!=' '&&str[i]!='\0')
				{
					temp = temp*10+str[i]-'0';
					i++;
				}
				a[ind++]=temp;
			}
			else if(str[i]!=' ')
				b[ind1++]=str[i];
		}
		for(int i = 0;i<ind1;i++)
		{
			if(b[i]=='*'||b[i]=='/')
			{
				if(b[i]=='*')
				{
					a[pre] *= a[i+1];
					a[i+1]=0;
				}
				else
				{
					a[pre] /= a[i+1];
					a[i+1] = 0;
				}
			}
			else
				pre=i+1;
		}
		pre = 0;
		for(int i = 0;i<ind1;i++)
		{
			if(b[i]=='+')
			{
				a[pre]+=a[i+1];
				a[i+1]=0;
			}
			else if(b[i]=='-')
			{
				a[pre]-=a[i+1];
				a[i+1] = 0;
			}
		}
		for(int i = 0;i<ind;i++)
			sum+=a[i];
		printf("%.2lf\n",sum);
	}
}

