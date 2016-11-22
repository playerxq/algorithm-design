// 1339-ancient cipher.cpp : 定义控制台应用程序的入口点。
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
char source[110];
char des[110];
int a[27];
int b[27];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%s",source)!=EOF)
	{
		scanf("%s",des);
		int len1 = strlen(source);
		int len2 = strlen(des);
		if(len1!=len2)
			printf("NO\n");
		else
		{
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for(int i = 0;i<len1;i++)
				a[source[i]-'A'+1]++;
			for(int j = 0;j<len2;j++)
				b[des[j]-'A'+1]++;
			sort(a+1,a+27);
			sort(b+1,b+27);
			int i;
			for(i = 1;i<27;i++)
				if(a[i]!=b[i])
					break;
			if(i==27)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}

