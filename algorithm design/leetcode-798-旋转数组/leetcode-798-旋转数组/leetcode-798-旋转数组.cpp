// leetcode-798-��ת����.cpp : Defines the entry point for the console application.
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
	int bestRotation(vector<int>& A) {
		int N = A.size();
		vector<int>AddPoint(N + 1, 0);
		vector<int>MinusPoint(N + 1, 0);
		int count = 0;
		for (int i = 0; i<A.size(); i++)
		{
			if (i >= A[i]) count++;
			if (i >= A[i])
			{
				MinusPoint[i - A[i] + 1] += 1;    // for this A[i] element, rotate i-A[i]+1 times will change the point from 1 to 0
				AddPoint[i + 1] += 1;           // but at the i+1 move, the point will go back from 0 to 1
			}
			else
			{
				AddPoint[i + 1] += 1;               // for this A[i] element, rotate i+1 times will change the point from 0 to 1
				MinusPoint[i + 1 + N - A[i]] += 1;    // but after another N-A[i] move, the point will go back from 1 to 0
			}
		}
		int result = count;
		int K = 0;

		for (int k = 1; k<N; k++)
		{
			count += AddPoint[k];
			count -= MinusPoint[k];

			if (count>result)
			{
				result = count;
				K = k;
			}
		}
		return K;
	}
};
int main()
{
    return 0;
}

