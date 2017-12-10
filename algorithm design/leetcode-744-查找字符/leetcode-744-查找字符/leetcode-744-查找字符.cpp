// leetcode-744-²éÕÒ×Ö·û.cpp : Defines the entry point for the console application.
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
	char nextGreatestLetter(vector<char>& letters, char target) {
		int n = letters.size();
		for (int i = 0; i < n; i++)
		{
			if (letters[i] > target)
				return letters[i];
		}
		return letters[0];
	}
};
int main()
{
    return 0;
}

