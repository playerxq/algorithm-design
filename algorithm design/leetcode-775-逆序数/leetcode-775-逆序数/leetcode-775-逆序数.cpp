// leetcode-775-ÄæÐòÊý.cpp : Defines the entry point for the console application.
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
	void Merge(vector<int>& ve, int first, int med, int last, int& cnt, vector<int>& temp)
	{
		int i = first, j = med + 1;
		int cur = 0;
		while (i <= med&&j <= last)
		{
			if (ve[i]<ve[j])
			{
				temp[cur++] = ve[i++];
			}
			else
			{
				temp[cur++] = ve[j++];
				cnt += med - i + 1;
			}
		}
		while (i <= med)
		{
			temp[cur++] = ve[i++];
		}
		while (j <= last)
		{
			temp[cur++] = ve[j++];
		}
		for (int m = 0; m<cur; m++)
		{
			ve[first++] = temp[m];
		}
	}
	void MergeSort(vector<int>& ve, int first, int last,int& cnt, vector<int>& temp)
	{
		if (first == last)
		{
			return;
		}
		int med = first + (last - first) / 2;
		MergeSort(ve,first,med,cnt,temp);
		MergeSort(ve,med + 1,last,cnt,temp);
		Merge(ve, first, med, last,cnt,temp);
	}
	int get_total(vector<int>& ve)
	{
		int cnt = 0;
		int n = ve.size();
		vector<int> temp(n);
		MergeSort(ve,0,n-1,cnt,temp);
		return cnt;
	}
	bool isIdealPermutation(vector<int>& A) {
		int n = A.size();
		if (!n)
			return true;
		int sum1 = 0;
		for (int i = 0; i < n-1; i++)
		{
			if (A[i] > A[i + 1])
				sum1++;
		}
		int sum = get_total(A);
		if (sum1 == sum)
			return true;
		return false;
	}
};

int main()
{
	Solution s;
	vector<int> A = {2,0,1};
	s.isIdealPermutation(A);
    return 0;
}

