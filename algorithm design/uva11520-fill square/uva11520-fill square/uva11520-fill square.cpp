// uva11520-fill square.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 15;
char grid[maxn][maxn];
int n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int kase = 1;kase<=T;kase++)
	{
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
			scanf("%s",grid[i]);
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				if(grid[i][j]=='.')
				{
					for(char ch='A';ch<='Z';ch++)
					{
						bool ok = true;
						if(i>0&&grid[i-1][j]==ch) ok = false;
						if(i<n-1&&grid[i+1][j]==ch) ok = false;
						if(j>0&&grid[i][j-1]==ch) ok = false;
						if(j<n-1&&grid[i][j+1]==ch) ok = false;
						if(ok)
						{
							grid[i][j]=ch;break;
						}
					}
				}
		printf("Case %d:\n",kase);
		for(int i = 0;i<n;i++)
			printf("%s\n",grid[i]);
	}
}

