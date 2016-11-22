// leetcode-4-两个数组中位数.cpp : 定义控制台应用程序的入口点。
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
class Solution {  
  
 int getMedian(int A[], int m, int B[], int n,int k)  
    {  
        if(m>n)  
            return getMedian(B,n,A,m, k);  
        if(m ==0)  
            return B[k-1];  
        if(k==1)  
            return min(A[0], B[0]);  
        int pa = min(k/2, m);  
        int pb = k - pa;  
        if (A[pa-1] < B[pb-1]) {  
            return getMedian(A+pa, m-pa, B, n, k-pa);  
        } else if(A[pa-1] > B[pb-1]) {  
            return getMedian(A, m, B+pb, n-pb, k-pb);  
        }else{  
            return A[pa-1];  
        }  
          
        return 0;  
      
      
    }  
   public: double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
			   int m = nums1.size();
			   int n = nums2.size();
			   int* A = new int[m];
			   int* B = new int[n];
			   for(int i = 0;i<m;i++)
				   A[i] = nums1[i];
			   for(int i = 0;i<n;i++)
				   B[i] = nums2[i];
        if ((m+n)%2 == 0) {  
            return (getMedian(A, m,B, n, (m+n)/2) + getMedian(A, m,B, n, (m+n)/2+1)) /2.0;  
        } else {  
            return getMedian(A, m,B, n, (m+n)/2+1);  
        }  
          
    }  
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	getchar();
}

