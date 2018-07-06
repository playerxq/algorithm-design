// leetcode-856-×Ö·û´®»ØÎÄ.cpp : Defines the entry point for the console application.
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
	int scoreOfParentheses(string S) {
		int n = S.length();
		stack<int> st;
		st.push(-1);
		for (int i = 1; i < n; i++)
		{
			if (S[i] == '(')
				st.push(-1);
			else
			{
				if (st.top() == -1)
				{
					st.pop();
					st.push(1);
				}
				else
				{
					int temp = 0;
					while (st.top() != -1)
					{
						temp += st.top();
						st.pop();
					}
					st.pop();
					st.push(2*temp);
				}
			}
		}
		int res = 0;
		while (!st.empty())
		{
			res += st.top();
			st.pop();
		}
		return res;
	}
};

int main()
{
	Solution s;
	s.scoreOfParentheses("(()(()))");
    return 0;
}

