/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 *
 * You are given a 0-indexed integer array nums of length n.
 *
 * The average difference of the index i is the absolute difference between the
 * average of the first i + 1 elements of nums and the average of the last n -
 * i - 1 elements. Both averages should be rounded down to the nearest
 * integer.
 *
 * Return the index with the minimum average difference. If there are multiple
 * such indices, return the smallest one.
 *
 * Note:
 *     - The absolute difference of two numbers is the absolute value of their difference.
 *     - The average of n elements is the sum of the n elements divided (integer division) by n.
 *     - The average of 0 elements is considered to be 0.
 */

// @lc code=start

#include <stdint.h>
#include <vector>
#include <numeric>
#include <cstdlib>

class Solution
{
public:
	int minimumAverageDifference(std::vector<int32_t> &nums)
	{
		if (nums.empty()) return -1;

		int32_t numsLen = nums.size();

		int64_t sumFirst = nums[0];
		int64_t sumLast = std::accumulate<std::vector<int32_t>::iterator, int64_t>(nums.begin() + 1, nums.end(), 0);
		int64_t diffAbs = numsLen > 1 ? abs(int64_t(sumFirst - (sumLast / (nums.size()-1)))) : sumFirst;

		uint32_t minIndex = 0;
		for (uint32_t i = 1; i < nums.size(); i++)
		{
			sumFirst += nums[i];
			sumLast  -= nums[i];

			int64_t tmp = (i == (numsLen - 1) ? sumFirst / (i+1) : abs(int((sumFirst / (i+1)) - (sumLast / (nums.size()-i-1)))));
			if (tmp < diffAbs)
			{
				diffAbs = tmp;
				minIndex = i;
			}
		}

		return minIndex;
	}
};

// @lc code=end
