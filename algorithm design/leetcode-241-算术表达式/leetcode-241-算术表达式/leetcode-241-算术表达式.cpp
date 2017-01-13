// leetcode-241-算术表达式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <sstream>
#include <algorithm>
using namespace std;
string int2str(const int &int_temp)
{
	string string_temp;
	stringstream stream;
	stream << int_temp;
	string_temp = stream.str();   //此处也可以用 stream>>string_temp  
	return string_temp;
}
int str2int(const string &string_temp)
{
	int int_temp = 0;
	stringstream stream(string_temp);
	stream >> int_temp;
	return int_temp;
}
class Solution {
public:
	void calc(string input, vector<int>& res)
	{
		int flag = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				flag = 1;
				vector<int> temp1;
				vector<int> temp2;
				calc(input.substr(0, i), temp1);
				calc(input.substr(i + 1), temp2);
				int l1 = temp1.size();
				int l2 = temp2.size();
				for (int s = 0; s < l1; s++)
				{
					for (int t = 0; t < l2; t++)
					{
						if (input[i] == '+')
							res.push_back(temp1[s] + temp2[t]);
						else if (input[i] == '-')
							res.push_back(temp1[s] - temp2[t]);
						else
							res.push_back(temp1[s] * temp2[t]);
					}
				}
			}
		}
		if (!flag)
			res.push_back(str2int(input));
	}
	vector<int> diffWaysToCompute(string input) {
		vector<int> res;
		if (input.size() == 0)
			return res;
		int flag = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				flag = 1;
				vector<int> temp1;
				vector<int> temp2;
				calc(input.substr(0,i),temp1);
				calc(input.substr(i+1),temp2);
				int l1 = temp1.size();
				int l2 = temp2.size();
				for (int s = 0; s < l1; s++)
				{
					for (int t = 0; t < l2; t++)
					{
						if (input[i] == '+')
							res.push_back(temp1[s]+temp2[t]);
						else if (input[i] == '-')
							res.push_back(temp1[s] - temp2[t]);
						else
							res.push_back(temp1[s] * temp2[t]);
					}
				}
			}
		}
		if (!flag)
			res.push_back(str2int(input));
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

