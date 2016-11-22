// uva-10132-file fragmentation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 310
#define LEN 610

char word[LEN];
struct file
{
   char s[LEN];
   int len;
}a[N];
int n,L;

int cmp(struct file x ,struct file y)
{
   return x.len < y.len;
}

int BF()
{
   int count = 0;
   bool used[N];
   char str[LEN];
   memset(used,false,sizeof(used));
   for(int i=0; i<n; i++)
      if(!used[i])
      {
         int ok = 0;
         for(int j=n-1; j>i; j--)
            if(!used[j] && a[i].len + a[j].len == L)
            {
               strcpy(str,a[i].s);
               strcat(str,a[j].s);
               if( !strcmp(word,str) )
               {
                  used[i] = used[j] = true;
                  ok = 1;
                  break;
               }

               strcpy(str,a[j].s);
               strcat(str,a[i].s);
               if( !strcmp(word,str) )
               {
                  used[i] = used[j] = true;
                  ok = 1;
                  break;
               }
            }
         if(!ok) break;//当前i没有配对 错误的word
         count ++;
      }

   if(count == (n/2)) return 1;
   else               return 0;
}

void solve()
{
   int i,j;
   int ok=0;
   for(i=0; a[i].len==a[0].len; i++)//找到当前最长与最短串拼接成目标串
      for(j=n-1; a[j].len==a[n-1].len; j--)
      {
         strcpy(word,a[i].s);
         strcat(word,a[j].s);
         if(BF())
         {
            ok=1;
            break;
         }

         strcpy(word,a[j].s);
         strcat(word,a[i].s);
         if(BF())
         {
            ok=1;
            break;
         }
      }
   printf("%s\n",word);
}

int main()
{
   int T;
   scanf("%d",&T);
   getchar(); getchar();
   while(T--)
   {
      n = 0;
      while(1)
      {
         if( !gets(a[n].s) )        break;
         if( !strcmp(a[n].s , "") ) break;
         a[n].len = strlen(a[n].s);
         n++;
      }
      sort(a,a+n,cmp);
      L = a[0].len + a[n-1].len;
      solve();
      if(T) printf("\n");
   }
   return 0;
}

