// leetcode-41-�ҵ���һ��ȱʧ������.cpp : �������̨Ӧ�ó������ڵ㡣
//k��������������  ��һ��ȱʧ��������(��1��ʼ����)��Ȼֵ��Ϊ[1,k+1]
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
	int partion(vector<int>& nums)
	{
		int q = -1;
		for(int i = 0;i<nums.size();i++)
		{
			if(nums[i]>0)
			{
				q++;
				swap(nums[i],nums[q]);
			}
		}
		return q;
	}
    int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		if(n==0)
			return 1;
		int k = partion(nums)+1;//[0:k-1]Ϊ�������� ���һ��ȱʧ����ֵ��Ϊ[1:k] ������Ϊ��������ʶ
		int temp = 0;
		int id = k;
		for(int i = 0;i<k;i++)
		{
			temp = abs(nums[i]);
			if(temp<=k)//����һ������������[1:k]�� ������Ϊ����������Ӧλ��Ϊ����
				nums[temp-1] = (nums[temp-1]<0)?nums[temp-1]:-nums[temp-1];
		}
		for(int i = 0;i<k;i++)//�鿴���� ��Ӧ��ֵΪ[1:k]
		{
			if(nums[i]>0)//û�г��ֹ�
			{
				id = i;
				break;
			}
		}
		return id+1;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	vector<int> ve;
	ve.push_back(3);
	ve.push_back(4);
	ve.push_back(-1);
	ve.push_back(6);
	ve.push_back(7);
	Solution s;
	s.firstMissingPositive(ve);
}

