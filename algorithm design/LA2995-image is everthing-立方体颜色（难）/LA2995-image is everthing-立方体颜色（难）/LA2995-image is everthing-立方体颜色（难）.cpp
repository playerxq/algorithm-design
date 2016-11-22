// LA2995-image is everthing-��������ɫ���ѣ�.cpp : �������̨Ӧ�ó������ڵ㡣
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
#define REP(i,n) for(int i = 0;i<(n);i++)
const int maxn = 10;
int n;
char pos[maxn][maxn][maxn];
char view[maxn][maxn][maxn];
char read_char()
{
	char ch;
	for(;;)
	{
		ch = getchar();
		if((ch>='A'&&ch<='Z')||ch=='.')
			return ch;
	}
}
void get(int k, int i, int j,int len, int &x,int &y,int &z)//�õ���k��ͼ�ĽǶȿ���(i,j)��ͨlen����ķ�������(x,y,z)
{
	if(k==0){x=len;y=j;z=i;}//ǰ��ͼ x�ı�  y,z��j,iһ��
	if(k==1){x=n-1-j;y=len;z=i;}//����ͼ yΪ��ͨ�ľ��� z��ȻΪi xΪi��n-1��Ծ��� ������ԭ����i��ʼ���෴��
	if(k==2){x=n-1-len;y=n-1-j;z=i;}//����ͼ ��ǰ��ͼ�෴
	if(k==3){x=j;y=n-1-len;z=i;}//����ͼ z���� x,y������ͼ�෴
	if(k==4){x=n-1-i;y=j;z=len;}//����ͼ zΪ��ͨ���� 
	if(k==5){x=i;y=j;z=n-1-len;}//��ͨ�����붥��ͼ�෴
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&n)==1&&n)
	{
		REP(i,n) REP(k,6) REP(j,n) view[k][i][j]=read_char();//kΪǰ����Ҷ���6����ͼ view[k][i][j]Ϊk����ͼ��i,j������ɫ
		REP(i,n) REP(j,n) REP(k,n) pos[i][j][k]='#';//�ȼ���ÿ��λ�ö��з���
		REP(k,6) REP(i,n) REP(j,n) if(view[k][i][j]=='.')//k��ͼ��(i,j)Ϊ��
			REP(p,n){//k��ͼ���� (i,j)Ӧ��ͨ
				int x,y,z;
				get(k,i,j,p,x,y,z);//k��ͼ�����(i,j)��ͨ���������п���ȥ
				pos[x][y][z]='.';
		}
		for(;;)
		{
			bool done = true;
			REP(k,6) REP(i,n) REP(j,n) if(view[k][i][j]!='.')//��Ϊ��
			{
				REP(p,n)
				{
					int x,y,z;
					get(k,i,j,p,x,y,z);
					if(pos[x][y][z]=='.') continue;//�Ѿ�����ȥ  ����
					if(pos[x][y][z]=='#')//���з���  ��δ��ɫ
					{
						pos[x][y][z]=view[k][i][j];//��һ��Ϳɫ����ɫӦΪ��k��ͼ��ȥ����Ӧλ��
						break;
					}
					if(pos[x][y][z]==view[k][i][j]) break;//��ɫ��֮ǰͿɫ��ͬ  ����
					pos[x][y][z]='.';//��(x,y,z)��֮ǰѭ���Ѿ�Ϳɫ����ɫ��ͬ  ��ȥ
					done=false;
				}
			}
			if(done) break;
		}
		int ans = 0;
		REP(i,n) REP(j,n) REP(k,n)
			if(pos[i][j][k]!='.') ans++;
		printf("Maximum weight: %d gram(s)\n",ans);
	}
}

