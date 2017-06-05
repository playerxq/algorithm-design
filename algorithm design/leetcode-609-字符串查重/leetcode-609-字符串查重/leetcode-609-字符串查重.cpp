// leetcode-609-字符串查重.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		vector<vector<string>> res;
		map<string, vector<string>> files;
		for (string s : paths)
		{
			std::istringstream ss(s);
			vector<string> toks{ istream_iterator<string>(ss), istream_iterator<string>{} };
			string path = toks[0];
			for (int i = 1; i < toks.size(); i++)
			{
				int pos = toks[i].find('(');
				string file = toks[i].substr(0, pos);
				string content = toks[i].substr(pos + 1, toks[i].size() - 2 - pos);
				files[content].push_back(path + "/" + file);
			}
		}
		for (auto p : files) {
			if (p.second.size() > 1) {
				res.push_back(p.second);
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> p;
	p.push_back("root/a 1.txt(abcd) 2.txt(efgh)");
	p.push_back("root/c 3.txt(abcd)");
	p.push_back("root/c/d 4.txt(efgh)");
	p.push_back("root 4.txt(efgh)");
	Solution s;
	s.findDuplicate(p);
	return 0;
}

