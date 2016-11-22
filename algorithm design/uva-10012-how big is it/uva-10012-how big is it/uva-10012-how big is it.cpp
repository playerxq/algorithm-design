// uva-10012-how big is it.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int num;
double radius[10];
double p[10];//Բ��λ��
double minx;
void swap_s(int a, int b)
{
	double temp = radius[a];
	radius[a] = radius[b];
	radius[b] = temp;
}

double point(int k){ //��k��Բ������
    double R = 0; 
    for(int j = 0 ; j < k ; j++){ //������ǰ�������԰����
        double tempr = p[j] + 2.0*sqrt(radius[k]*radius[j]);//����Բ�ľ��� d = sqrt((r1+r2)^2 - (r1-r2)^2) ��ô�� d  =  2.0*sqrt(r[k]*r[j]);     
        if(R < tempr)//����Ϊ��� 
            R = tempr; 
    } 
    return R; 
} 


void distance(){ 
    double high , low; 
    high = 0 ; low = 0; 
    for(int i = 0 ; i <num ; i++){ 
        if(p[i]-radius[i] < low)  low  = p[i] - radius[i];     //��������ߵ�λ�� 
        if(p[i]+radius[i] > high) high = p[i] + radius[i]; //�������ұߵ�λ�� 
    } 
    if(high - low < minx) 
        minx = high - low;//������С���� 
}
void dfs(int cur)
{
	if(cur==num)
	{
		distance();
	}
	else
	{
		for(int i = cur;i<num;i++)
		{
			swap_s(cur,i);
			double R = point(cur);
			if(R+radius[0]+radius[cur]<minx)
			{
				p[cur] = R;
				dfs(cur+1);
			}
			swap_s(cur,i);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = 0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&num);
		memset(radius,0,sizeof(radius));
		memset(p,0,sizeof(p));
		for(int i = 0;i<num;i++)
		{
			scanf("%lf",&radius[i]);
		}
		minx = 1<<30;
		dfs(0);
		printf("%.3lf\n",minx);
	}
	return 0;
}

