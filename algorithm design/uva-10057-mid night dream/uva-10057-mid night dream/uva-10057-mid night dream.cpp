// uva-10057-mid night dream.cpp : �������̨Ӧ�ó������ڵ㡣
//�������ָ���Ϊż����ʱ��A�����м����������֮��ȡֵ
//����Ϊ������ʱ,A������λ����

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
const int N = 1000005;
int a[N];
void swap_s(int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int partion(int l,int r)
{
	int x = a[r-1];
	int i = l-1;
	for(int j = l;j<r;j++)
	{
		if(a[j]<x)
		{
			i++;
			swap_s(i,j);
		}
	}
	swap_s(i+1,r-1);
	return i+1;//�����ڶ��������е�һ������
}
int select_k(int k, int l, int r)//l:r-1 ��k��  
{
	if(l==r-1)
		return a[l];
	int q = partion(l,r);
	int x = q-l+1;
	if(x==k)
		return a[q];
	else if(x>k)
		return select_k(k,l,q);
	else
		return select_k(k-x,q+1,r);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	int i,min,max,sum,count;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int mid = 0;
		if(n%2)
		{
			mid = select_k(n/2+1,0,n);
		}
		else
		{
			mid = select_k(n/2,0,n);
		}
		sort(a,a+n);
		if(n%2)
		{
			sum = 1;//һ����λ��
			min = mid;//��λ��
			max = min;
		}
		else 
		{
			sum=a[n/2]-a[n/2-1]+1; 
			min=a[n/2-1];
			max=a[n/2];
		}
		count=0;  //��λ������
	  for (i=0;i<n;i++)  
	  {  
		   if ((a[i]>=min)&&(a[i]<=max)) 
			   ++count;  
		   if (a[i]>max) break;  
	  }  
	 printf("%d %d %d\n",min,count,sum);  
	}
	return 0;
}

