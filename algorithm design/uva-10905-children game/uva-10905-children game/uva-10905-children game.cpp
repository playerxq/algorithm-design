#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char num[55][100];

int n;
void init()
{
    for( int i = 0; i < n; i ++)
        scanf( "%s", num[i]);
}

void output()
{
    for( int i = 0; i < n; i ++)
        printf( "%s", num[i]);
    printf("\n");
}


int cmp( const void *_p, const void *_q)
{
    char s1[500], s2[500];
    char *p = (char *)_p;
    char *q = (char *)_q;
    strcpy( s1, p);
    strcat( s1, q);
    strcpy( s2, q);
    strcat( s2, p);
    return strcmp( s1, s2) < 0 ? 1 : -1;
}

int main()
{
    while(true)
    {
        scanf( "%d", &n);
        if( !n) break;
        init();
        qsort( num, n, sizeof(num[0]), cmp);
        output();
    }
    return 0;
}