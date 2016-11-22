// uva-1508-equipment.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <cmath>
//#define ll long long
#define inf 1e9
#define maxn 110
using namespace std;

int ma[10];
int val[10010][10];
int N,K;
int pp[1<<6];

int DP(int st,int num)//�Ե�ǰѡȡ��ʽ  һ����ĳ��Ԫ�汻ѡ����״̬Ϊst ��ö��st���Ӽ���Ϊnum+1:kʣ��Ԫ��  ÿ���Ӽ��൱��ĳ��Ԫ�汻���Ӽ���ʽѡ�� ����pp[pos]����pos��ʽ�����ֵ  ��ʱҲӦ��ѡ����pos��ʽ�¿��Եõ����͵�Ԫ��  ��Ȼ����pp[pos]
{
    if(num==K)
    {
        return 0;
    }

    int i,j;
    int temp=0;
    for(i=st;i;i=(i-1)&st)
    {
        temp=max(temp,pp[i]+DP(st^i,num+1));
    }
    return temp;
}
//5Ԫ��  ȫѡΪ11111Ϊ31
int main()
{
	
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 //   freopen("input.txt","r",stdin);
    int i,j,k;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&K);
        memset(ma,0,sizeof(ma));
        memset(pp,0,sizeof(pp));
        for(i=0;i<N;i++)
        {
            for(j=0;j<5;j++)
            {
                scanf("%d",&val[i][j]);
                ma[j]=max(ma[j],val[i][j]);
            }
            for(j=0;j<32;j++)//��ÿ������  ��pos:11111-00000ö���ܲ����ĺ�  pp[pos]���浱ǰѡȡ��ʽ�µ����ֵ��
            {
                int temp=0;
                for(k=0;k<5;k++)
                {
                    if(j&(1<<k))
                    {
                        temp+=val[i][k];
                    }
                }
                pp[j]=max(pp[j],temp);
            }
        }
        if(K>=5)
        {
            int ans=0;
            for(j=0;j<5;j++)
            {
                ans+=ma[j];
            }
            printf("%d\n",ans);
        }
        else
        {
            printf("%d\n",DP(31,0));
        }
    }
    return 0;
}

