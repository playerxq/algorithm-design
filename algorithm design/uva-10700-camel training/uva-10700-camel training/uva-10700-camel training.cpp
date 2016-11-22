// uva-10700-camel training.cpp : �������̨Ӧ�ó������ڵ㡣
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
		memset(mup, 0, sizeof(mup));    //�����ȼӵ�ֵ ����
        memset(add, 0, sizeof(add));//�ȳ˵�ֵ  ����
		char c = '+';
		add_index = -1, mup_index = 0;
		while(c!='\n')
		{
			scanf("%lld",&num);
			if(c=='+')//֮ǰ��+
			{
				add[++add_index] = num;//��Сֵʱ �ȳ��ټ�
				mup[mup_index]+=num;//���ֵ �ȼ�
			}
			else 
				mup[++mup_index] = num, add[add_index] *= num;    //�˺�ʱ  add[]��ʾ�ȳ˺��
            scanf("%c", &c); 
		}
		max = 1, min = 0;    
        for (int i = 0; i <= mup_index; ++i) max *= mup[i];    //�ȼ��ٳ�
        for (int i = 0; i <= add_index; ++i) min += add[i];    //�ȳ��ټ�
        printf("The maximum and minimum are %lld and %lld.\n", max, min);
	}
	return 0;
}

