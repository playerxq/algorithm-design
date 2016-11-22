// leetcode-20-匹配.cpp : 定义控制台应用程序的入口点。
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
int ok(char a, char b)
{
    if((a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}'))
    return 1;
    return 0;
}
    bool isValid(string s) {
        if(s.size()==0||s.size()==1)
        return 0;
        vector<char> ve;
        ve.clear();
        ve.push_back(s[0]);
        for(int i = 1;i<s.size();i++)
        {
			if(ve.empty())
				ve.push_back(s[i]);
			else if(ok(ve[ve.size()-1],s[i]))
				ve.pop_back();
            else
			{
				ve.push_back(s[i]);
			}
        }
		if(ve.empty())
        return 1;
		return 0;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.isValid("([])");
	return 0;
}

