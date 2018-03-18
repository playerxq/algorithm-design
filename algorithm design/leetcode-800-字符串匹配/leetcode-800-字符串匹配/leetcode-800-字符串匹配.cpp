// leetcode-800-×Ö·û´®Æ¥Åä.cpp : Defines the entry point for the console application.
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
	string similarRGB(string color) {
		map<string, long long> mp;
		string s1 = (color.substr(1, 2));
		string s2 = (color.substr(3,2));
		string s3 = (color.substr(5, 2));
		int t1 = (s1[0]>'9'?s1[0]-'a'+10:s1[0]-'0') * 16 + (s1[1] > '9' ? s1[1] - 'a'+10 : s1[1] - '0');
		int t2 = (s2[0] > '9' ? s2[0] - 'a'+10 : s2[0] - '0') * 16 + (s2[1] > '9' ? s2[1] - 'a'+10 : s2[1] - '0');
		int t3 = (s3[0] > '9' ? s3[0] - 'a'+10 : s3[0] - '0') * 16 + (s3[1] > '9' ? s3[1] - 'a' +10: s3[1] - '0');
		vector<char> ve = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
		for (int i = 0; i <ve.size(); i++)
		{
			for (int j = 0; j <ve.size(); j++)
			{
				for (int k = 0; k <ve.size(); k++)
				{
					string s="#";
					s += ve[i];
					s += ve[i];
					int s11 = i * 16 + i;
					s += ve[j];
					s += ve[j];
					int s22 = j * 16 + j;
					string s3 = to_string(k);
					s += ve[k];
					s += ve[k];
					int s33 = k * 16 + k;
					if (s == "#11ee66")
					{
						int a = 1;
					}
					long long res = (t1 - s11)*(t1 - s11) + (t2 - s22)*(t2 - s22) + (t3 - s33)*(t3 - s33);
					mp.insert(make_pair(s,res*(-1)));
				}
			}
		}
		string rr;
		long long minx = INT_MIN;
		for (map<string, long long>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second > minx)
			{
				minx = it->second;
				rr = it->first;
			}
		}
		return rr;
	}
};

int main()
{
	Solution s;
	s.similarRGB("#09f166");
    return 0;
}

