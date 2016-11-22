// uva-714-coping books.cpp : 定义控制台应用程序的入口点。
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
const int MAXN = 505;
int m, k;  
long long a[MAXN], sum, minx, ans;  
bool vis[MAXN];
int divide(long long mid)
{
	memset(vis, 0, sizeof(vis));  
    int cnt=0;  
    int pos=m-1; 
	while(pos>=0)
	{
		long long sum=0;  
        bool ok=true;
		while(pos>=0&&sum+a[pos]<=mid)//尽可能从右端划分最接近目标的区间
		{
			sum+=a[pos];
			ok = false;
			pos--;
		}
		if(ok)
			return k+1;
		if(pos>=0)
			vis[pos] = 1;//pos后加一个划分
		cnt++;
	}
	return cnt;
}
long long binary()
{
	long long left=minx, right=sum, mid;  
    while(left<right){  
        mid = (left+right)>>1;  
        if(divide(mid)<=k)   
            right=mid;  
        else   
            left=mid+1;  
    }  
    return right;//最小的可能区间最大值 
}
void output(){  
    int cnt=divide(ans);  
    for(int i=0; i<m-1&&cnt<k; ++i)if(!vis[i]){  //尽可能在左端添加划分
        vis[i]=true;  
        ++cnt;  
    }   
    for(int i=0; i<m; ++i){  
        if(i) printf(" %lld",a[i]);  
        else printf("%lld",a[i]);  
        if(vis[i]){  
            printf(" /");  
        }  
    }  
    puts("");  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&k);
		memset(a,0,sizeof(a));
		sum = 0;
		minx = 10000001;
		for(int i = 0;i<m;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
			if(a[i]<minx)
				minx = a[i];
		}
		ans = binary();
		output();
	}
	return 0;
}

