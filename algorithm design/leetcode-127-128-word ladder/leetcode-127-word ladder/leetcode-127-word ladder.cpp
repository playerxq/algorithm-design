// leetcode-word ladder 2.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
#include <unordered_set>
using namespace std;
//长度
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int previous = 1;
		int now = 0;
		int ans = 0;
		vector<string> ve[2];
		ve[now].push_back(beginWord);
		while(1)
		{
			ans++;
			now = now^1;
			previous = 1-now;
			for (vector<string>::iterator iter = ve[previous].begin(); iter != ve[previous].end(); ++iter)  
                wordList.erase(*iter);
			ve[now].clear(); 
			for(vector<string>::iterator iter = ve[previous].begin();iter != ve[previous].end(); ++iter)
			{
				for(int i = 0;i<(*iter).size();i++)
				{
					for(char c = 'a';c<='z';c++)
					{
						if((*iter)[i]==c)
							continue;
						else
						{
							string temp_w = (*iter);
							temp_w[i]=c;
							if(temp_w==endWord)
								return ans+1;
							if(wordList.find(temp_w)!=wordList.end())
							{
								ve[now].push_back(temp_w);
							}
						}
					}
				}
			}
			for(vector<string>::iterator iter = ve[now].begin();iter != ve[now].end(); ++iter)
			{
				if((*iter)==endWord)
				{
					return ans+1;
				}
			}
			if(ve[now].size()==0)
			{
				return 0;
			}
		}
    }
};
//路径
class Solution1 {
public:
	vector<string> ve[2];
	vector<vector<string>> ans;  
	void dfs(map<string,set<string>>& pre,vector<string>& path, string end)
	{
		if(pre[end].size()==0)
		{
			path.push_back(end);
			vector<string> ans_now = path;
			std::reverse(ans_now.begin(),ans_now.end());
			ans.push_back(ans_now);
			path.pop_back();
			return;
		}
		path.push_back(end);
		for(set<string>::iterator iter = pre[end].begin();iter != pre[end].end(); ++iter)
			dfs(pre,path,(*iter));
		path.pop_back();
	}
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string,set<string>> pre;
		for(unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)  
            pre[*iter] = set<string>();
		int previous = 1; 
		int now = 0;
		ve[now].push_back(start);
		bool flag = true;
		while(flag)
		{
			now = now^1;
			previous = 1-now;
			for (vector<string>::iterator iter = ve[previous].begin(); iter != ve[previous].end(); ++iter)  
                dict.erase(*iter);  
            ve[now].clear(); 
			for(vector<string>::iterator iter = ve[previous].begin();iter != ve[previous].end(); ++iter)
			{
				for(int i = 0;i<(*iter).size();i++)
				{
					for(char c = 'a';c<='z';c++)
					{
						if((*iter)[i]==c)
							continue;
						else
						{
							string temp_w = (*iter);
							temp_w[i]=c;
							if(dict.find(temp_w)!=dict.end()||temp_w==end)
							{
								pre[temp_w].insert(*iter);
								ve[now].push_back(temp_w);
							}
						}
					}
				}
			}
			if(ve[now].size()==0)
			{
				return ans;
			}
			for(vector<string>::iterator iter = ve[now].begin();iter != ve[now].end(); ++iter)
				if((*iter)==end)
				{
					flag = false;
					break;
				}
		}
		vector<string> path;
		dfs(pre,path,end);
		//ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
		return ans;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution1 s;
	unordered_set<string> ss;
	ss.insert("red");
	ss.insert("ted");
	ss.insert("tad");
	ss.insert("tex");
	ss.insert("tax");
	ss.insert("rex");
	s.findLadders("red","tax",ss);
}

