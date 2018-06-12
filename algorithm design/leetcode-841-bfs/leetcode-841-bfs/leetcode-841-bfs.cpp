// leetcode-841-bfs.cpp : Defines the entry point for the console application.
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
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		if (rooms.empty())
			return true;
		queue<int> curr;
		unordered_set<int> open_rooms;
		open_rooms.insert(0);
		curr.push(0);
		while (!curr.empty())
		{
			int temp = curr.front();
			curr.pop();
			if (rooms[temp].empty() || rooms[temp][0] == -1)
			{
				continue;
			}
			for (int i = 0; i < rooms[temp].size(); i++)
			{
				curr.push(rooms[temp][i]);
				open_rooms.insert(rooms[temp][i]);
			}
			rooms[temp][0] = -1;
		}
		return rooms.size() == open_rooms.size();
	}
};

int main()
{
    return 0;
}

