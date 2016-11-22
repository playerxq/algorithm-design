// uva1335-beijing guards.cpp : 定义控制台应用程序的入口点。
//n为偶数 答案为相邻两个人r和的最大值
//n为奇数 第一个人礼物是r 之后第i个人  i为偶数  取1:r的i-1没取的礼物 i为奇数 取r+1:p的没取的礼物

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
bool test(int p)//总数是p
{
	int x = r[1];//左半部份是r[1]即第一个人的礼物
	int y = p-r[1];//右半部分
	left[1]=x;
	right[1]=0;//left[i]为第i个人取的左半部份数目 right[i]为取右半部份数目
	for(int i = 2;i<=n;i++)
	{
		if(i%2==1)//奇数  尽量从右半部分取
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
	return left[n]==0;//第n个人不会取左半部份  则不会与第一个人的礼物（全部左半部份）冲突
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
