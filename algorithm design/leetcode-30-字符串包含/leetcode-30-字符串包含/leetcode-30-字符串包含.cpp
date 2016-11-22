// leetcode-30-字符串包含.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		int k = words[0].length();
		vector<int> ve;
		ve.clear();
		map<string, int> mm;
		int n = words.size();
		for(int i = 0;i<n;i++)
		{
			mm[words[i]]++;
		}
		int len = s.length();
		for(int i = 0;i<k;i++)
		{
			map<string, int> tm;
			int left = i,count=0;
			for(int j = i;j<=len-k;j+=k)
			{
				string str = s.substr(j,k);
				if(mm.count(str))
				{
					tm[str]++;
					if(tm[str]<=mm[str])
						count++;
					else
					{
						while(tm[str]>mm[str])
						{
							string str1 = s.substr(left,k);
							tm[str1]--;
							if(tm[str1]<mm[str1]) count--;
							left+=k;
						}
					}
					if(count==n)
					{
						ve.push_back(left);
						tm[s.substr(left,k)]--;
						count--;
						left+=k;
					}
				}
				else
				{
					tm.clear();
					count = 0;
					left = j+k;
				}
			}
		}
		return ve;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<string> v;
	v.push_back("mississippis");
	//v.push_back("good");
	//v.push_back("best");
	//v.push_back("good");
	string str = "mississippi";
//["mississippis"];
	s.findSubstring(str,v);

}

