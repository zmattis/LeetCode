/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 *
 * There is an undirected connected tree with n nodes labeled from 0 to n - 1
 * and n - 1 edges.
 *
 * You are given the integer n and the array edges where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the tree.
 *
 * Return an array answer of length n where answer[i] is the sum of the
 * distances between the i^th node in the tree and all other nodes.
 */

// @lc code=start

#include <vector>

class Graph
{
private:
	int n;
	std::vector<std::vector<int>> adj;

	std::vector<int> count;
	std::vector<int> sum;

	void dfsPost(int node, int parent)
	{
		for (int child : this->adj[node])
		{
			if (child == parent) continue;

			this->dfsPost(child, node);
			this->count[node] += this->count[child];
			this->sum[node] += this->sum[child] + this->count[child];
		}
	}

	void dfsPre(int node, int parent)
	{
		for (int child : this->adj[node])
		{
			if (child == parent) continue;

			this->sum[child] = this->sum[node] - count[child] + this->n - count[child];
			this->dfsPre(child, node);
		}
	}

public:
	Graph(int n, const std::vector<std::vector<int>> &edges) : n(n)
	{
		this->adj.resize(n);
		for (const std::vector<int> &edge : edges)
		{
			int a = edge[0];
			int b = edge[1];
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		this->count = std::vector<int>(n, 1);
		this->sum = std::vector<int>(n, 0);
	}

	std::vector<int> distanceSum()
	{
		this->dfsPost(0, -1);
		this->dfsPre(0, -1);
		return this->sum;
	}
};

class Solution
{
public:
	std::vector<int> sumOfDistancesInTree(int n, const std::vector<std::vector<int>> &edges)
	{
		Graph g = Graph(n, edges);
		return g.distanceSum();
	}
};

// @lc code=end
