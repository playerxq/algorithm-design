// uva-687-lattice.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int N = 20;
const int M = 50;
int ans,g[N];
set<string> rec;
int d[M],c[M];
char sta[M][N];
void handle()
{
	for(int i = 0;i<32;i++)//i��Ϊ5λ
	{//��i�ֽ�Ϊ������  ����sta[i]��
		int k = i;
		int t = 0;
		for(int j = 0;j<5;j++)
		{
			int m = k%2;
			k/=2;
			t = 2*t+m;
			sta[i][4-j]='0'+m;//sta[i]���i�Ķ����Ƶ�5λ  sta[i][4]Ϊ��λ sta[i][0]Ϊ��λ
		}
		d[i]=t;//d[i]Ϊi�Ķ����Ʒ�ת�õ�����
	}
}
void rechange(int id, char* str)
{
	int t = 0,k = 0;
	for(int i = 0;i<5;i++)
	{
		t = 2*t+str[i]-'0';//str[0]str[1]..str[4]��ɵ���
		k = 2*k+str[4-i]-'0';//str[4]str[3]..str[0]��ɵ���
	}
	c[t]++;
	c[k]++;
}
bool init()
{
	rec.clear();
	ans = 0;
	memset(c,0,sizeof(c));
	char str[N];
	for(int i = 0;i<10;i++)
	{
		scanf("%s",str);
		if(strcmp(str,"END")==0) return false;
		rechange(i,str);//�ֱ����str��������Ķ�����ֵ�ĸ���
	}
	return true;
}
void add(char (*x)[N],char (*y)[N])
{
	string str;
	for(int i = 0;i<5;i++)
		str = str+x[i];
	for(int i = 0;i<5;i++)
		str = str+y[i];
	rec.insert(str);//x,yƴ�ӷ���set
}
void ret(char (*x)[N])//����һ�з������һ��  �ڶ��зŵ����ڶ��С�����������˳ʱ��ת
{
	char y[N][N];
	for(int i = 0;i<5;i++)
		strcpy(y[i],x[i]);
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<5;j++)
		{
			x[j][4-i]=y[i][j];
		}
	}
}
void del()
{
	ans++;//�õ�һ���
	char x[N][N],y[N][N];
	for(int i = 0;i<5;i++)//g[i] g[i+5]Ϊ��Ӧ�ĺ��������������
	{
		strcpy(x[i],sta[g[i]]);//������������x,y
		strcpy(y[i],sta[g[i+5]]);
	}
	for(int i = 0;i<4;i++)//����ǰx,y�����5���� �ֱ�˳ʱ��ת4�� ��¼��ͬ����תֵ
	{
		add(x,y);
		ret(x);
		ret(y);
	}
	for(int i = 0;i<5;i++)
	{
		strcpy(x[i],sta[g[4-i]]);//����5�������»�λ
		strcpy(y[i],sta[d[g[i+5]]]);//�������g[i]���»�λ��Ӧ�������g[i+5]�ߵ�λ��ת  ��d[g[i+5]]
	}
	for(int i = 0;i<4;i++)//ͬ��˳ʱ��ת
	{
		add(x,y);
		ret(x);
		ret(y);
	}
}
bool judge()//�Ժ���ŵ�5��5λ��������  �����Ӧ������ŵ��� ��ӦλΪȡ��
{
	int r[M];
	memset(r,0,sizeof(r));
	for(int i = 0;i<5;i++)//����ĵ�i��  ��Ӧ�����i����  ����ÿ���������ĵ�iλ
	{
		int k = 0;
		for(int j = 0;j<5;j++)//�����j����
		{
			k = k*2+((g[j]&(1<<i))?0:1);//ÿ���������ĵ�iλ  ȡ��Ϊ�����i������jλ��ֵ
		}
		if(r[k]>=c[k]) return false;//����ȡ
		g[i+5]=k;//��5���������������
		r[k]++;//��¼ʹ�ô���
		r[d[k]]++;
	}
	string str;
	for(int i = 0;i<10;i++)
	{
		str = str+sta[g[i]];
	}
	if(rec.find(str)!=rec.end()) return false;
	return true;
}
void dfs(int deep)
{
	if(deep>=5)//�õ����ɺ���ŵ���
	{
		if(judge()) del();
		return;
	}
	for(int i =0;i<32;i++)//5λ��  ����31
	{
		if(c[i]==0) continue;//�����ֹ�
		c[i]--;
		c[d[i]]--;
		g[deep]=i;//g[]���ݴ��i
		dfs(deep+1);
		c[i]++;
		c[d[i]]++;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	handle();
	while(init())
	{
		dfs(0);
		printf("%d\n",ans/2);
	}
}

