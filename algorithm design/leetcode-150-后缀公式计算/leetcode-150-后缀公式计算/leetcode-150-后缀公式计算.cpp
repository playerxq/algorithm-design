// leetcode-150-后缀公式计算.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
		if(tokens.size()==0)
			return 0;
		int len = tokens.size();
		int ans = 0;
		for(int i = 0;i<len;i++)
		{
			string tmp = tokens[i];
			int l = tmp.length();
			int sig = 0;
			if((tmp[0]>='0'&&tmp[0]<='9')||(tmp[0]=='-'&&l>1))
			{
				int sum = 0;
				if(tmp[0]=='-')
					sig = 1;
				for(int k = (sig?1:0);k<l;k++)
				{
					sum = sum*10+(tmp[k]-'0');
				}
				if(sig)
					st.push((-1)*sum);
				else
					st.push(sum);
			}
			else
			{
				if(tmp=="+")
				{
					int op1 = st.top();
					st.pop();
					int op2 = st.top();
					st.pop();
					int res = op1+op2;
					st.push(res);
				}
				else if(tmp=="-")
				{
					int op1 = st.top();
					st.pop();
					int op2 = st.top();
					st.pop();
					int res = op2-op1;
					st.push(res);
				}
				else if(tmp=="*")
				{
					int op1 = st.top();
					st.pop();
					int op2 = st.top();
					st.pop();
					int res = op1*op2;
					st.push(res);
				}
				else
				{
					int op1 = st.top();
					st.pop();
					int op2 = st.top();
					st.pop();
					int res = op2/op1;
					st.push(res);
				}
			}
		}
		return st.top();
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> ve;
	ve.push_back("3");
	ve.push_back("-4");
	ve.push_back("+");
	Solution s;
	s.evalRPN(ve);
	return 0;
}

