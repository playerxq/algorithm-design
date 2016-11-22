// uva-311-packets.cpp : 定义控制台应用程序的入口点。
//

// poj-1017.cpp : 定义控制台应用程序的入口点。
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

 int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
     int n,a,b,c,d,e,f,x,y;//n表示需要的箱子，
                         //x表示1*1的空位数目，y表示2*2空位数目
    int u[4]={0,5,3,1};
     //表示3*3的产品分别是4k,4k+1,4k+2,4k+3时，为3*3产品打开的新箱子中剩余2*2的空位数
     while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF)
     {
        if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)
             break;
         n=f+e+d+(c+3)/4;
         y=5*d+u[c%4];
         if(b>y)
             n+=(b-y+8)/9;
         x=36*n-36*f-25*e-16*d-9*c-4*b;
         if(a>x)
            n+=(a-x+35)/36;
         printf("%d\n",n);
    }//while
     return 0;
 }

