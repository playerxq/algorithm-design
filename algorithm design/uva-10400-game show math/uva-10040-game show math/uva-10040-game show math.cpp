// uva-10040-game show math.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

bool vis[100][64001];
int num, save[101], flag;
char expo[100];
void dfs(int cur, int sum)
{
    if(cur == num)
    {
        if(sum == save[num])//达到目标
            flag = 1;
        return ;
    }
    int ans = sum + save[cur];
    expo[cur - 1] = '+';
    if(ans <= 32000 &&
       ans >= -32000 && // 判断是否超出范围
      !vis[cur][ans + 32000]
      )
    {
        vis[cur][ans + 32000] = true;
        dfs(cur + 1, ans);
        if(flag)
            return ;
    }
    ans = sum - save[cur];
    expo[cur - 1] = '-';
    if(ans >= -32000 &&
       ans <= 32000 &&
      !vis[cur][ans + 32000]
      )
    {
        vis[cur][ans + 32000] = true;
        dfs(cur + 1, ans);
        if(flag)
            return ;
    }
    ans = sum * save[cur];
    expo[cur - 1] = '*';
    if(ans <= 32000 &&
       ans >= -32000 &&
      !vis[cur][ans + 32000]
      )
    {
        vis[cur][ans + 32000] = true;
        dfs(cur + 1, ans);
        if(flag)
            return ;
    }
    ans = sum / save[cur];
    expo[cur - 1] = '/';
    if(!vis[cur][ans + 32000])
    {
        vis[cur][ans + 32000] = true;
        dfs(cur + 1, ans);
        if(flag)
            return ;
    }
}
int main()
{
#ifdef test
    freopen("sample.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    while(n--)
    {
        flag = 0;
        scanf("%d", &num);
        memset(vis, false, sizeof(vis));
        for(int i = 0; i <= num; i++)
            scanf("%d", &save[i]);
        dfs(1, save[0]);
        if(flag)
        {
            expo[num - 1] = '=';
            for(int i = 0; i < num; i++)
                printf("%d%c", save[i], expo[i]);
            printf("%d\n", save[num]);
        }
        else
            printf("NO EXPRESSION\n");
    }
    return 0;
}

