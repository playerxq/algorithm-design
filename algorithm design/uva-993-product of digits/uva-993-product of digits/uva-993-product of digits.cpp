// uva-993-product of digits.cpp : 定义控制台应用程序的入口点。
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
int a[10];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		if(!n)
			printf("0\n");
		else if(n==1)
			printf("1\n");
		else
		{
			for(int i = 9;i>=2;i--)
			{
				while(1)
				{
					if(n%i)
						break;
					n/=i;
					a[i]++;
				}
			}
			if(n == 1)  
                for(int i = 2; i < 10; i++)  
                    for(int j = 0; j < a[i]; j++)  
                        printf("%d", i);  
            else  
                printf("-1");
			printf("\n");
		}
	}
	return 0;
}

