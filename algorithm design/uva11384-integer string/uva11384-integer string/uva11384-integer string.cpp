// uva11384-integer string.cpp : 定义控制台应用程序的入口点。
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
int f(int n)
{
	return n==1?1:f(n/2)+1;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n;
	while(scanf("%d",&n)==1)
		printf("%d\n",f(n));
}

