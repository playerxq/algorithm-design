// leetcode-137-����������ֻ����һ��������Ԫ�ؾ�����3�ε���.cpp : �������̨Ӧ�ó������ڵ㡣
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

