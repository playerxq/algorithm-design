// uva-10700-camel training.cpp : 定义控制台应用程序的入口点。
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

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	long long  max, min, num, mup[15], add[15];    
	int add_index = 0;
	int mup_index = 0;
	scanf("%d",&n);
	while(n--)
	{
		memset(mup, 0, sizeof(mup));    //保存先加的值 最后乘
        memset(add, 0, sizeof(add));//先乘的值  最后加
		char c = '+';
		add_index = -1, mup_index = 0;
		while(c!='\n')
		{
			scanf("%lld",&num);
			if(c=='+')//之前是+
			{
				add[++add_index] = num;//最小值时 先乘再加
				mup[mup_index]+=num;//最大值 先加
			}
			else 
				mup[++mup_index] = num, add[add_index] *= num;    //乘号时  add[]表示先乘后加
            scanf("%c", &c); 
		}
		max = 1, min = 0;    
        for (int i = 0; i <= mup_index; ++i) max *= mup[i];    //先加再乘
        for (int i = 0; i <= add_index; ++i) min += add[i];    //先乘再加
        printf("The maximum and minimum are %lld and %lld.\n", max, min);
	}
	return 0;
}

