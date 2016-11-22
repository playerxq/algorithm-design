// uva-10602-editor nottoobad.cpp : 定义控制台应用程序的入口点。
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
char str[101][101];
int cnt;
void swap_s(int i,int j)
{
	char temp[101] = {0};
	strcpy(temp,str[i]);
	strcpy(str[i],str[j]);
	strcpy(str[j],temp);
}
int get_analogy(char* s,int k)
{
	int len1 = strlen(str[k]);
	int len2 = strlen(s);
	int i = 0;
	int j = 0;
	while(i<len1&&j<len2)
	{
		if(str[k][i]==s[j])
		{
			i++;
			j++;
		}
		else
			break;
	}
	if(i==len1)
		return i;
	else 
		return j;
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
		cnt = 0;
		memset(str,0,sizeof(str));
		getchar();
		for(int i = 0;i<n;i++)
			gets(str[i]);
		cnt+=strlen(str[0]);//first
		for(int i = 0;i<n-1;i++)
		{
			int max_analogy = 0;
			int max_index = -1;
			int max_len = 0;
			int max_len_index = -1;
			for(int j = i+1;j<n;j++)
			{
				int num1 = get_analogy(str[j],i);
				int len1 = strlen(str[j]);
				if(num1>max_analogy)
				{
					max_analogy = num1;
					max_index = j;
				}
				if(len1>max_len)
				{
					max_len = len1;
					max_len_index = j;
				}
			}
			if(max_index>-1)
			{
				cnt+=(strlen(str[max_index])-get_analogy(str[max_index],i));
				swap_s(i+1,max_index);
			}
			else
			{
				cnt+=strlen(str[max_len_index]);
				swap_s(i+1,max_len_index);
			}
		}
		printf("%d\n",cnt);
		for(int i = 0;i<n;i++)
		{
			printf("%s\n",str[i]);
		}
	}
	return 0;
}
