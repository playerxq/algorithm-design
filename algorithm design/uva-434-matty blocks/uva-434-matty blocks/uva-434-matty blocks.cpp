// uva-434-matty blocks.cpp : 定义控制台应用程序的入口点。
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
int front[10];
int rightx[10];
int used[2][10];
int k;
int n,m;
int sum;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&k);
		memset(used,0,sizeof(used));
		sum = n = m = 0;
		for(int i = 0;i<k;i++)
			scanf("%d",&front[i]);
		for(int i = 0;i<k;i++)
			scanf("%d",&rightx[i]);
		for(int i = 0;i<k;i++)
			for(int j = 0;j<k;j++)
			{
				sum+=min(front[i],rightx[j]);
			}
		for(int i = 0;i<k;i++)
			for(int j = 0;j<k;j++)
			{
				if(front[i]==rightx[j]&&!used[0][i]&&!used[1][j])
				{
					n+=front[i];
					used[0][i]=used[1][j]=1;
				}
			}
		for(int i = 0;i<k;i++)
		{
			if(used[0][i]==0)
				n+=front[i];
			if(used[1][i]==0)
				n+=rightx[i];
		}
		m = sum-n;
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n",n,m);
	}
}

