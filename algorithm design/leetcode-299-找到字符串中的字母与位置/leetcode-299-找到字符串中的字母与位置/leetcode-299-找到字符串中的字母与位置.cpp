// leetcode-299-找到字符串中的字母与位置.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <unordered_map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		unordered_map<int, int> se;
		unordered_map<int, int> gu;
		for (int i = 0; i < secret.length(); i++)
		{
			se[secret[i] - '0']++ ;
		}
		for (int i = 0; i < guess.length(); i++)
		{
			gu[guess[i] - '0']++;
		}
		int cow = 0;
		int bull = 0;
		for (int i = 0; i < secret.length(); i++)
		{
			if (secret[i] == guess[i])
				cow++;
		}
		int sum = 0;
		for (int i = 0; i <= 9; i++)
			sum += min(se[i],gu[i]);
		bull = sum - cow;
		string res = to_string(cow) + "A" + to_string(bull) + "B";
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

