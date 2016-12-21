// leetcode-179-组成最大的数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;
int cmp(const void* _a,const void* _b)
	{
		int* a = (int*)_a;
		int* b = (int*)_b;
		int a1 = *a;
		int a2 = *b;
		int aa1 = a1;
		int aa2 = a2;
		int t1 = 0;
		int t2 = 0;
		if(a1==0)
			t1 = 1;
		if(a2==0)
			t2 = 1;
		while(a1)
		{
			t1++;
			a1/=10;
		}
		while(a2)
		{
			t2++;
			a2/=10;
		}
		long long tt1 = aa1*pow(10.0,t2)+aa2;
		long long tt2 = aa2*pow(10.0,t1)+aa1;
		if(tt1<tt2)
			return 1;
		else if(tt1>tt2)
			return -1;
		return 0;
	}
class Solution {
public:
	
    string largestNumber(vector<int>& nums) {
		int n = nums.size();
		string res;
		if(!n)
			return res;
		if(n==1)
			return to_string((long long)nums[0]);
		int* nn = new int[n+1];
		for(int i = 0;i<n;i++)
			nn[i] = nums[i];
		qsort(nn,n,sizeof(int),cmp);
        for(int i = 0;i<n;i++)
		{
			res+=to_string((long long)nn[i]);
		}
		int t = 0;
		while(t<res.length()&&res[t]=='0')
			t++;
		if(t==res.length())
			return "0";
		res = res.substr(t);
		return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	//nums.push_back(8);
	//nums.push_back(7);
	//nums.push_back(6);
	//nums.push_back(5);
	//nums.push_back(4);
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(1);
	Solution s;
	s.largestNumber(nums);
	return 0;
}

