// uva-1508-equipment.cpp : 定义控制台应用程序的入口点。
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

int DP(int st,int num)//对当前选取方式  一定是某个元祖被选中且状态为st 则枚举st的子集作为num+1:k剩余元祖  每个子集相当于某个元祖被按子集方式选中 由于pp[pos]保存pos方式的最大值  此时也应该选的是pos方式下可以得到最大和的元祖  自然就是pp[pos]
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
//5元组  全选为11111为31
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
            for(j=0;j<32;j++)//对每个类型  从pos:11111-00000枚举能产生的和  pp[pos]保存当前选取方式下的最大值和
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

