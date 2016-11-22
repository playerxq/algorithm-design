// uva-10714-nts.cpp : 定义控制台应用程序的入口点。
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
const int N = 1000001;
int len,num,pos;
int odd,mid;
int max_time,min_time;
int mid_l,mid_r;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&len,&num);
		odd = 0;
		max_time = min_time = -1;
		for(int i = 0;i<num;i++)
		{
			scanf("%d",&pos);
			int min_temp = pos<len-pos?pos:len-pos;
			int max_temp = pos>len-pos?pos:len-pos;
			max_time = max_time>max_temp?max_time:max_temp;
			min_time = min_time>min_temp?min_time:min_temp;
		}
	printf("%d %d\n",min_time,max_time);
	}
	return 0;
}

