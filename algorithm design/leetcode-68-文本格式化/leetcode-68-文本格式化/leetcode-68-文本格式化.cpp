// leetcode-68-文本格式化.cpp : 定义控制台应用程序的入口点。
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
    vector<string> fullJustify(vector<string>& words, int L) {
        vector<string> res;
		for(int i = 0,k,l;i<words.size();i+=k)
		{
			for(k = l = 0;i+k<words.size()&&l+words[i+k].length()+k<=L;k++)
			{
				l+=words[i+k].size();
			}
			string tmp = words[i];
			for(int j = 0;j<k-1;j++)
			{
				if(i+k>=words.size()) tmp+=" ";
				else tmp+=string((L-l)/(k-1)+((j<((L-l)%(k-1)))?1:0),' ');
				tmp+=words[i+j+1];
			}
			tmp+=string(L-tmp.length(),' ');
			res.push_back(tmp);
		}
		return res;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

