// leetcode-842-backtrack.cpp : Defines the entry point for the console application.
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
	bool isFibonacci(std::vector<int>& nums, int num) {
		std::size_t n = nums.size();
		return n < 2 || nums[n - 2] + nums[n - 1] == num;
	}
	void backtrack(std::vector<int>& answer, std::vector<int>& solution, std::string& source, int start)
	{
		if (start == source.length() && solution.size() >= 3)
		{
			answer = solution;
			return;
		}
		for (std::size_t i = start; i < source.length(); i++)
		{
			std::string s = source.substr(start, i - start + 1);
			if (s.size() > 1 && s[0] == '0') return;
			long long num = stoll(s);
			if (num > INT_MAX) return;
			if (isFibonacci(solution, num))
			{
				solution.push_back(num);
				backtrack(answer, solution, source, i + 1);
				solution.pop_back();
			}
		}
	}
	vector<int> splitIntoFibonacci(string S) {
		std::vector<int> answer;
		std::vector<int> candidate;
		backtrack(answer, candidate, S, 0);
		return answer;
	}
};
int main()
{
    return 0;
}

