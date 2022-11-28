/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 *
 * You are given an integer array matches where matches[i] = [winneri, loseri]
 * indicates that the player winneri defeated player loseri in a match.
 *
 * Return a list answer of size 2 where:
 *     answer[0] is a list of all players that have not lost any matches.
 *     answer[1] is a list of all players that have lost exactly one match.
 *
 * The values in the two lists should be returned in increasing order.
 */

// @lc code=start

#include <stdint.h>
#include <vector>
#include <map>

class Solution
{
public:
	std::vector<std::vector<int32_t>> findWinners(std::vector<std::vector<int32_t>> &matches)
	{
		// <playerId, <wins, losses>>
		std::map<int32_t, std::pair<int32_t, int32_t>> hm;

		for (const std::vector<int32_t> &match : matches)
		{
			int32_t idWinner = match[0];
			int32_t idLoser = match[1];

			hm[idWinner].first++;
			hm[idLoser].second++;
		}

		std::vector<int32_t> arrayLose0;
		std::vector<int32_t> arrayLose1;
		for (auto it = hm.begin(); it != hm.end(); it++)
		{
			if (it->second.second == 0)
			{
				arrayLose0.push_back(it->first);
			}
			else if (it->second.second == 1)
			{
				arrayLose1.push_back(it->first);
			}
		}

		return {arrayLose0, arrayLose1};
	}
};

// @lc code=end
