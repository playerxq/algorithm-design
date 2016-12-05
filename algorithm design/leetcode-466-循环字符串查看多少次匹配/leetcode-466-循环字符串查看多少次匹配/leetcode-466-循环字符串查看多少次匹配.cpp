// leetcode-466-循环字符串查看多少次匹配.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		int* rapport = new int[s2.length()+1];
		int* rest = new int[s2.length()+1];
		for(int i = 0;i<s2.length();i++)
			rapport[i] = rest[i] = -1;
		int j = 0;
		int m = 0;
		int last,b;
		b = last = -1;
		rapport[0] = rest[0] = 0;
		for(int k = 1;k<=s2.length()+1;k++)
		{
			for(int i= 0;i<s1.length();i++)
			{
				if(s2[j]==s1[i])
				{
					j++;
					if(j==s2.length())
    				{
    					m++;
    					j = 0;
    				}
				}
			}
			for(int l = 0;l<k;l++)
			{
				if(rest[l]==j)
				{
					b = l;
					last = k;
					break;
				}
			}
			rapport[k] = m;
			rest[k] = j;
			if(b>=0)
				break;
		}
		if(b>=n1) return rapport[n1]/n2;
		else
		{
			return ((n1-b)/(last-b)*(rapport[last]-rapport[b])+rapport[b+(n1-b)%(last-b)])/n2;
		}
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.getMaxRepetitions("lovelive",0,"lovelive",10);
}

