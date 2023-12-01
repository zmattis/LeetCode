/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
 *
 * You are given a 0-indexed integer array tasks, where tasks[i] represents the
 * difficulty level of a task. In each round, you can complete either 2 or 3
 * tasks of the same difficulty level.
 *
 * Return the minimum rounds required to complete all the tasks, or -1 if it is
 * not possible to complete all the tasks.
 */

// @lc code=start

#include <vector>
#include <unordered_map>

class Solution
{
public:
	int minimumRounds(const std::vector<int> &tasks)
	{
		std::unordered_map<int, int> hm;
		for (int task : tasks) { hm[task]++; }

		int count = 0;
		for (auto [task, num] : hm)
		{
			if (num == 1) return -1;

			if (num % 3 == 0) count += num / 3;
			else count += (num / 3) + 1;
		}

		return count;
	}
};

// @lc code=end
