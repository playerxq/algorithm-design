// leetcode-258-������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Solution {
public:
	int addDigits(int num) {
		if (num == 0)
			return 0;
		else if (num < 9)
			return num;
		else if (num % 9 == 0)
			return 9;
		return num % 9;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

