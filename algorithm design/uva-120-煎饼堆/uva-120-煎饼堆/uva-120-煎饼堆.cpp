// uva-120-煎饼堆.cpp : 定义控制台应用程序的入口点。
//DP   考虑当前0--i的串  找最大的max  在j处  将0到j翻转 再将0到i翻转可将max放到i处

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
int s[35];
void process(char* str,int* num)
{
	memset(s,0,sizeof(s));
	int len = strlen(str);
	int i = 0;
	int j = 0;
	while(str[i]!='\0')
	{
		if(str[i]!=' ')
		{
			int temp = 0;
			while(str[i]!='\0'&&str[i]!=' ')
			{
				temp = temp*10 + str[i] - '0';
				i++;
			}
			s[j++] = temp;
		}
		else
			i++;
	}
	*num = j;
}
void rev(int l, int r)
{
	int i = l;
	for(;i<(r-l+1)/2;i++)
	{
		int temp = s[i];
		s[i] = s[r+l-i];
		s[r+l-i] = temp;
	}
}
int main()
{
	char pch[100];
	int count = 0;
	while(gets(pch)!=NULL)
	{
		cout<<pch<<endl;
		process(pch,&count);
		for(int i = 1;i<count;i++)//此时考虑0到count-i的串
		{
			int max = -1;
			int max_pos = 0;
			for(int j = count-i;j>=0;j--)
			{
				if(s[j]>max)
				{
					max = s[j];
					max_pos = j;
				}
			}
			if(max_pos==0)
			{
				rev(0,count-i);
				max_pos = count-i;
				cout<<i<<" "; 
			}
			else if(max_pos!=count-i)
			{
				rev(0,max_pos);
				cout<<count-max_pos<<" ";
				rev(0,count-i);
				cout<<i<<" "; 
			}
		}
		cout<<"0\n";
	}
	return 0;
}

