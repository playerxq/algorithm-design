// leetcode-137-查找数组中只出现一次且其他元素均出现3次的数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> t(32);
		int n = nums.size();
		for(int i = 0;i<n;i++)
		{
			int tt = nums[i];
			for(int j = 31;j>=0;j--)
			{
				t[j]+=tt&1;
				tt>>=1;
				if(!tt)
					break;
			}
		}
		int res = 0;
		for(int i = 31;i>=0;i--)
		{
			int ttt = t[i]%3;
			if(ttt)
				res+=1<<(31-i);
		}
		return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

