/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 *
 * There are n rooms labeled from 0 to n - 1 and all the rooms are locked
 * except for room 0. Your goal is to visit all the rooms. However, you cannot
 * enter a locked room without having its key.
 *
 * When you visit a room, you may find a set of distinct keys in it. Each key
 * has a number on it, denoting which room it unlocks, and you can take all of
 * them with you to unlock the other rooms.
 *
 * Given an array rooms where rooms[i] is the set of keys that you can obtain
 * if you visited room i, return true if you can visit all the rooms, or false
 * otherwise.
 */

// @lc code=start

#include <cstring>
#include <vector>
#include <queue>

class Solution
{
public:
	bool canVisitAllRooms(const std::vector<std::vector<int>> &rooms)
	{
		int n = rooms.size();

		bool visited[n];
		std::memset(visited, 0x00, sizeof(visited));

		std::queue<int> q;
		q.push(0);
		while (!q.empty())
		{
			int key = q.front();
			q.pop();

			if (visited[key]) continue;

			n--;
			visited[key] = true;

			for (int k : rooms[key]) q.push(k);
		}

		return !n;
	}
};

// @lc code=end
