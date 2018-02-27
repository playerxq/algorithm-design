// leetcode-785-bfs.cpp : Defines the entry point for the console application.
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
	bool isBipartite(vector<vector<int>>& graph) {
		// vector subset indicates the subset node is in: 0 for unvisited, 1 for set A, -1 for set B
		vector<int> subset(graph.size(), 0);

		for (int i = 0; i < graph.size(); i++) {
			// if not in any subset (start of new disjoint graph), arbitrarily put in set A (set 1)
			if (subset[i] == 0)
				subset[i] = 1;
			// DFS queue to sort all connected edges
			queue<int> connections;
			connections.push(i);

			while (!connections.empty()) {
				int node = connections.front();
				connections.pop();
				for (int j = 0; j < graph[node].size(); j++) {
					// every edge connects to otherNode, which can be in...
					int otherNode = graph[node][j];
					// same subset: violates bipartite
					if (subset[otherNode] == subset[node])
						return false;
					// no subset: put into subset that node is not in
					if (subset[otherNode] == 0) {
						subset[otherNode] = -subset[node];
						connections.push(otherNode);
					}
					// otherwise, already in different subset, continue;
				}
			}
		}
		// if every connection passes, graph is bipartite
		return true;
	}
};
int main()
{
    return 0;
}

