// leetcode-49-字符串排序.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> result;
    int s_hash[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    int v_len = strs.size();
    unordered_map<int,int> val_result;
    for(int i=0; i<v_len; i++){
        int i_val=1;
        int i_len=strs[i].size();
        for(int j=0;j<i_len;++j){
            i_val *= s_hash[strs[i][j]-'a'];
        }
        int index = val_result[i_val];
        if(index == 0){
            result.push_back(vector<string>(1, strs[i]));
            val_result[i_val]=result.size();
        }else{
            result[index-1].push_back(strs[i]);
        }
    }
    return result;
}
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<string> v;
	v.push_back("ate");
	v.push_back("aet");
	v.push_back("eta");
	v.push_back("bat");
	v.push_back("nat");
	v.push_back("tan");
	Solution s;
	s.groupAnagrams(v);
}

