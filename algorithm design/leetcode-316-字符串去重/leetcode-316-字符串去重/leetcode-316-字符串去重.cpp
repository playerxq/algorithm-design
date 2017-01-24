// leetcode-316-�ַ���ȥ��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	string removeDuplicateLetters(string s) {
		int len = s.length();
		int* cnt = new int[27];

		int* vis = new int[27];
		for (int i = 0; i < 26; i++)
			cnt[i] = vis[i] = 0;
		for (int i = 0; i < len; i++)
			cnt[s[i] - 'a']++;
		string res = "";
		for (int i = 0; i < len; i++)
		{
			if (vis[s[i] - 'a'])
			{
				cnt[s[i] - 'a']--;
				continue;
			}
			while (!res.empty()&&s[i] <= res.back() && cnt[res.back() - 'a'])
			{
				vis[res.back() - 'a'] = 0;
				res.pop_back();
			}
			if (vis[s[i] - 'a'] == 0)
			{
				res += s[i];
				cnt[s[i] - 'a']--;
				vis[s[i] - 'a'] = 1;
			}
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.removeDuplicateLetters("bbcaac");
	return 0;
}

