// uva-311-packets.cpp : �������̨Ӧ�ó������ڵ㡣
//

// poj-1017.cpp : �������̨Ӧ�ó������ڵ㡣
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
     int n,a,b,c,d,e,f,x,y;//n��ʾ��Ҫ�����ӣ�
                         //x��ʾ1*1�Ŀ�λ��Ŀ��y��ʾ2*2��λ��Ŀ
    int u[4]={0,5,3,1};
     //��ʾ3*3�Ĳ�Ʒ�ֱ���4k,4k+1,4k+2,4k+3ʱ��Ϊ3*3��Ʒ�򿪵���������ʣ��2*2�Ŀ�λ��
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

