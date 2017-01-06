// leetcode-224-算术表达式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <sstream>
#include <algorithm>
using namespace std;
string int2str(const int &int_temp)  
{  
	string string_temp;
    stringstream stream;  
    stream<<int_temp;  
    string_temp=stream.str();   //此处也可以用 stream>>string_temp  
	return string_temp;
}
int str2int(const string &string_temp)  
{  
	int int_temp = 0;
    stringstream stream(string_temp);  
    stream>>int_temp;  
	return int_temp;
}
class Solution {
public:
    int calculate(string s) {
		if(s.length()==0)
			return 0;
		int be = 0;
		be = s.find(" ",be);
		while(be != -1)  //表示字符串中存在空格
		{
			s.replace(be, 1, "");
			be = s.find(" ",be);
		}
		int len = s.length();
		vector<string> num;
		int c1 =0;
		int c2 = 0;
		int c3 = 0;
		int i = 0;
		for(;i<len;i++)
		{
			if(s[i]=='+')
				num.push_back("+");
			else if(s[i]=='-')
				num.push_back("-");
			else if(s[i]>='0'&&s[i]<='9')
			{
				string n = "";
				while(s[i]>='0'&&s[i]<='9')
				{
					n += (s[i]);
					i++;
				}
				num.push_back(n);
				i--;
			}
			else if(s[i]=='(')
			{
				num.push_back("(");
				c1++;
			}
			else if(s[i]==')')
			{
				c2++;
				int sum = 0;
				int sig = 0;
				int tmp = 0;
				while(!num.empty()&&num.back()!="(")
				{
					tmp = str2int(num.back());
					num.pop_back();
					if(num.empty()||num.back()=="(")
					{
						sum+=tmp;
						break;
					}
					if(num.back()=="-")
					{
						tmp = (-1)*tmp;
						num.pop_back();
					}
					if(num.back()=="+")
						num.pop_back();
					sum+=tmp;
				}
				if(!num.empty()&&num.back()=="(")
				{
					num.pop_back();
					c3++;
				}
				num.push_back(int2str(sum));
			}
		}
		int sum = 0;
		int sig = 0;
		int tmp = 0;
		while(!num.empty())
		{
			tmp = str2int(num.back());
			num.pop_back();
			if(num.empty())
			{
				sum+=tmp;
				break;
			}
			if(num.back()=="-")
			{
				tmp = (-1)*tmp;
				num.pop_back();
			}
			if(num.back()=="+")
				num.pop_back();
			sum+=tmp;
		}
		num.push_back(int2str(sum));
		return str2int(num.back());
    }
};
//
class Solution1 {
public:
    int calculate(string s) {
        if(s.length()==0)
			return 0;
		int be = 0;
		be = s.find(" ",be);
		while(be != -1)  //表示字符串中存在空格
		{
			s.replace(be, 1, "");
			be = s.find(" ",be);
		}
		int len = s.length();
		vector<string> num;
		for(int i = 0;i<len;i++)
		{
			if(s[i]=='+')
			{
				num.push_back("+");
			}
			else if(s[i]=='-')
			{
				num.push_back("-");
			}
			else if(s[i]=='*')
			{
				num.push_back("*");
			}
			else if(s[i]=='/')
			{
				num.push_back("/");
			}
			else
			{
				string n = "";
				while(s[i]>='0'&&s[i]<='9')
				{
					n += (s[i]);
					i++;
				}
				i--;
				if(!num.empty())
				{
					if(num.back()=="*")
					{
						num.pop_back();
						int oper1 = str2int(num.back());
						int tt = oper1*str2int(n);
						num.pop_back();
						num.push_back(int2str(tt));
					}
					else if(num.back()=="/")
					{
						num.pop_back();
						int oper1 = str2int(num.back());
						int tt = oper1/str2int(n);
						num.pop_back();
						num.push_back(int2str(tt));
					}
					else
						num.push_back(n);
				}
				else
					num.push_back(n);
			}
		}
		int sig = 1;
		int sum = 0;
		if(num.back()=="+")
		{
			sig = 1;
			num.pop_back();
		}
		else if(num.back()=="-")
		{
			sig = -1;
			num.pop_back();
		}
		while(!num.empty())
		{
			string o = num.back();
			num.pop_back();
			if(!num.empty())
			{
				if(num.back()=="+")
				{
					sig = 1;
					num.pop_back();
				}
				else if(num.back()=="-")
				{
					sig = -1;
					num.pop_back();
				}
			}
			sum+=(sig*str2int(o));
			sig = 1;
		}
		return sum;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution1 s;
	s.calculate("3+2*2");	
}

