// leetcode-409-最长回文.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> cnt;
		int len = s.length();
		if (!len)
			return 0;
		int sum = 0;
		int max_odd = 0;
		int odd = 0;
		for (int i = 0; i < len; i++)
			cnt[s[i]]++;
		for (int i = 0; i < len; i++)
		{
			if (cnt[s[i]] != 0)
			{
				if (cnt[s[i]] % 2 == 0)
				{
					sum += cnt[s[i]];
					cnt[s[i]] = 0;
				}
				else
				{
					sum += (cnt[s[i]]-1);
					if (max_odd < cnt[s[i]])
					{
						max_odd = cnt[s[i]];
					}
					cnt[s[i]] = 0;
				}
			}
		}
		if (max_odd != 0)
			odd++;
		return sum + odd;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
	//s.longestPalindrome("abccccdd");
	return 0;
}

