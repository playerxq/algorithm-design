// uva10795-��ŵ��-�ݹ飨�ѣ�.cpp : �������̨Ӧ�ó������ڵ㡣
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
long long f(int* P, int i, int final)//��P��1��i�������ƶ���final�� 
{
	if(i==0) return 0;
	if(P[i]==final) return f(P,i-1,final);//���������Ѿ���final�� 
	return f(P,i-1,6-P[i]-final)+(1LL<<(i-1));//�Ƚ�1:i-1���ƶ��������������ϣ�1��2��3�Ź��ӣ�һ������6��ȥ���������ͣ��ٽ�i���ƶ���final�ϣ��ٽ�1:i-1�ƶ���final��
	//���У���1��i-1�������ƶ���final�ϣ�һ����Ҫ2^(j-1)-1���������ƶ�i���ǲ�  ������2^(j-1)
}
const int maxn=60+10;
int n, start[maxn],finish[maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int kase = 0;
	while(scanf("%d",&n)==1&&n)
	{
		for(int i = 1;i<=n;i++)
			scanf("%d",&start[i]);
		for(int i = 1;i<=n;i++)
			scanf("%d",&finish[i]);
		int k = n;
		while(k>=1&&start[k]==finish[k]) k--;//�ҵ������Ҫ�ƶ�������  ����k�Ķ�����Ҫ����
		long long ans = 0;
		if(k>=1)
		{
			int other=6-start[k]-finish[k];
			ans = f(start,k-1,other)+f(finish,k-1,other)+1;//��other������1:k-1�������ƶ���finish�ϵȼ��ڴ�finish�ƶ���other �Գ���
		}
		printf("Case %d: %lld\n",++kase,ans);
	}
}

