// uva-10827-max in a torus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//先拼接成四个矩阵，然后枚举起点坐标和最大矩形和的长、宽 
#include <iostream>
using namespace std;
int a[200][200],sum[200],lie[200];
int main(int argc, char *argv[])
{
	int t,n,i,j,k,ans,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			a[i][j+n]=a[i+n][j]=a[i+n][j+n]=a[i][j]; //一个扩展成四个 
		}
		ans=-100000000;
		for(x=0;x<n;x++) //左上角横坐标 
		for(y=0;y<n;y++)//左上角纵坐标 
		for(j=0;j<n;j++)    
		for(i=0;i<n;i++)  
		{
			lie[i]=a[x+i][y+j]; 
			if(i)  lie[i]+=lie[i-1]; //lie[i]为第j列的前i行值的累加
			if(j)  sum[i]+=lie[i];  //sum[i]为(x,y)开始的0到j列的前i行累加
            else   sum[i]=lie[i];
			if(ans<sum[i]) ans=sum[i];	
		} 
  		cout<<ans<<endl;
	}
	return 0;
}

