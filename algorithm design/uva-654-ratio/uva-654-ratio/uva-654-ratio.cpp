// uva-654-ratio.cpp : 定义控制台应用程序的入口点。
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
const int INF = 0x3f3f3f;
int n,m;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t = 0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(t)
			printf("\n");
		t = 1;
		double k = n/(m*(1.0));
		double r = INF;
		for(int i = 1;i<=m;i++)
		{
			int j = i*k+0.5;
			double temp = fabs(j/(i*1.0)-k);
			if(temp<r)
			{
				r = temp;
				printf("%d/%d\n",j,i);
			}
		}
	}
}

