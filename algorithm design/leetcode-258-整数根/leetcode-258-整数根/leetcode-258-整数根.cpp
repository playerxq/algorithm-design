// leetcode-258-整数根.cpp : 定义控制台应用程序的入口点。
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

