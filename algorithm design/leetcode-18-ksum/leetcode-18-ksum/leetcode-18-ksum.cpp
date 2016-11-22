// leetcode-18-ksum.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
	void Ksum(int k, vector<int> nums, int l, int r, int target, vector<vector<int>>& res, vector<int>& ve, int ci)
	{
		int i,mn,mx;
		int km1 = k-1;
		if(r-l+1<k)
			return;
		while(l<r)
		{
			mn = nums[l];
			mx = nums[r];
			if((mn+mx*km1)<target)
				l++;
			else if((km1*mn+mx)>target)
				r--;
			else if(k*mn>target)
				break;
			else if(k*mx<target)
				break;
			else if(k*mn==target)
			{
				if((l+km1<=r)&&((nums[l+km1])==mn))
				{
					for ( i = 0; i < k; i++ ) ve[ci+i] = mn;
                    res.push_back( ve );
				}
				break;
			}
			else if ( k*mx == target )
            {
                if ( ( l <= r - km1 ) && ( mx == ( nums[r-km1] ) ) )
                {
                    for ( i = 0; i < k; i++ ) ve[ci+i] = mx;
                    res.push_back( ve );
                }
                break;                
            }
			else if(k==2)
			{
				ve[ci]=mn;
				ve[ci+1]=mx;
				res.push_back(ve);
				l++;
				while((l<r)&&(nums[l]==mn)) l++;
				r--;
				while((l<r)&&(nums[r]==mx)) r--;
			}
			else
			{
				ve[ci]=mn;
				Ksum(km1,nums,++l,r,target-mn,res,ve,ci+1);
				while((l<r)&&(nums[l]==nums[l-1])) l++;
			}
		}
	}
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
		vector<int> ve(4,0);
		ve.clear();
		res.clear();
		sort(nums.begin(),nums.end());
		Ksum(4,nums,0,nums.size()-1,target,res,ve,0);
		return res;
    }
};
*/
class Solution {
private:
    // Valid for K >= 2
    void KSum(int k, vector<int>& nums, int l, int r, int target, vector<vector<int>>& retVal, vector<int>& cur, int ci ) 
    {
        int i, mn, mx;
        int km1 = k - 1;

        if ( r-l+1 < k ) return;
        
        while ( l < r )
        {
            mn = nums[l];
            mx = nums[r];
            
            // If K minus 1 largest + min < target, move to larger
            if ( ( mn + km1*mx ) < target ) l++;
            // If K minus 1 smaller + max > target, move to smaller
            else if ( ( km1*mn + mx ) > target ) r--;
            // If K * min > target, stop looking
            else if ( k*mn > target ) break;
            // If K * min == target, reached the threshold, check then stop looking
            else if ( k*mn == target )
            {
                if ( ( l + km1 <= r ) && ( mn == ( nums[l+km1] ) ) )
                {
                    for ( i = 0; i < k; i++ ) cur[ci+i] = mn;
                    retVal.push_back( cur );
                }
                break;
            }
            // If K * max < target, stop looking
            else if ( k*mx < target ) break;
            // If K * max == target, reached the threshold, check then stop looking
            else if ( k*mx == target )
            {
                if ( ( l <= r - km1 ) && ( mx == ( nums[r-km1] ) ) )
                {
                    for ( i = 0; i < k; i++ ) cur[ci+i] = mx;
                    retVal.push_back( cur );
                }
                break;                
            }
            // If K == 2, we found a match!
            else if ( k == 2 )
            {
                cur[ci] = mn;
                cur[ci+1] = mx;
                retVal.push_back( cur );
                l++;
                while ( ( l < r ) && ( nums[l] == mn ) ) l++;
                r--;
                while ( ( l < r ) && ( nums[r] == mx ) ) r--;
            }
            // Otherwise, convert the problem to a K-1 problem
            else
            {
                cur[ci] = mn;
                KSum( km1, nums, ++l, r, target - mn, retVal, cur, ci+1 );
                while ( ( l < r ) && ( nums[l] == nums[l-1] ) ) l++;
            }
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> lRetVal;
        vector<int> lQuad( 4, 0 ); // Pre-allocate the size of the result

        // Sort to provide a mechanism for avoiding duplicates
        sort( nums.begin(), nums.end() );
        
        KSum( 4, nums, 0, nums.size()-1, target, lRetVal, lQuad, 0 );

        return( lRetVal );        
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	Solution s;
	vector<int> nn;
	nn.push_back(1);
	nn.push_back(0);
	nn.push_back(-1);
	nn.push_back(0);
	nn.push_back(-2);
	nn.push_back(2);
	s.fourSum(nn,0);
}

