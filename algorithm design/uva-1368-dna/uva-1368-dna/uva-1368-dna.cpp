// uva-1368-dna.cpp : 定义控制台应用程序的入口点。
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
int n,m;
int ss[1000+10][26];
char str[1000+10];
char maxn[1000+10];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		memset(ss,0,sizeof(ss));
		memset(maxn,0,sizeof(maxn));
		for(int i = 0;i<m;i++)
		{
			scanf("%s",str);
			for(int j =0;j<n;j++)
			{
				ss[j][str[j]-'A']++;
			}
		}
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			int maxt = 0;
			for(int j = 25;j>=0;j--)
			{
				if(ss[i][j]>=maxt)
				{
					maxt = ss[i][j];
					maxn[i]='A'+j;
				}
			}
			for(int j = 0;j<=25;j++)
				if(ss[i][j]&&j!=maxn[i]-'A')
					ans+=ss[i][j];
		}
		printf("%s\n",maxn);
		printf("%d\n",ans);
	}
}

