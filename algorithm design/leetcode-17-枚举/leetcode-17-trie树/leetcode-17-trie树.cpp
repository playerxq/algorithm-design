// leetcode-17-trie树.cpp : 定义控制台应用程序的入口点。
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
int len[10]={0,0,3,3,3,3,3,4,3,4};
    char ch[10][4]={  {' ',' ',' ',' '},
                    {' ',' ',' ',' '},
                    {'a','b','c',' '},
                    {'d','e','f',' '},
                    {'g','h','i',' '},
                    {'j','k','l',' '},
                    {'m','n','o',' '},
                    {'p','q','r','s'},
                    {'t','u','v',' '},
                    {'w','x','y','z'}
                  };
class Solution {
public:
	vector<string> ve;
	
	void dfs(int cur, string digits, string str)
	{
		if(cur>=digits.length())
		{
			ve.push_back(str);
			str.clear();
			return;
		}
		int t = digits[cur]-'0';
		for(int i = 0;i<len[t];i++)
		{
			string tmp;
			tmp=str;
			dfs(cur+1,digits,str+ch[t][i]);
			str = tmp;
		}
		return;
	}
    vector<string> letterCombinations(string digits) {
		ve.clear();
		if(digits.length()==0)
			return ve;
		string str = "";
		dfs(0,digits,str);
		return ve;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	s.letterCombinations("2");
}

