// leetcode-74-矩阵搜索.cpp : 定义控制台应用程序的入口点。
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
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        if (target < m[0][0] || target > m[m.size() - 1][m[0].size() - 1]) 
        return false;
		int row = 0;
		int col = m[0].size() - 1;
		while(col>=0&&row<m.size())
		{
			if(target==m[row][col]) return true;
			if(target>m[row][col]) row++;
			else col--;
		}
		return false;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

