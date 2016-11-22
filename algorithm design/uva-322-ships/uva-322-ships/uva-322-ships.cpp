// uva-322-ships.cpp : 定义控制台应用程序的入口点。
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
typedef struct pot//每个点
{
	int m;//'o'的数目
	int n;//'x'的数目
	bool is_various;//如果m,n均大于0 说明为非固定点  为真
	int x,y;//坐标 (0,0)为原点
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
char grids[500][LL][LL];//保存完整的图  即没有'.'
int cnt = 0;//grids的数目
int used_grids[500]={0};//grids遍历情况
char in_grid[LL][LL];//输入
grid pot_grid;//保存grid中每个pot点的状态
int W,H;//横宽
int R,C;
int cases = 0;
int x_cnt = 0;//输入中x数目
int o_cnt = 0;//输入中o数目
int i_cnt = 0;//输入中.数目
//船模型  包括旋转
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
int kind_cnt[7]={1,2,2,4,4,4,2};//记录每种kind对应的旋转patterns数目
int kind_ind[7]={0,1,3,5,9,13,17};//每种kind对应的起始索引
//将in_grid插入到grids中
int insert_grid()
{
	for(int i = 0;i<R;i++)
	{
		for(int j = 0;j<C;j++)
		{
			if(in_grid[i][j]=='.') {grids[cnt][i][j]='o';}//未定的作为o
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
//放置下一个pattern并将完整的grid插入到grids中
int DFS_kind(int cur)
{
	if(x_cnt>28) return 0;//当前x个数超过最大值
	if(cnt>R*C) return -1;
	if(cur>=7)//完成pattern摆放  统计x个数
	{
		int x_c = 0;
		for(int i = 0;i<R;i++)
		{
			for(int j = 0;j<C;j++)
			{
				if(in_grid[i][j]=='x'||(in_grid[i][j]>=0&&in_grid[i][j]<=6)){x_c++;}
			}
		}
		if(x_c==28)//恰好有7个kind的pattern  每个4个x
		{
			insert_grid();//将此时的'.''o'均作为'o'
		}
	}
	else//选择一个pattern
	{
		for(int k = 0;k<=kind_cnt[cur]-1;k++)//枚举当前kind对应的每个pattern
		{
			int pat_ind = kind_ind[cur]+k;//当前pattern的索引
			//将当前pattern的左上角坐标从(0,0)平移到(R-1,C-1)做偏移
			for(int nexti = 0;nexti<R;nexti++)
			{
				for(int nextj = 0;nextj<C;nextj++)
				{
					int i=0,j = 0;
					int match_cnt = 0;//当前pattern中x匹配数目 =4时当前pattern完成匹配
					int pre_x[5]={0};
					int pre_y[5] = {0};
					int pre_char[5]={0};
					while(i<=4-1&&j<=4-1)//每个pattern横竖最多4  0：3
					{
						char ch = patterns[pat_ind][i][j];//相应pattern的位
						if(ch!='\0')
						{
							if(ch=='x')
							{
								if(nexti+i>R-1||nextj+j>C-1) break;
								if(in_grid[nexti+i][nextj+j]=='x'||in_grid[nexti+i][nextj+j]=='.')
								{
									if(in_grid[nexti+i][nextj+j]=='.')//把.置为x x_cnt加一
										x_cnt++;
									pre_x[match_cnt]=nexti+i;//保存原来的位置
									pre_y[match_cnt]=nextj+j;
									pre_char[match_cnt]=in_grid[nexti+i][nextj+j];//保存原来的值
									match_cnt++;
									in_grid[nexti+i][nextj+j]=cur;//当前位置在第cur次枚举第cur个kind的pattern时被使用
								}
								else
									break;//不匹配
							}
						}
						j++;//向右平移
						if(j>4-1)
						{
							j= 0;
							i++;
						}
					}
					if(match_cnt==4)//当前Pattern被匹配完成  看下一个kind的pattern
					{
						int flag = DFS_kind(cur+1);
						if(flag==-1) return -1;
					}
					for(int ci = 0;ci<match_cnt;ci++)
					{
						in_grid[pre_x[ci]][pre_y[ci]]=pre_char[ci];
						if(pre_char[ci]=='.')
							x_cnt--;//恢复计数
					}
				}
			}
		}
	}
	return 0;
}
//构建pot_grid
int constr_pot()
{
	for(int c = 0;c<cnt;c++)
	{
		for(int i = 0;i<R;i++)
		{
			for(int j = 0;j<C;j++)
			{
				if(grids[c][i][j]=='x')
					pot_grid.val[i][j].n++;//所有可能的完整grid中 每个点对应的x的个数
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
				pot_grid.val[i][j].is_various=true;//是可变点
		}
	}
	return 0;
}
//对所有完整的grid,若当前grid的min_m.x min_m.y位置为ch 则消去此grid
int sub_grids(pot min_m,char ch, int cur)
{
	for(int c = 0;c<cnt;c++)
	{
		if(!used_grids[c]&&grids[c][min_m.x][min_m.y]==ch)
		{
			used_grids[c]=cur;//标记当前grid在第几轮中被处理
			for(int i = 0;i<R;i++)//当前grid被消去导致pot_grid.val中对应点的计数状态改变
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
		if(used_grids[c]==cur)//找到第cur轮被处理的grid  恢复该grid
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
//dfs pot_grid并消去可变点 
int DFS_pot(int cur, int use_o)
{
	if(use_o>=2) return 0;//出现了2次以上的错误命中  则为false
	pot min_m;
	int flag = 0;
	int mark = 0;
	min_m.m=1000;
	for(int i = 0;i<R;i++)//找到所有可能解中 出现'o'次数最少的可变点
	{
		for(int j = 0;j<C;j++)
		{
			if(pot_grid.val[i][j].is_various)
			{
				flag = 1;
				if(pot_grid.val[i][j].m<min_m.m)//找到可变点中o的次数最小的
				{
					min_m.m=pot_grid.val[i][j].m;
					min_m.n=pot_grid.val[i][j].n;
					min_m.x=i;
					min_m.y=j;
				}
			}
		}
	}
	if(!flag)//没有可变点  说明图案确定
	{
		return 1;//直接得到yes
	}
	//分别假设可变点是x 或者 o
	//假设可变点是o 则将所有完整grid中min_m此点为x的grid都消去
	sub_grids(min_m,'x',cur);
	mark=DFS_pot(cur+1,use_o+1);//错误命中数+1
	if(!mark) return 0;
	add_grids(cur);
	//假设可变点是x 则将所有完整grid中min_m此点为o的grid都消去
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
