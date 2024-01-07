#
# @lc app=leetcode id=446 lang=python3
#
# [446] Arithmetic Slices II - Subsequence
#
# Given an integer array nums, return the number of all the arithmetic
# subsequences of nums.
#
# A sequence of numbers is called arithmetic if it consists of at least three
# elements and if the difference between any two consecutive elements is the
# same.
#
#   • For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9]
#     are arithmetic sequences.
#   • For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
#
# A subsequence of an array is a sequence that can be formed by removing some
# elements (possibly none) of the array.
#
#   • For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
#
# The test cases are generated so that the answer fits in 32-bit integer.
#
# Constraints:
#   • 1  <= nums.length <= 1000
#   • -2^31 <= nums[i] <= 2^31 - 1
#

# @lc code=start

from collections import defaultdict

class Solution:
    def numberOfArithmeticSlices(self, nums: list[int]) -> int:

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(n^2)

        count = 0

        n = len(nums)
        dp = [defaultdict(int) for _ in range(n)]
        for i in range(1, n):
            for j in range(i):
                delta = nums[i] - nums[j]
                dp[i][delta] += 1
                if delta in dp[j]:
                    dp[i][delta] += dp[j][delta]
                    count += dp[j][delta]

        return count

# @lc code=end
