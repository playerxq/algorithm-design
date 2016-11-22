// uva-10720-graph construct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>

using namespace std;

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int a[10002];
int solve(int num)
{
    for(int i = 0; i < num; i++)
    {
        qsort(&a[i], num - i, sizeof(a[0]), cmp);
        if(a[i] >= num)  // ��ĳһ��Ķ������ڵ��ڵ�ĸ�������ֱ����Ϊ 0
            return 0;
        if(!a[i]) // ��֦
            return 1;
        for(int j = i + 1; j <= a[i] + i; j++)
        {
            --a[j];
            if(a[j] < 0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        if(solve(n))
            printf("Possible\n");
        else
            printf("Not possible\n");

    }
    return 0;
}

