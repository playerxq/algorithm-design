// uva-10706-number sequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int MAX = 100000;
long long num[MAX];
int t,n;
void init()
{
	long long i , j , k , tmp;
	memset(num,0,sizeof(num));
	for(i = 1;i<6;i++)//���5λ��
	{
		for( j = pow(10.0,(double)i-1);j<pow(10.0,(double)i);j++)//����iλ��
		{
			num[j] = num[j-1];
			//�ۼ�1��j��λ����
			tmp = (j-pow(10,(double)i-1)+1)*i;//һ��(j-pow(10,i-1)+1)��iλ��  
			for(k = 1 ; k < i ; k++) 
                tmp +=(pow(10.0,(double)k)-pow(10.0,(double)k-1))*k; //ǰ���
            num[j] += tmp; 
		}
	}
}
void solve()
{
	int i , j , k , pos , ans; 
    //�ҵ�posλ�� 
    for(i = 1 ; i < MAX; i++){ 
        if(n > num[i-1] && n <= num[i]){ 
            pos = i ; break; 
        } 
    }
	int cnt = n-num[pos-1] ; //��ǰpos��Ӧ���Ӵ��е�λ��
	int sum = 0; 
    int len , tmp , tmp_j; 
	for(int j = 1;j<=pos;j++)//pos�Ӵ���ÿһ����1��pos  ��λ��
	{
		tmp_j = j;
		len = 0;
		for(i = tmp_j;i!=0;i/=10) len++;
		for(k = len-1;k>=0;k--)//�Ե�ǰ���ĵ�ǰλ
		{
			ans = tmp_j/pow(10.0,(double)k);
			sum++;
			if(sum == cnt){             
                printf("%d\n" , ans); 
                return; 
            } 
            tmp = pow(10.0,(double)k) ; 
			tmp_j %=tmp; 
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	scanf("%d" , &t);  
    while(t--){ 
        scanf("%d" , &n) ;
		solve(); 
    } 
    return 0; 
	return 0;
}

