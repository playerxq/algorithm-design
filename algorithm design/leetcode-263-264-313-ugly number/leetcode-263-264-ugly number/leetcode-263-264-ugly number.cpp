// leetcode-263-264-ugly number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
	bool isUgly(int num) {
		if (num == 0)
			return false;
		if (num == 1)
			return true;
		while (num != 1)
		{
			while (num % 2 == 0)
				num /= 2;
			while (num % 3 == 0)
				num /= 3;
			while (num % 5 == 0)
				num /= 5;
			if (num != 1)
				return false;
		}
		return true;
	}
};
class Solution2 {
public:
	int nthUglyNumber(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		int t2 = 0;
		int t3 = 0;
		int t5 = 0;
		vector<int> ve(n);
		ve[0] = 1;
		for (int i = 1; i < n; i++)
		{
			ve[i] = min(ve[t2]*2,min(ve[t3]*3,ve[t5]*5));
			if (ve[i] == ve[t2] * 2)
				t2++;
			if (ve[i] == ve[t3] * 3)
				t3++;
			if (ve[i] == ve[t5] * 5)
				t5++;
		}
		return ve[n-1];

	}
};
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int len = primes.size();
		int* t = new int[len+1];
		for (int i = 0; i < len + 1; i++)
			t[i] = 0;
		int* ugly = new int[n+1];
		ugly[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			ugly[i] = INT_MAX;
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < len; j++)
			{
				ugly[i] = min(ugly[i],primes[j]*ugly[t[j]]);
			}
			for (int j = 0; j < len; j++)
			{
				t[j] += (ugly[i] == primes[j] * ugly[t[j]] ? 1 : 0);
			}
		}
		return ugly[n-1];
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> ve;
	ve.push_back(2);
	ve.push_back(5);
	ve.push_back(7);
	ve.push_back(11);
	ve.push_back(13);
	ve.push_back(17);
	ve.push_back(23);
	ve.push_back(29);
	ve.push_back(43);
	ve.push_back(53);
	Solution s;
	s.nthSuperUglyNumber(10,ve);
	return 0;
}

