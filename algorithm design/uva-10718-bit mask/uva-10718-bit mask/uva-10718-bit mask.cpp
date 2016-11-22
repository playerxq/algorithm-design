// uva-10718-bit mask.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>

using namespace std;

void D_bite(char *str, unsigned long long num) // 将数字化成二进制
{
    if(!num)
        str[0] = '0';
    else
        for(int i = 0; num; i++)
        {
            str[i] = num % 2 + '0';
            num /= 2;
        }
}
unsigned long long B_dight(char *str, int len) // 将二进制化成数字
{
    unsigned long long num = 0;
    for(int i = 0; i < len; i++)
        if(str[i] == '1')
            num += (1LL << i);
    return num;
}
int main()
{
    unsigned long long l, u, n;
    char U[65], M[65], L[65], N[65];
    while(scanf("%llu%llu%llu", &n, &l, &u) != EOF)
    {
        memset(U, 0, sizeof(U));
        memset(N, 0, sizeof(N));
        memset(M, 0, sizeof(M));
        memset(L, 0, sizeof(L));
        D_bite(U, u);//均转化为2进制
        D_bite(L, l);
        D_bite(N, n);
        int len_u = strlen(U), len_m = len_u, len_l = strlen(L);
        M[len_m - 1] = '1';//最高位为1
        if(!u)  // 当上界为0时，需要特殊处理
            M[len_m - 1] = '0';
        while(1)
        {
            if(N[len_m-1]=='1'&&len_m>len_l)
			{
				--len_m;
				M[len_m] = '\0';
				M[len_m-1] = '1';
			}
			else
				break;
        }
        int ffct = len_m - 1;
        for(int i = 0; i < len_m - 1; i++)
            M[i] = '0';
        while(ffct >= 0)//从高位向低位考虑
        {
            if(N[ffct] != '1')//N对应位为0 M尽量为1 不超过U
            {
                M[ffct] = '1';
                if(B_dight(M, len_m) > u) // 相应位置赋为‘1’时，考虑是否超上界
                    M[ffct] = '0';
            }
            else
            {
                M[ffct] = '0';//N为1 M尽量为0
                if(B_dight(M, len_m) < l) // 相应位置赋为‘0’时，考虑是否超下界
                {
                    memset(M, '1', sizeof(M[0]) * ffct);//当前位为0小于L  将0:ffct-1即当前位之前所有位置1(之前为0) 即考虑当前位0时的最大可能值
                    if(B_dight(M, len_m) < l)//依然小于L 当前位必须为1
                        M[ffct] = '1';
                    memset(M, '0', sizeof(M[0]) * ffct);//前面所有位恢复0
                }

            }
            --ffct;
        }
        printf("%llu\n", B_dight(M, len_m));
    }
    return 0;
}

