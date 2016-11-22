// uva-10041-vato family.cpp : 定义控制台应用程序的入口点。
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
int a[501];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int mid=n/2;
		if(n%2==0)
			mid = n/2-1;
		int start = a[mid];
		int dis = 0;
		for(int i = 0;i<n;i++)
		{
			dis+=start>a[i]?(start-a[i]):(a[i]-start);
		}
		printf("%d\n",dis);
	}
	return 0;
}

