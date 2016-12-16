// leetcode-165-字符串简单比较.cpp : 定义控制台应用程序的入口点。
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
    int compareVersion(string version1, string version2) {
        int pos1,pos2;
		pos1 = pos2 = 0;
		int num1,num2 ;
		num1 = num2 = 0;
		while(pos1<version1.length()&&pos2<version2.length())
		{
			num1 = num2 = 0;
			int s1,s2;
			s1 = pos1;
			s2 = pos2;
			pos1 = version1.find('.',pos1);
			pos2 = version2.find('.',pos2);
			if(pos1==string::npos)
				pos1 = version1.length();
			if(pos2==string::npos)
				pos2 = version2.length();
			for(int i = s1;i<pos1;i++)
				num1 = num1*10+version1[i]-'0';
			for(int i = s2;i<pos2;i++)
				num2 = num2*10+version2[i]-'0';
			if(num1<num2)
				return -1;
			else if(num1>num2)
				return 1;
			else
			{
				pos1++;
				pos2++;
			}
		}
		while(pos1<version1.length())
		{
			num1 = 0;
			int s1;
			s1 = pos1;
			pos1 = version1.find('.',pos1);
			if(pos1==string::npos)
				pos1 = version1.length();
			for(int i = s1;i<pos1;i++)
				num1 = num1*10+version1[i]-'0';
			if(num1!=0)
				return 1;
			else
				pos1++;
		}
		while(pos2<version2.length())
		{
			num2 = 0;
			int s2;
			s2 = pos2;
			pos2 = version2.find('.',pos2);
			if(pos2==string::npos)
				pos2 = version2.length();
			for(int i = s2;i<pos2;i++)
				num2 = num2*10+version2[i]-'0';
			if(num2!=0)
				return -1;
			else
				pos2++;
		}
		return 0;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	string v1,v2;
	v1 = "1.0";
	v2 = "1";
	s.compareVersion(v1,v2);
}

