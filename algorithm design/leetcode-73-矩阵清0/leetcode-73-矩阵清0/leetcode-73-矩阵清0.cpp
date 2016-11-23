// leetcode-73-矩阵清0.cpp : 定义控制台应用程序的入口点。
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
    void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.empty()) return;
		int rowsize = matrix.size();
		int colsize = matrix[0].size();
		bool rowstate = false;
		bool colstate = false;
		for(int i = 0;i<colsize;i++)
		{
			if(matrix[0][i]==0)
			{
				rowstate = true;
				break;
			}
		}
		for(int i = 0;i<rowsize;i++)
		{
			if(matrix[i][0]==0)
			{
				colstate = true;
				break;
			}
		}
		for(int i = 1;i<rowsize;i++)
		{
			for(int j = 1;j<colsize;j++)
			{
				if(matrix[i][j]==0)
				{
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for(int i = 1;i<colsize;i++)
		{
			if(matrix[0][i]==0)
			{
				for(int j = 1;j<rowsize;j++)
				{
					matrix[j][i]=0;
				}
			}
		}
		for(int i = 1;i<rowsize;i++)
		{
			if(matrix[i][0]==0)
			{
				for(int j = 1;j<colsize;j++)
				{
					matrix[i][j]=0;
				}
			}
		}
		if(rowstate)
		{
			for(int i = 0;i<colsize;i++)
				matrix[0][i]=0;
		}
		if(colstate)
		{
			for(int i = 0;i<rowsize;i++)
				matrix[i][0]=0;
		}
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

