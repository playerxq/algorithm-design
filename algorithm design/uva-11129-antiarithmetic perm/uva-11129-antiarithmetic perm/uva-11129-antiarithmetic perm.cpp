// uva-11129-antiarithmetic perm.cpp : 定义控制台应用程序的入口点。
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
#define M 10010  
int n, a[M], b[M];  
void dfs(int s, int t)  
{  
    int i = s;  
    if(s==t) return;  
    for(int j = s; j <= t; j++) b[j] = a[j];  
    for(int j = s; j <= t; j+=2,i++) a[i] = b[j];  
    for(int j = s+1; j <= t; j+=2,i++) a[i] = b[j];  
    dfs(s,(s+t)/2);  
    dfs((s+t)/2+1,t);  
}  
int main ()  
{  
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n;  
    while(scanf("%d",&n),n)  
    {  
        for(int i = 0; i < n; i++) a[i] = i;  
        dfs(0,n-1);  
        printf("%d:",n);  
        for(int i = 0; i < n; i++) i?printf(" %d",a[i]):printf("%d",a[i]);  
        printf("\n");  
    }  
    return 0;  
}

