// uva-11054-wine trading.cpp : �������̨Ӧ�ó������ڵ㡣
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
int a[100001];
long long sum;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		memset(a,0,sizeof(a));
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sum = 0;
        for(int i=0;i<n-1;i++)//��i������i+1��������Ӷ�����i������
        {
            sum+=abs(a[i]);
            a[i+1]+=a[i];
        }
        printf("%lld\n",sum);
	}
	return 0;
}

