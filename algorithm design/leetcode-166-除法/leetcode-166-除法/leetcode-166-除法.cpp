// leetcode-166-除法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//numerator/denominator
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        res += to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp; 
        while (rmd) {
            long que = rmd/denom;
			if(mp.find(rmd)!=mp.end())
			{
				res.insert(mp[rmd],1,'(');
				res+=(')');
				break;
			}
			mp[rmd] = res.size();
			res+=to_string(que);
			rmd = rmd%denom;
			rmd = rmd*10;
        }
        return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

