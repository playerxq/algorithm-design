// leetcode-71-字符串处理.cpp : 定义控制台应用程序的入口点。
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
#include <algorithm>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
		vector<string> stk;
		stringstream ss(path);
		while(getline(ss,tmp,'/'))
		{
			if(tmp==""||tmp=='.') continue;
			if(tmp==".."&&!stk.empty()) stk.pop_back();
			else if(tmp!="..")
				stk.push_back(tmp);
		}
		for(int i = 0;i<stk.size();i++)
			res+='/'+stk[i];
		return res.empty()?"/":res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

