// uva-10148-advertisement.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

struct point
{
    int x, y;
} pot[1002];
int cmp(const void *a, const void *b)
{
    point *aa = (point *)a;
    point *bb = (point *)b;
    if(aa->y != bb->y)
        return aa->y > bb->y ? 1 : -1;//x y������
    return aa->x > bb->x ? 1 : -1;
}
int ascend_cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
const int chr = 10000;
int main()
{
    int t, k, n, save[20002], flag[20002];
    scanf("%d", &t);
    while(t--)
    {
        int cct = 0, xx, yy;
        scanf("%d%d", &k, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &xx, &yy);
            if(xx < yy)  // ��֤���е���˵㶼С���Ҷ˵�
            {
                pot[i].x = xx;
                pot[i].y = yy;
            }
            else
            {
                pot[i].x = yy;
                pot[i].y = xx;
            }
        }
        qsort(pot, n, sizeof(pot[0]), cmp);
        memset(flag, 0, sizeof(flag));
        for(int i = 0; i < n; i++)
        {
            int fct = 0;
            for(int j = pot[i].x; j <= pot[i].y; j++) // ���˶��������ж��ٵ����Ѿ�����ע����
                if(flag[j + chr])//-10000ƫ�Ƶ�0
                {
                    fct++;
                    if(fct == k)
                        break;
                }
            if(fct == k)
                continue;
            for(int j = pot[i].y; j >= pot[i].x; j--)//�Ӻ���ǰȡ
            {
                if(!flag[j + chr])
                {
                    flag[j + chr] = 1;
                    save[cct++] = j;
                    fct++;
                }
                if(fct == k)
                    break;
            }
        }
        qsort(save, cct, sizeof(save[0]), ascend_cmp);
        printf("%d\n", cct);
        for(int i = 0; i < cct; i++)
            printf("%d\n", save[i]);
        if(t)
            puts("");
    }
    return 0;
}

