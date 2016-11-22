// hdu-1211-rsa.cpp : 定义控制台应用程序的入口点。
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
int x,y;
long long ext_gcd(int a, int b)
{
	long long t,d;
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	d = ext_gcd(b,a%b);
	t = x;
	x = y;
	y = t-(a/b)*(y);
	return d;
}
int p,q,e,n,d,c,fn,i,j,t,gcd,k;  
long long m;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d %d %d %d",&p,&q,&e,&t)!=EOF)
	{
		n = p*q;
		fn = (p-1)*(q-1);
		gcd = ext_gcd(e,fn);
		d = (x%fn+fn)%fn;
		for(i=0;i<t;i++)  
        {  
            scanf("%d",&c);  
            m=1;  
            for(j=0;j<d;j++)  
            {  
                m*=c;  
                m%=n;  
            }  
            printf("%c",m);  
        }  
        printf("\n");
	}
}

