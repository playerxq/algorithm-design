#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

struct point
{
    double x, y;
} po[700+2];
int cmp(const void *a, const void *b)
{
    point *aa = (point*)a, *bb = (point*)b;
    if(aa -> x != bb -> x)
        return aa -> x > bb -> x ? 1 : -1;
    return aa -> y > bb -> y ? 1 : -1;
}
int main()
{
freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

    int t, num;
    char a[100];
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        int max = 0;
        num = 0;
        while(gets(a))
        {
            if(!strlen(a))
                break;
            sscanf(a,"%lf %lf", &po[num].x, &po[num].y);
            ++num;
        }
        qsort(po, num, sizeof(po[0]), cmp);
        for(int i = 0; i < num; i++)
            for(int j = i + 1; j < num; j++)
            {
                int sum = 2;
                double k, b;
                if(!fabs(po[i].x - po[j].x) < 0.000001)
                {
                    k = (po[i].y - po[j].y) / (po[i].x - po[j].x);
                    b = -(po[i].y - po[j].y) / (po[i].x - po[j].x) * po[i].x + po[i].y;
                    for(int I = j + 1; I < num; I++)
                        if(fabs(po[I].y - k * po[I].x - b) < 0.000001)
                            sum++;
                }
                else                                // 要注意考虑斜率不存在的情况 
                    for(int I = j + 1; I < num; I++)
                        if((po[I].x - po[j].x) < 0.000001)
                            sum++;
                if(sum > max)
                    max = sum;
            }
        printf("%d\n",max);
        if(t)
            puts("");
    }
    return 0;
}