// uva-322-ships.cpp : �������̨Ӧ�ó������ڵ㡣
//http://blog.csdn.net/hackerwin7/article/details/40182021

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
#define X 28
#define LL 20
typedef struct pot//ÿ����
{
	int m;//'o'����Ŀ
	int n;//'x'����Ŀ
	bool is_various;//���m,n������0 ˵��Ϊ�ǹ̶���  Ϊ��
	int x,y;//���� (0,0)Ϊԭ��
	pot()
	{
		x=y=m=n=0;
		is_various=false;
	}
}pot,*pot_link;
typedef struct grid
{
	int r,c;
	pot val[20][20];
	grid(){r=c=0;}
}grid,*grid_link;
char grids[500][LL][LL];//����������ͼ  ��û��'.'
int cnt = 0;//grids����Ŀ
int used_grids[500]={0};//grids�������
char in_grid[LL][LL];//����
grid pot_grid;//����grid��ÿ��pot���״̬
int W,H;//���
int R,C;
int cases = 0;
int x_cnt = 0;//������x��Ŀ
int o_cnt = 0;//������o��Ŀ
int i_cnt = 0;//������.��Ŀ
//��ģ��  ������ת
char patterns[19][10][10]=  
{  
  {  
      "xx",//1 kind -> 1 pattern  
      "xx"  
  },  
  {  
      "xx",//1 kind-> 2 patterns  
      " xx"  
  },  
  {  
      " x",  
      "xx",  
      "x"  
  },  
  {  
      " xx",//1 kind -> 2 patterns  
      "xx"  
  },  
  {  
      "x ",  
      "xx",  
      " x"  
  },  
  {  
      "x",//1 kind -> 4 patterns  
      "xxx"  
  },  
  {  
      "xx",  
      "x",  
      "x"  
  },  
  {  
      "xxx",  
      "  x"  
  },  
  {  
      " x",  
      " x",  
      "xx"  
  },  
  {  
      " x ",//1 kind -> 4 patterns  
      "xxx"  
  },  
  {  
      "x",  
      "xx",  
      "x"  
  },  
  {  
      "xxx",  
      " x"  
  },  
  {  
      " x",  
      "xx",  
      " x"  
  },  
  {  
      "  x",//1 kind -> 4 patterns  
      "xxx"  
  },  
  {  
      "x",  
      "x",  
      "xx"  
  },  
  {  
      "xxx",  
      "x"  
  },  
  {  
      "xx",  
      " x",  
      " x"  
  },  
  {  
      "xxxx"//1 kind -> 2 patterns  
  },  
  {  
      "x",  
      "x",  
      "x",  
      "x"  
  }  
};
int kind_cnt[7]={1,2,2,4,4,4,2};//��¼ÿ��kind��Ӧ����תpatterns��Ŀ
int kind_ind[7]={0,1,3,5,9,13,17};//ÿ��kind��Ӧ����ʼ����
//��in_grid���뵽grids��
int insert_grid()
{
	for(int i = 0;i<R;i++)
	{
		for(int j = 0;j<C;j++)
		{
			if(in_grid[i][j]=='.') {grids[cnt][i][j]='o';}//δ������Ϊo
			else if(in_grid[i][j]>=0&&in_grid[i][j]<=6){grids[cnt][i][j]='x';}
			else
				grids[cnt][i][j]=in_grid[i][j];
		}
	}
	cnt++;
	if(cnt>=1000)
		cnt--;
	return 0;
}
//������һ��pattern����������grid���뵽grids��
int DFS_kind(int cur)
{
	if(x_cnt>28) return 0;//��ǰx�����������ֵ
	if(cnt>R*C) return -1;
	if(cur>=7)//���pattern�ڷ�  ͳ��x����
	{
		int x_c = 0;
		for(int i = 0;i<R;i++)
		{
			for(int j = 0;j<C;j++)
			{
				if(in_grid[i][j]=='x'||(in_grid[i][j]>=0&&in_grid[i][j]<=6)){x_c++;}
			}
		}
		if(x_c==28)//ǡ����7��kind��pattern  ÿ��4��x
		{
			insert_grid();//����ʱ��'.''o'����Ϊ'o'
		}
	}
	else//ѡ��һ��pattern
	{
		for(int k = 0;k<=kind_cnt[cur]-1;k++)//ö�ٵ�ǰkind��Ӧ��ÿ��pattern
		{
			int pat_ind = kind_ind[cur]+k;//��ǰpattern������
			//����ǰpattern�����Ͻ������(0,0)ƽ�Ƶ�(R-1,C-1)��ƫ��
			for(int nexti = 0;nexti<R;nexti++)
			{
				for(int nextj = 0;nextj<C;nextj++)
				{
					int i=0,j = 0;
					int match_cnt = 0;//��ǰpattern��xƥ����Ŀ =4ʱ��ǰpattern���ƥ��
					int pre_x[5]={0};
					int pre_y[5] = {0};
					int pre_char[5]={0};
					while(i<=4-1&&j<=4-1)//ÿ��pattern�������4  0��3
					{
						char ch = patterns[pat_ind][i][j];//��Ӧpattern��λ
						if(ch!='\0')
						{
							if(ch=='x')
							{
								if(nexti+i>R-1||nextj+j>C-1) break;
								if(in_grid[nexti+i][nextj+j]=='x'||in_grid[nexti+i][nextj+j]=='.')
								{
									if(in_grid[nexti+i][nextj+j]=='.')//��.��Ϊx x_cnt��һ
										x_cnt++;
									pre_x[match_cnt]=nexti+i;//����ԭ����λ��
									pre_y[match_cnt]=nextj+j;
									pre_char[match_cnt]=in_grid[nexti+i][nextj+j];//����ԭ����ֵ
									match_cnt++;
									in_grid[nexti+i][nextj+j]=cur;//��ǰλ���ڵ�cur��ö�ٵ�cur��kind��patternʱ��ʹ��
								}
								else
									break;//��ƥ��
							}
						}
						j++;//����ƽ��
						if(j>4-1)
						{
							j= 0;
							i++;
						}
					}
					if(match_cnt==4)//��ǰPattern��ƥ�����  ����һ��kind��pattern
					{
						int flag = DFS_kind(cur+1);
						if(flag==-1) return -1;
					}
					for(int ci = 0;ci<match_cnt;ci++)
					{
						in_grid[pre_x[ci]][pre_y[ci]]=pre_char[ci];
						if(pre_char[ci]=='.')
							x_cnt--;//�ָ�����
					}
				}
			}
		}
	}
	return 0;
}
//����pot_grid
int constr_pot()
{
	for(int c = 0;c<cnt;c++)
	{
		for(int i = 0;i<R;i++)
		{
			for(int j = 0;j<C;j++)
			{
				if(grids[c][i][j]=='x')
					pot_grid.val[i][j].n++;//���п��ܵ�����grid�� ÿ�����Ӧ��x�ĸ���
				else
					pot_grid.val[i][j].m++;
			}
		}
	}
	for(int i = 0;i<R;i++)
	{
		for(int j = 0;j<C;j++)
		{
			if(pot_grid.val[i][j].m>0&&pot_grid.val[i][j].n>0)
				pot_grid.val[i][j].is_various=true;//�ǿɱ��
		}
	}
	return 0;
}
//������������grid,����ǰgrid��min_m.x min_m.yλ��Ϊch ����ȥ��grid
int sub_grids(pot min_m,char ch, int cur)
{
	for(int c = 0;c<cnt;c++)
	{
		if(!used_grids[c]&&grids[c][min_m.x][min_m.y]==ch)
		{
			used_grids[c]=cur;//��ǵ�ǰgrid�ڵڼ����б�����
			for(int i = 0;i<R;i++)//��ǰgrid����ȥ����pot_grid.val�ж�Ӧ��ļ���״̬�ı�
			{
				for(int j = 0;j<C;j++)
				{
					if(grids[c][i][j]=='x')
						pot_grid.val[i][j].n--;
					else
						pot_grid.val[i][j].m--;
					if(!(pot_grid.val[i][j].m>0&&pot_grid.val[i][j].n>0))
						pot_grid.val[i][j].is_various=false;
				}
			}
		}
	}
	return 0;
}
int add_grids(int cur)
{
	for(int c = 0;c<cnt;c++)
	{
		if(used_grids[c]==cur)//�ҵ���cur�ֱ������grid  �ָ���grid
		{
			used_grids[c]=0;
			for(int i = 0;i<R;i++)
			{
				for(int j = 0;j<C;j++)
				{
					if(grids[c][i][j]=='x')
						pot_grid.val[i][j].n++;
					else
						pot_grid.val[i][j].m++;
					if((pot_grid.val[i][j].m>0&&pot_grid.val[i][j].n>0))
						pot_grid.val[i][j].is_various=true;
				}
			}
		}
	}
	return 0;
}
//dfs pot_grid����ȥ�ɱ�� 
int DFS_pot(int cur, int use_o)
{
	if(use_o>=2) return 0;//������2�����ϵĴ�������  ��Ϊfalse
	pot min_m;
	int flag = 0;
	int mark = 0;
	min_m.m=1000;
	for(int i = 0;i<R;i++)//�ҵ����п��ܽ��� ����'o'�������ٵĿɱ��
	{
		for(int j = 0;j<C;j++)
		{
			if(pot_grid.val[i][j].is_various)
			{
				flag = 1;
				if(pot_grid.val[i][j].m<min_m.m)//�ҵ��ɱ����o�Ĵ�����С��
				{
					min_m.m=pot_grid.val[i][j].m;
					min_m.n=pot_grid.val[i][j].n;
					min_m.x=i;
					min_m.y=j;
				}
			}
		}
	}
	if(!flag)//û�пɱ��  ˵��ͼ��ȷ��
	{
		return 1;//ֱ�ӵõ�yes
	}
	//�ֱ����ɱ����x ���� o
	//����ɱ����o ����������grid��min_m�˵�Ϊx��grid����ȥ
	sub_grids(min_m,'x',cur);
	mark=DFS_pot(cur+1,use_o+1);//����������+1
	if(!mark) return 0;
	add_grids(cur);
	//����ɱ����x ����������grid��min_m�˵�Ϊo��grid����ȥ
	sub_grids(min_m,'o',cur);
	mark=DFS_pot(cur+1,use_o);
	if(!mark) return 0;
	add_grids(cur);
	return 1;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&W,&H)!=EOF&&(W+H)>0)
	{
		R = H;
		C = W;
		cnt = 0;
		x_cnt=o_cnt=i_cnt=0;
		pot_grid.c=C;
		pot_grid.r=R;
		memset(grids,'\0',sizeof(grids));
		memset(used_grids,0,sizeof(used_grids));
		for(int i = 0;i<R;i++)
		{
			for(int j = 0;j<C;j++)
			{
				pot_grid.val[i][j].is_various=false;
				pot_grid.val[i][j].m=pot_grid.val[i][j].n=pot_grid.val[i][j].x=pot_grid.val[i][j].y=0;
			}
		}
		printf("Game #%d\n",++cases);
		for(int i = 0;i<R;i++)
		{
			scanf("%s",in_grid[i]);
			for(int j = 0;j<C;j++)
			{
				switch(in_grid[i][j])
				{
				case 'x':
					x_cnt++;
					break;
				case 'o':
					o_cnt++;
					break;
				case '.':
					i_cnt++;
					break;
				}
			}
		}
		if(x_cnt>28)
		{
			printf("no.\n\n");
			continue;
		}
		DFS_kind(0);
		constr_pot();
		if(cnt>0&&cnt<=R*C&&DFS_pot(1,0))
			printf("yes.\n\n");
		else
			printf("no.\n\n");
	}
}
