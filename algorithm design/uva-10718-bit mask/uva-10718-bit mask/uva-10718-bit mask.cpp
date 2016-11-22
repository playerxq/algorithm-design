// uva-10718-bit mask.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>

using namespace std;

void D_bite(char *str, unsigned long long num) // �����ֻ��ɶ�����
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
unsigned long long B_dight(char *str, int len) // �������ƻ�������
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
        D_bite(U, u);//��ת��Ϊ2����
        D_bite(L, l);
        D_bite(N, n);
        int len_u = strlen(U), len_m = len_u, len_l = strlen(L);
        M[len_m - 1] = '1';//���λΪ1
        if(!u)  // ���Ͻ�Ϊ0ʱ����Ҫ���⴦��
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
        while(ffct >= 0)//�Ӹ�λ���λ����
        {
            if(N[ffct] != '1')//N��ӦλΪ0 M����Ϊ1 ������U
            {
                M[ffct] = '1';
                if(B_dight(M, len_m) > u) // ��Ӧλ�ø�Ϊ��1��ʱ�������Ƿ��Ͻ�
                    M[ffct] = '0';
            }
            else
            {
                M[ffct] = '0';//NΪ1 M����Ϊ0
                if(B_dight(M, len_m) < l) // ��Ӧλ�ø�Ϊ��0��ʱ�������Ƿ��½�
                {
                    memset(M, '1', sizeof(M[0]) * ffct);//��ǰλΪ0С��L  ��0:ffct-1����ǰλ֮ǰ����λ��1(֮ǰΪ0) �����ǵ�ǰλ0ʱ��������ֵ
                    if(B_dight(M, len_m) < l)//��ȻС��L ��ǰλ����Ϊ1
                        M[ffct] = '1';
                    memset(M, '0', sizeof(M[0]) * ffct);//ǰ������λ�ָ�0
                }

            }
            --ffct;
        }
        printf("%llu\n", B_dight(M, len_m));
    }
    return 0;
}

