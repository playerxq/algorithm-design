// leetcode-151-字符串翻转.cpp : 定义控制台应用程序的入口点。
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
    void reverseWords(string &s) {
		int len = s.length();
		int i = len-1;
		int flag = 0;
		int pre = 0;
		while(i>=0&&s[i]==' ')
			i--;
		if(i<0)
		{
			s = "";
			return;
		}
		int en = i;
		s.erase(en+1,len-en-1);
		while(i>=0&&s[i]!=' ')
			i--;
		if(i<0)
		{
			s = s.substr(0,en+1);
			return;
		}
		int star = i+1;
		int st,ed;
		while(i>=0)
		{
			while(i>=0&&s[i]==' ')
				i--;
			if(i<0)
				break;
			ed = i;
			while(i>=0&&s[i]!=' ')
			{
				i--;
			}
			st = i+1;
			s.append(" ");
			s.append(s.substr(st,ed-st+1));
		}
		s = s.substr(star);
		return;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	string ss = " 1 ";
	s.reverseWords(ss);
}
