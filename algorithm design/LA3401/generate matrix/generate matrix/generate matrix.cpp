// generate matrix.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <string.h>
#include <math.h>
#include <vector>
#include <ctype.h>
#include <algorithm>
using namespace std;
int left[6]={4,0,2,3,5,1};
int up[6]={2,1,5,0,4,3};
void rot(int* T, int* p)
{
	int q[6];
	memcpy(q,p,sizeof(q));
	for(int i = 0;i<6;i++)
		p[i]=T[q[i]];
}
void enumerate_perm()
{
	int p0[6]={0,1,2,3,4,5};
	printf("int dice24[24][6]={\n");
	for(int i = 0;i<6;i++)//ö���ĸ��泯��
	{
		int p[6];
		memcpy(p,p0,sizeof(p0));
		if(i ==0) rot(up,p);
		if(i==1) {rot(left,p);rot(up,p);}
		if(i==3) {rot(up,p);rot(up,p);}
		if(i==4) {rot(left,p);rot(left,p);rot(left,p);rot(up,p);}
		if(i==5) {rot(left,p);rot(left,p);rot(up,p);}
		for(int j = 0;j<4;j++)
		{
			printf("{%d,%d,%d,%d,%d,%d},\n",p[0],p[1],p[2],p[3],p[4],p[5]);
			rot(left,p);
		}

	}
	printf("};\n");
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	enumerate_perm();
}

