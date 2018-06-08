// leetcode-836-³¤·½ÐÎ¸²¸Ç.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool contain(vector<int>& rec1, vector<int>& rec2)
	{
		pair<int, int> p1, p2, p3, p4;
		p1.first = rec1[0];
		p1.second = rec1[1];
		p3.first = rec1[2];
		p3.second = rec1[3];
		p2.first = rec1[0];
		p2.second = rec1[3];
		p4.first = rec1[2];
		p4.second = rec1[1];
		if (p1.first<rec2[2] && p1.first>rec2[0] && p1.second<rec2[3] && p1.second>rec2[1])
			return 1;
		if (p2.first<rec2[2] && p2.first>rec2[0] && p2.second<rec2[3] && p2.second>rec2[1])
			return 1;
		if (p3.first<rec2[2] && p3.first>rec2[0] && p3.second<rec2[3] && p3.second>rec2[1])
			return 1;
		if (p4.first<rec2[2] && p4.first>rec2[0] && p4.second<rec2[3] && p4.second>rec2[1])
			return 1;
		return 0;
	}
	bool interect(vector<int>& rec1, vector<int>& rec2)
	{
		if (rec1[1] >= rec2[1] && rec1[1] <= rec2[3] && rec1[3] >= rec2[1] && rec1[3] <= rec2[3] && rec2[0] >= rec1[0] && rec2[0] <= rec1[2] && rec2[2] >= rec1[0] && rec2[2] <= rec1[2])
			return 1;
		if (rec2[1] >= rec1[1] && rec2[1] <= rec1[3] && rec2[3] >= rec1[1] && rec2[3] <= rec1[3] && rec1[0] >= rec2[0] && rec1[0] <= rec2[2] && rec1[2] >= rec2[0] && rec1[2] <= rec2[2])
			return 1;
		return 0;
	}
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		return contain(rec1, rec2) || contain(rec2, rec1)||interect(rec1, rec2);
	}
};
int main()
{
    return 0;
}

