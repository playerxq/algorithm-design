// leetcode-263-264-ugly number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
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
class Solution {
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
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

