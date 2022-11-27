/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 *
 * Given an integer array nums, return the number of all the arithmetic
 * subsequences of nums.
 *
 * A sequence of numbers is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the same.
 *     For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
 *     For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
 *
 * A subsequence of an array is a sequence that can be formed by removing some
 * elements (possibly none) of the array.
 *     For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
 *
 * The test cases are generated so that the answer fits in 32-bit integer.
 */

// @lc code=start

#include <stdint.h>
#include <vector>
#include <map>

class Solution
{
public:
	int32_t numberOfArithmeticSlices(std::vector<int32_t> &nums)
	{
		int64_t count = 0;

		int32_t n = nums.size();
		std::vector<std::map<int64_t, int32_t>> dp(n);
		for (uint32_t i = 1; i < n; i++)
		{
			for (uint32_t j = 0; j < i; j++)
			{
				int64_t delta = (int64_t)nums[i] - (int64_t)nums[j];

				int32_t sum = 0;
				if (dp[j].find(delta) != dp[j].end())
				{
					sum = dp[j][delta];
				}

				dp[i][delta] += sum + 1;
				count += sum;
			}
		}

		return (int32_t)count;
	}
};

// @lc code=end
