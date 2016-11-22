// uva-1509-leet.cpp : 定义控制台应用程序的入口点。
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
int len1,len2;
char map[26][4];
char a[20];
char b[100];
int k;
int dfs(int i, int j)
{
	if(i==len1&&j==len2)
		return 1;
	if((i==len1&&j<len2)||(i<len1&&j==len2))
		return 0;
	int ans = 0;
	if((map[a[i]-'a'][0]=='\0')&&j<len2)
	{
		map[a[i]-'a'][0] = b[j];
		ans |= dfs(i+1,j+1);
		map[a[i]-'a'][0] = '\0';
	}
	if((map[a[i]-'a'][0]=='\0')&&j<len2-1&&k>=2)
	{
		map[a[i]-'a'][0] = b[j];
		map[a[i]-'a'][1] = b[j+1];
		ans |= dfs(i+1,j+2);
		map[a[i]-'a'][0] = '\0';
		map[a[i]-'a'][1] = '\0';
	}
	if((map[a[i]-'a'][0]=='\0')&&j<len2-2&&k>=3)
	{
		map[a[i]-'a'][0] = b[j];
		map[a[i]-'a'][1] = b[j+1];
		map[a[i]-'a'][2] = b[j+2];
		ans |= dfs(i+1,j+3);
		map[a[i]-'a'][0] = '\0';
		map[a[i]-'a'][1] = '\0';
		map[a[i]-'a'][2] = '\0';
	}
	if(map[a[i]-'a'][0]!='\0')
	{
		int len = strlen(map[a[i]-'a']);
		if(j+len-1<len2)
		{
			char str[4]={'\0'};
			for(int m = 0;m<len;m++)
				str[m]=b[j+m];
			if(strcmp(map[a[i]-'a'],str)==0)
				ans|=dfs(i+1,j+len);
		}
	}
	return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(map,'\0',sizeof(map));
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		scanf("%d",&k);
		scanf("%s",a);
		scanf("%s",b);
		len1 = strlen(a);
		len2 = strlen(b);
		printf("%d\n",dfs(0,0));
	}
}

