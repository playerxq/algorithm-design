// uva-10318-security panel.cpp : 定义控制台应用程序的入口点。
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


const int N = 10;

int r, c, n, d[N][2], cnt[N], vis[N][N], rec[N][N];
char g[N][N];

void init() {
	n = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	memset(rec, 0, sizeof(rec));

	for (int i = 0; i < 3; i++) {//输入开关模式
		scanf("%s", g[i]);
		for (int j = 0; j < 3; j++) if (g[i][j] == '*') {
			d[n][0] = i - 1; d[n][1] = j - 1;//各个方向可以改变状态的点
			n++;
		}
	}
}

void put() {
	int p = 0, path[50];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) if (rec[i][j]) {
			path[p++] = i * c + j + 1;
		}
	for (int i = 0; i < p - 1; i++) printf("%d ", path[i]);
	printf("%d\n" , path[p-1]);
}

void clear(int x, int y) {
	for (int i = 0; i < n; i++) {
		int p = x + d[i][0], q = y + d[i][1];
		if (p < 0 || p >= r || q < 0 || q >= c) continue;
		if (vis[p][q])	cnt[p]--;//已经开灯  当前行上开灯数-1
		else   cnt[p]++;
		vis[p][q] = vis[p][q] ? 0 : 1;//切换状态
	}
}

bool dfs(int x, int y) {
	if (y == c) { 
		x += 1; y = 0;//下一行
		if (x >= 2 && cnt[x - 2] != c) return false;//当前行无法让x-2行的状态改变  故如果x-2行上有没开灯的  返回false
	}

	if (x == r) {
		if (cnt[x - 1] != c) return false;
		put();
		return true;
	}

	if (dfs(x, y + 1)) return true;

	rec[x][y] = 1; clear(x, y); //开灯  改变状态
	if (dfs(x, y + 1)) return true;
	rec[x][y] = 0; clear(x, y);//恢复状态

	return false;	
}

int main () {
	int cas = 1;
	while (scanf("%d%d", &r, &c) == 2 && r + c) {
		init();
		printf("Case #%d\n", cas++);
		if (!dfs(0, 0)) printf("Impossible.\n");
	}
	return 0;
}

