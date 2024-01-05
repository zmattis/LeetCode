#
# @lc app=leetcode id=300 lang=python3
#
# [300] Longest Increasing Subsequence
#
# Given an integer array nums, return the length of the longest strictly
# increasing subsequence.
#
# Constraints:
#   • 1 <= nums.length <= 2500
#   • -10^4 <= nums[i] <= 10^4
#

# @lc code=start

class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(n)

        n = len(nums)
        dp = [1] * n

        for i in range(1, len(nums)):
            for j in range(0, i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[j] + 1, dp[i])

        return max(dp)

# @lc code=end
