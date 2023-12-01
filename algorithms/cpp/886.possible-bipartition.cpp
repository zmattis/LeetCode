/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * We want to split a group of n people (labeled from 1 to n) into two groups
 * of any size. Each person may dislike some other people, and they should not
 * go into the same group.
 *
 * Given the integer n and the array dislikes where dislikes[i] = [ai, bi]
 * indicates that the person labeled ai does not like the person labeled bi,
 * return true if it is possible to split everyone into two groups in this
 * way.
 */

// @lc code=start

#include <vector>
#include <set>

class DisjointSet
{
private:
	std::vector<int> root;

public:
	DisjointSet(int n) : root(n)
	{
		for (int i=0;i<n;i++) this->root[i] = i;
	};

	int Find(int v)
	{
		return this->root[v];
	}

	void Union(int x, int y)
	{
		int rootX = this->root[x];
		int rootY = this->root[y];

		if (rootX != rootY)
		{
			this->root[y] = rootX;
			for (int i=0;i<root.size();i++)
			{
				if (this->root[i] == rootY) this->root[i] = rootX;
			}
		}
	}

	bool Connected(int x, int y)
	{
		return this->Find(x) == this->Find(y);
	}
};

class Solution
{
public:
	bool possibleBipartition(int n, const std::vector<std::vector<int>> &dislikes)
	{
		std::vector<std::vector<int>> adj(n);
		for (const std::vector<int> &pair : dislikes)
		{
			int x = pair[0]-1;
			int y = pair[1]-1;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		DisjointSet ds(n);
		for (int i = 0; i < n; i++)
		{
			for (int neighbor : adj[i])
			{
				if (ds.Connected(i, neighbor)) return false;
				ds.Union(adj[i][0], neighbor);
			}
		}

		return true;
	}
};

// @lc code=end
