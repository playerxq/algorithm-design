// uva-10716-evil straw warts live.cpp : 定义控制台应用程序的入口点。
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
char s[101];
int used[26];
int get_ans()
{
	int cnt = 0;
	int odd_cnt=0;//奇数次出现的字母个数
	int odd_index = -1;
	char odd_char = 0;
	char c = 0;
	int len = strlen(s);
	for(int i = 0;i<len;i++)
	{
		used[s[i]-'a']++;
	}
	for(int i = 0;i<26;i++)
	{
		if(used[i]%2)
		{
			odd_cnt++;
			odd_char = i+'a';
			c = odd_char;
			odd_index = i;
		}
	}
	if(odd_cnt>1)
		return -1;
	for(int i = 0, knum = 0; i < len; i++)  
         if(s[i] == c)  
         {  
                if(knum == used[odd_index] / 2)  
                {  
                      s[i] = '*';  
                      c = '*';  
                      break;  
                 }++knum;  
         } 
	for(int i = 0;i<len/2;i++)
	{
		if(s[i] == c) // 遇到奇数字母就将其后移  
        {  
             char t = s[i];  
             s[i] = s[i + 1];  
             s[i + 1] = t;  
             ++cnt;  
        }  
        if(s[i] != s[len - 1 - i]) // 对应位置对应字母，从两端开始占据依次向中间夹逼  
        {  
			int j;
             for(j = len - 1 - i; j >= i + 1; j--)  
                 if(s[j] == s[i])  
                     break;  
             for(int k = j; k < len - 1 - i; k++)  
             {  
                  char t = s[k];  
                  s[k] = s[k + 1];  
                  s[k + 1] = t;  
                  ++cnt;  
              }  
         }
	}
	return cnt;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		memset(s,0,sizeof(s));
		memset(used,0,sizeof(used));
		gets(s);
		int res = get_ans();
		if(res==-1)
			printf("Impossible\n");
		else
			printf("%d\n",res);
	}
	return 0;
}

