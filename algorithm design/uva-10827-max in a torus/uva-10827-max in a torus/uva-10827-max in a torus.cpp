// uva-10827-max in a torus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//��ƴ�ӳ��ĸ�����Ȼ��ö���������������κ͵ĳ����� 
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
			a[i][j+n]=a[i+n][j]=a[i+n][j+n]=a[i][j]; //һ����չ���ĸ� 
		}
		ans=-100000000;
		for(x=0;x<n;x++) //���ϽǺ����� 
		for(y=0;y<n;y++)//���Ͻ������� 
		for(j=0;j<n;j++)    
		for(i=0;i<n;i++)  
		{
			lie[i]=a[x+i][y+j]; 
			if(i)  lie[i]+=lie[i-1]; //lie[i]Ϊ��j�е�ǰi��ֵ���ۼ�
			if(j)  sum[i]+=lie[i];  //sum[i]Ϊ(x,y)��ʼ��0��j�е�ǰi���ۼ�
            else   sum[i]=lie[i];
			if(ans<sum[i]) ans=sum[i];	
		} 
  		cout<<ans<<endl;
	}
	return 0;
}

