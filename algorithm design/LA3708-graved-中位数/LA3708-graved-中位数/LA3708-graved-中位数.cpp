// LA3708-graved-中位数.cpp : 定义控制台应用程序的入口点。
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
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		double ans = 0.0;
		for(int i = 1;i<n;i++)//从第一个开始
		{
			double pos = (double)i/n*(n+m);
			ans+=fabs(pos-floor(pos+0.5))/(n+m);
		}
		printf("%.4lf\n",ans*10000);
	}
}

