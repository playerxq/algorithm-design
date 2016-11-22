// LA3971-assemble computer-2分答案判断.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <algorithm>
using namespace std;
int cnt;
map<string,int> id;
int ID(string s)
{
	if(!id.count(s)) id[s]=cnt++;//新增一个种类
	return id[s];
}
const int maxn = 1005;
struct Component{
	int price;
	int quality;
};
int n,b;
vector<Component> comp[maxn];
bool ok(int q)
{
	int sum = 0;
	for(int i = 0;i<cnt;i++)
	{
		int cheapest = b+1;
		int m = comp[i].size();
		for(int j = 0;j<m;j++)//考虑第i类商品的每一件
		{
			if(comp[i][j].quality>=q) cheapest = min(cheapest, comp[i][j].price);
		}
		if(cheapest==b+1) return false;//最便宜的也比要求的贵
		sum+=cheapest;
		if(sum>b) return false;
	}
	return true;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&b);
		cnt=0;
		for(int i = 0;i<n;i++)
			comp[i].clear();
		id.clear();
		int maxq = 0;
		for(int i = 0;i<n;i++)
		{
			char type[30], name[30];
			int p,q;
			scanf("%s%s%d%d",type,name,&p,&q);
			maxq = max(maxq,q);
			Component ccc;
			ccc.price=p;
			ccc.quality=q;
			comp[ID(type)].push_back(ccc);
		}
		int L = 0,R=maxq;
		while(L<R)
		{
			int M = L+(R-L+1)/2;
			if(ok(M)) L = M;
			else R = M-1;
		}
		printf("%d\n",L);
	}
}

