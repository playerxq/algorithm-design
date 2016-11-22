// uva1335-beijing guards.cpp : �������̨Ӧ�ó������ڵ㡣
//nΪż�� ��Ϊ����������r�͵����ֵ
//nΪ���� ��һ����������r ֮���i����  iΪż��  ȡ1:r��i-1ûȡ������ iΪ���� ȡr+1:p��ûȡ������

#include "stdafx.h"
#include <cstdio>
#include <string.h>
#include <math.h>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int maxn = 100000+10;
int n,r[maxn],left[maxn],right[maxn];
bool test(int p)//������p
{
	int x = r[1];//��벿����r[1]����һ���˵�����
	int y = p-r[1];//�Ұ벿��
	left[1]=x;
	right[1]=0;//left[i]Ϊ��i����ȡ����벿����Ŀ right[i]Ϊȡ�Ұ벿����Ŀ
	for(int i = 2;i<=n;i++)
	{
		if(i%2==1)//����  �������Ұ벿��ȡ
		{
			right[i]=min(y-right[i-1],r[i]);
			left[i]=r[i]-right[i];
		}
		else
		{
			left[i]=min(x-left[i-1],r[i]);
			right[i]=r[i]-left[i];
		}
	}
	return left[n]==0;//��n���˲���ȡ��벿��  �򲻻����һ���˵����ȫ����벿�ݣ���ͻ
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)==1&&n)
	{
		for(int i = 1;i<=n;i++)
			scanf("%d",&r[i]);
		if(n==1)
		{
			printf("%d\n",r[1]);
			continue;
		}
		r[n+1]=r[1];
		int L = 0;int R = 0;
		for(int i = 1;i<=n;i++)
			L = max(L,r[i]+r[i+1]);
		if(n%2==1)
		{
			for(int i = 1;i<=n;i++)
				R = max(R,3*r[i]);
			while(L<R)
			{
				int M = L+(R-L)/2;
				if(test(M))
					R = M;
				else
					L = M+1;
			}
		}
		printf("%d\n",L);
	}
}
