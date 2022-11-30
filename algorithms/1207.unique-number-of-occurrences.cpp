/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * Given an array of integers arr, return true if the number of occurrences of
 * each value in the array is unique, or false otherwise.
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution
{
public:
	bool uniqueOccurrences(const std::vector<int32_t> &array)
	{
		std::unordered_map<int32_t, int32_t> hm;
		for (int32_t val : array) { hm[val]++; }

		std::unordered_set<int32_t> ht;
		for (auto it = hm.begin(); it != hm.end(); it++)
		{
			auto [val,count] = *it;
			if (ht.find(count) != ht.end()) { return false; }
			ht.insert(count);
		}

		return true;
	}
};

// @lc code=end
