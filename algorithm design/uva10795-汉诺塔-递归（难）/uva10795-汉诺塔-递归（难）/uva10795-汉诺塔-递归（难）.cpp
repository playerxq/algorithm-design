// uva10795-汉诺塔-递归（难）.cpp : 定义控制台应用程序的入口点。
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
long long f(int* P, int i, int final)//将P上1：i号盘子移动到final上 
{
	if(i==0) return 0;
	if(P[i]==final) return f(P,i-1,final);//最大的盘子已经在final上 
	return f(P,i-1,6-P[i]-final)+(1LL<<(i-1));//先将1:i-1号移动到第三根棍子上（1，2，3号棍子，一根等于6减去另外两根和）再将i号移动到final上，再将1:i-1移动到final上
	//其中，将1：i-1是整体移动到final上，一共需要2^(j-1)-1步，加上移动i的那步  正好是2^(j-1)
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
		while(k>=1&&start[k]==finish[k]) k--;//找到最大需要移动的盘子  大于k的都不需要考虑
		long long ans = 0;
		if(k>=1)
		{
			int other=6-start[k]-finish[k];
			ans = f(start,k-1,other)+f(finish,k-1,other)+1;//从other将其他1:k-1个盘子移动到finish上等价于从finish移动到other 对称性
		}
		printf("Case %d: %lld\n",++kase,ans);
	}
}

