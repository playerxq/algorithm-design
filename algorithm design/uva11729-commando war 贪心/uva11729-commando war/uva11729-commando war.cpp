// uva11729-commando war.cpp : 定义控制台应用程序的入口点。
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
struct job
{
	int j,b;
	bool operator < (const job& x) const
	{
		return j>x.j;
	}
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,b,j,kase = 1;
	while(scanf("%d",&n)==1&&n)
	{
		vector<job> v;
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&b,&j);
			job jj;
			jj.b=b;
			jj.j=j;
			v.push_back(jj);
		}
		sort(v.begin(),v.end());
		int s = 0;
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			s+=v[i].b;
			ans=max(ans,s+v[i].j);
		}
		printf("Case %d: %d\n",kase++,ans);
	}
}

