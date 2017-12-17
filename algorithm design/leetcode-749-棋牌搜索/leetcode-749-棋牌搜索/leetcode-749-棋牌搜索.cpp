// leetcode-749-ÆåÅÆËÑË÷.cpp : Defines the entry point for the console application.
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
	int containVirus(vector<vector<int>>& grid) {
		size_t row = grid.size(), col = grid[0].size();
		int dirs[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
		vector<vector<bool>> control = vector<vector<bool>>(row, vector<bool>(col, false));
		int numWalls = 0;
		while (true)
		{
			// Search for the points with most infection
			vector<vector<bool>> visited = vector<vector<bool>>(row, vector<bool>(col, false));
			vector<vector<int>> infection = vector<vector<int>>(row, vector<int>(col, 0));
			int mostInfection = 0;
			for (int x = 0; x < row; x++)
			{
				for (int y = 0; y < col; y++)
				{
					if (!control[x][y] && !visited[x][y] && grid[x][y] == 1)
					{
						vector<vector<bool>> infectionVisited = vector<vector<bool>>(row, vector<bool>(col, false));
						visited[x][y] = true;
						int infectionSize = 0;
						queue<pair<int, int>> bfs;
						bfs.push({ x, y });
						while (!bfs.empty())
						{
							auto point = bfs.front();
							int px = point.first, py = point.second;
							bfs.pop();
							for (size_t i = 0; i < 4; i++)
							{
								int newx = px + dirs[i][0], newy = py + dirs[i][1];
								if (newx >= 0 && newx < row && newy >= 0 && newy < col)
								{
									if (!control[newx][newy] && !visited[newx][newy])
									{
										if (grid[newx][newy] == 1)
										{
											visited[newx][newy] = true;
											bfs.push({ newx, newy });
										}
										else if (!infectionVisited[newx][newy])
										{
											infectionVisited[newx][newy] = true;
											infectionSize++;
										}
									}
								}
							}
						}
						infection[x][y] = infectionSize;
						mostInfection = max(mostInfection, infectionSize);
					}
				}
			}
			if (mostInfection == 0) {
				break;
			}
			// Calculate the number of walls needed
			for (int x = 0; x < row; x++)
			{
				for (int y = 0; y < col; y++)
				{
					if (infection[x][y] == mostInfection)
					{
						visited = vector<vector<bool>>(row, vector<bool>(col, false));
						visited[x][y] = true;
						queue<pair<int, int>> bfs;
						bfs.push({ x, y });
						while (!bfs.empty())
						{
							auto point = bfs.front();
							int px = point.first, py = point.second;
							bfs.pop();

							control[x][y] = true;
							for (size_t i = 0; i < 4; i++)
							{
								int newx = px + dirs[i][0], newy = py + dirs[i][1];
								if (newx >= 0 && newx < row && newy >= 0 && newy < col)
								{
									if (!control[newx][newy] && !visited[newx][newy])
									{
										if (grid[newx][newy] == 1)
										{
											control[newx][newy] = true;
											visited[newx][newy] = true;
											bfs.push({ newx, newy });
										}
										else
										{
											numWalls++;
										}
									}
								}
							}
						}
						infection[x][y] = 0;
						break;
					}
				}
			}
			// Infect the virus
			vector<vector<int>> newGrid = grid;
			for (int x = 0; x < row; x++)
			{
				for (int y = 0; y < col; y++)
				{
					if (infection[x][y] > 0)
					{
						visited = vector<vector<bool>>(row, vector<bool>(col, false));
						visited[x][y] = true;
						queue<pair<int, int>> bfs;
						bfs.push({ x, y });
						while (!bfs.empty())
						{
							auto point = bfs.front();
							int px = point.first, py = point.second;
							bfs.pop();

							for (size_t i = 0; i < 4; i++)
							{
								int newx = px + dirs[i][0], newy = py + dirs[i][1];
								if (newx >= 0 && newx < row && newy >= 0 && newy < col)
								{
									if (!control[newx][newy] && !visited[newx][newy])
									{
										if (grid[newx][newy] == 1)
										{
											visited[newx][newy] = true;
											bfs.push({ newx, newy });
										}
										else
										{
											newGrid[newx][newy] = 1;
										}
									}
								}
							}
						}
					}
				}
			}
			grid = newGrid;
		}
		return numWalls;
	}
};

int main()
{
    return 0;
}

