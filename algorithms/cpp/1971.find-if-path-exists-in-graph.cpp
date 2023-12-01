/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 *
 * There is a bi-directional graph with n vertices, where each vertex is
 * labeled from 0 to n - 1 (inclusive). The edges in the graph are represented
 * as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a
 * bi-directional edge between vertex ui and vertex vi. Every vertex pair is
 * connected by at most one edge, and no vertex has an edge to itself.
 *
 * You want to determine if there is a valid path that exists from vertex
 * source to vertex destination.
 *
 * Given edges and the integers n, source, and destination, return true if
 * there is a valid path from source to destination, or false otherwise.
 */

// @lc code=start

#include <vector>
#include <queue>
#include <cstring>

class Solution
{
public:
	bool validPath(int n, std::vector<std::vector<int>> &edges, int source, int destination)
	{
		bool visited[n];
		std::memset(visited, 0x00, sizeof(visited));

		std::queue<int> q;
		q.push(source);

		while (!q.empty())
		{
			int node = q.front();
			q.pop();

			if (visited[node]) continue;
			if (node == destination) return true;

			visited[node] = true;
			for (const auto &edge : edges)
			{
				int u = edge[0];
				int v = edge[1];
				if (v == node) q.push(u);
				if (u == node) q.push(v);
			}
		}

		return false;
	}
};

// @lc code=end
