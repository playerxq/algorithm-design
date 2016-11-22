// uva-1555-garland.cpp : 定义控制台应用程序的入口点。
//H1 = a  H3 = 2*H2+2-H1 H4 = 2*H3+2-H2...Hn=2H(n-1)+2-H(n-2)

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
const int N = 1002;
int n, K[N];//K[i]为Hi中H2系数
double a,b[N],k;
double solve()
{
	k = 0;//H2
	K[1]=0;
	b[1]=a;
	K[2]=1;
	b[2]=0.0;
	for(int i = 3;i<=n;i++)
	{
		K[i]=2*K[i-1]-K[i-2];
		b[i]=2*b[i-1]-b[i-2]+2;
		if(k*K[i]+b[i]<0)
			k = -b[i]/K[i];
	}
	return k*K[n]+b[n];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%lf",&n,&a)!=EOF)
		printf("%.2lf\n",solve());
}

