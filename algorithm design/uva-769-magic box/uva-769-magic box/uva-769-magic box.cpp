// uva-769-magic box.cpp : 定义控制台应用程序的入口点。
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
int n;
void solve()
{
	int t = 2*(n-1);
	for(int i = 0;i<t;i++)
	{
		printf("%d",2*(n+i)+1);
		for(int x = 0;x<=i;x++)
		{
			int y = i-x;
			if(x>=n||y>=n) continue;
			printf(" %d",x*n+y+1);
		}
		printf("\n");
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		solve();
		if(T) printf("\n");
	}
}

