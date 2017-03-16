// leetcode-535-URL编码.cpp : 定义控制台应用程序的入口点。
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
	int cnt = 0;
	string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unordered_map<string, string> id;
	unordered_map<int, string> rev;
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		if (id.find(longUrl) != id.end())
			return id[longUrl];
		string res = "";
		cnt++;
		int cc = cnt;
		while (cc)
		{
			res += dict[cc % 62];
			cc /= 62;
		}
		while (res.size() < 6)
			res = '0' + res;
		id[longUrl] = res;
		rev[cnt] = longUrl;
		return res;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		int cc = 0;
		for (int i = 0; i < shortUrl.size(); i++)
		{
			int t = dict.find(shortUrl[i]);
			cc = cc * 62 + t;
		}
		if (rev.find(cc) != rev.end())
			return rev[cc];
		return "";
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

