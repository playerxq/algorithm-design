// uva-10245-most closet pair.cpp : 定义控制台应用程序的入口点。
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
int n;
struct POINT   
{  
    double x,y;  
}point[10010],temp[10010];
double dis(struct POINT p1, struct POINT p2)  
{  
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));  
}
int cmp(const void * a, const void * b)  
{  
    struct POINT * c = (struct POINT *)a;  
    struct POINT * d = (struct POINT *)b;  
    if (c->x != d->x)  
    {  
        return c->x > d->x;  
    }  
    else  
        return c->y > d->y;  
}
int cmp1(const void * a, const void * b)  
{  
    struct POINT * c = (struct  POINT *)a;  
    struct POINT * d = (struct  POINT *)b;  
    if (c->y != d->y)  
    {  
        return c->y > d->y;  
    }  
    else  
        return c->x > d->x;  
}
double findMin(int l, int r)  
{  
    if (l == r)  
    {  
        return 10010;  
    }  
    if (l == r - 1)  
    {  
        return dis(point[l], point[r]);  
    }  
    double tmp1 = findMin(l,l+(r-l)/2);  
    double tmp2 = findMin(l+(r-l)/2+1, r);  
    double Mindis,tmp, mid;  
    mid = point[l+(r-l)/2].x;
    int i,j,cnt = 0;  
    if (tmp1 < tmp2)  
    {  
        Mindis = tmp1;  
    }  
    else  
        Mindis = tmp2;  
    for (i = l; i <= r; ++ i)  //只需考虑与中点距离小于mindis的点
    {  
        if (fabs(point[i].x - mid) < Mindis)  
        {  
            temp[cnt ++] = point[i];  
        }  
    }  
    qsort(temp, cnt, sizeof(temp[0]), cmp1);  //按y升序排序
    for (i = 0; i < cnt - 1; ++ i)  
    {  
        for (j = i + 1; j < i + 7 && j < cnt; ++ j)  
        {  
            tmp = dis(temp[i], temp[j]);  
            if (tmp < Mindis)  
            {  
                Mindis = tmp;  
            }  
        }  
    }  
    return Mindis;  
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	double minDis;
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		for(int i = 0;i<n;i++)
			scanf("%lf%lf", &point[i].x, &point[i].y);
		qsort(point, n, sizeof(point[0]), cmp);
		minDis = findMin(0, n-1);
		if (minDis > 10000)  
        {  
            printf("INFINITY\n");  
        }  
        else  
            printf("%.4lf\n", minDis); 
	}
	return 0;
}
