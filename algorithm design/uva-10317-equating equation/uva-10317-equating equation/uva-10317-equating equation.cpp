// uva-10317-equating equation.cpp : �������̨Ӧ�ó������ڵ㡣
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


const int N = 100;

bool pom[2][N];	// plus or minus, 0 is plus, 1 is minus
int lterm, rterm;
char eqt[N];
int sum, num[N], cnt, mcnt;
bool choose[N];

void init() {
	char tmp[4];
	int len = strlen(eqt), prev = 0, dpom = 0, npom = 0;
	cnt = 0;
	mcnt = 0;
	sum = 0;
	for (int i = 0; i < len; ) {
		sscanf(eqt + i, "%s", tmp);
		if (tmp[0] == '+') {
			pom[dpom][npom++] = 0;
			prev = 0;
		} else if (tmp[0] == '-') {
			pom[dpom][npom++] = 1;
			prev = 1;
		} else if (tmp[0] == '=') {
			dpom++;
			lterm = npom;
			npom = 0;
			prev = 0;
		} else {
			mcnt += dpom ^ prev;//dpom=1˵���ڵ�ʽ�ұ� �����߱��  prevΪ��ǰ����ǰһ������ ��dpom���Ϊ�����ķ��� mcnt��¼�������ߵļ���������Ŀ
			sscanf(tmp, "%d", &num[cnt]);
			sum += num[cnt];
			cnt++;
		}
		i += strlen(tmp) + 1;
	}
	rterm = npom;
}

bool dfs(int restsum, int pos, int restcnt) {//restcnt�����������  ��͵��ڲ���ӷ������ֺ�  restsumΪ�����ֵĸ��Ժ� ���
	if (restcnt == 0)
		return restsum == 0;
	if (restsum < 0 || restcnt < 0)
		return false;
	for (int i = pos; i <= cnt - restcnt; i++) {//ѡ��pos:cnt-1�е�һ����Ϊ��������  ��֤ʣ���������ٻ���restcnt-1����������Ϊ��������
		choose[i] = 1;
		if (dfs(restsum - num[i], i + 1, restcnt - 1))
			return true;
		choose[i] = 0;
	}
	return false;
}

bool solve() {
	memset(choose, 0, sizeof(choose));
	if (sum % 2) {
		return false;
	}
	return dfs(sum / 2, 0, mcnt);
}

void print() {
	int p[N], m[N], pcnt = 0, mcnt = 0;
	for (int i = 0; i < cnt; i++) {
		if (choose[i]) {
			m[mcnt++] = num[i];//һ��ѡ����Ϊ��������
		} else {
			p[pcnt++] = num[i];
		}
		// cout << choose[i] << ' ';
	}

	printf("%d", p[--pcnt]);
	for (int i = 0; i < lterm; i++) {//����߷���  ����ԭ��
		if (pom[0][i] == 0) {
			printf(" + %d", p[--pcnt]);
		} else {
			printf(" - %d", m[--mcnt]);
		}
	}

	printf(" = %d", m[--mcnt]);
	for (int i = 0; i < rterm; i++) {//���ұߵ�  ��ԭ���Ǽ�  ������Ϊ��  ȡһ����Ϊ��������
		if (pom[1][i] == 1) {//ԭ��Ϊ��  ȡһ����Ϊ�ӷ�����
			printf(" - %d", p[--pcnt]);
		} else {
			printf(" + %d", m[--mcnt]);
		}
	}
	puts("");
}

int main() {
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while (gets(eqt)) {
		init();
		if (solve()) {
			print();
		} else {
			puts("no solution");
		}
	}
	return 0;
}

