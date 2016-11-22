// uva-507-jill rides again.cpp : 定义控制台应用程序的入口点。
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
int a[20001];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int ncase = 1;
	int f;
	int n;
	while(T--)
	{
		scanf("%d",&n);  
		 f=1;  
		 for (int i=1;i<n;i++)  
		 {  
			  scanf("%d",&a[i]);  
			  if (a[i]>0) f=0;  
		 }  
		 if (f) printf("Route %d has no nice parts\n",ncase++);  
		 else
		 {
			 int maxn = 0;
			 int s = 0;
			 int start = 1;
			 int end = 1;
			 int begin = 1;
			 for(int i = 1;i<n;i++)
			 {
				 s+=a[i];
				 if(s<0)
				 {
					 s = 0;
					 start = i+1;
				 }
				 if(s>maxn||(s==maxn&&end-begin<i-start))
				 {
					 maxn = s;
					 begin = start;
					 end = i;
				 }
			 }
			 printf("The nicest part of route %d is between stops %d and %d\n",ncase++,begin,end+1); 
		 }
	}
	return 0;
}

