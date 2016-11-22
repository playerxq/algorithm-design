// uva-10670-work reduction.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

struct agency
{
    int A, B, V;
    char name[20];
} gen[102];
int cmp(const void *a, const void *b)
{
    agency *aa = (agency*)a;
    agency *bb = (agency*)b;
    if(aa->V != bb->V)
        return aa->V - bb->V;
    return strcmp(aa->name, bb->name);
}
int main()
{
    int t;
    char str[50];
    scanf("%d", &t);
    for(int k = 1; k <= t; k++)
    {
        int N, M, num;
        scanf("%d%d%d", &N, &M, &num);
        for(int i = 0; i < num; i++)
        {
            scanf("%s", str);
            sscanf(str, "%[^:]:%d,%d",gen[i].name, &gen[i].A, &gen[i].B);
        }
        for(int i = 0; i < num; i++)//考虑第i个机构
        {
            int tem_a = 0, tem_b = 0, n = N;
            while(n / 2 >= M && gen[i].A * (n / 2) > gen[i].B) // 能减半则尽可能减半
            {
                n /= 2;
                ++tem_b;
            }
            tem_a = n - M;//剩下的由A完成
            gen[i].V = tem_b * gen[i].B + tem_a * gen[i].A;
        }
        qsort(gen, num, sizeof(gen[0]), cmp);
        printf("Case %d\n", k);
        for(int i = 0; i < num; i++)
            printf("%s %d\n", gen[i].name, gen[i].V);
    }
    return 0;
}


