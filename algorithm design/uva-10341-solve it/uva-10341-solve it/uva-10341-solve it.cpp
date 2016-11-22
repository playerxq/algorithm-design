// uva-10341-solve it.cpp : 定义控制台应用程序的入口点。
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
int p,q,r,s,t,u;
double get_s(double x)
{
	 double rr=p*exp(-x)+q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
     return rr; 
}
double get_ans(double x, double y)
{
	while(y-x>1e-6)
	{
		double m = x+(y-x)/2;
		if(get_s(x)*get_s(m)>0)
			x=m;
		else 
			y=m;
	}
	printf("%.4lf\n", x); 
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char a[100];
	while(gets(a))
	{
		sscanf(a,"%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u);
		double f1 = get_s(0.0);
		double f2 = get_s(1.0);
		if(f1*f2>0)
			printf("No solution\n");
		else
			get_ans(0.0,1.0);
	}
	return 0;
}

