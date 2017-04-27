// leetcode-564-回文查找-难.cpp : 定义控制台应用程序的入口点。
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
	string palindromeStr(const string& s) {//从s的左半边翻转生成一个回文
		int i = 0;
		int j = s.size() - 1;
		string ret = s;
		while (i <= j) {
			ret[j] = ret[i];
			i++;
			j--;
		}
		return ret;
	}
	string dec2Palindrome(const string& s) {//左半边-1翻转后构成回文
		string pal = s;
		int left = (int)(s.size() - 1) / 2;
		int right = (int)s.size() / 2;
		while (left >= 0) {
			if (pal[left] > '0') {
				pal[left] = pal[left] - 1;
				if (left < right) {
					pal[right] = pal[right] - 1;
				}
				break;
			}
			else {
				pal[left] = pal[right] = '9';
				left--;
				right++;
			}
		}
		if ((pal[0] == '0') && (pal.size() > 1)) {
			pal[right] = '9';
			pal.erase(pal.begin());
		}
		return pal;
	}
	string inc2Palindrome(const string& s) {//左半边+1翻转后构成回文
		string pal = s;
		int left = (int)(s.size() - 1) / 2;
		int right = (int)s.size() / 2;
		while (left >= 0) {
			if (pal[left] < '9') {
				pal[left] = pal[left] + 1;
				if (left < right) {
					pal[right] = pal[right] + 1;
				}
				break;
			}
			else {
				pal[left] = pal[right] = '0';
				left--;
				right++;
			}
		}
		if (pal[0] == '0') {
			pal.back() = '1';
			pal.insert(pal.begin(), '1');
		}
		return pal;
	}
	string nearestPalindromic(string n) {
		if (n == "0") {
			return "-1";
		}
		//Find the almost closest palindrome integer
		string pal = palindromeStr(n);
		long low;
		long up;
		long num = stoll(n);
		string lowPal;
		string upPal;
		if (pal == n) {
			//For n is a palindrome number, find the two closest palindrome integer, 
			//one is larger than n and the other is less than n
			lowPal = dec2Palindrome(n);
			upPal = inc2Palindrome(n);
		}
		//For the other cases, find the corresponding another palindrome integer
		else if (pal < n) {
			lowPal = pal;
			upPal = inc2Palindrome(pal);
		}
		else {
			upPal = pal;
			lowPal = dec2Palindrome(pal);
		}
		low = stoll(lowPal);
		up = stoll(upPal);
		if (num - low <= up - num) {
			return lowPal;
		}
		else {
			return upPal;
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

