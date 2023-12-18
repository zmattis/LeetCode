#
# @lc app=leetcode id=1913 lang=python3
#
# [1913] Maximum Product Difference Between Two Pairs
#
# The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).
#
# For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
#
# Given an integer array nums, choose four distinct indices w, x, y, and z such
# that the product difference between pairs (nums[w], nums[x]) and (nums[y],
# nums[z]) is maximized.
#
# Return the maximum such product difference.
#
# Constraints:
#   • 4 <= nums.length <= 10^4
#   • 1 <= nums[i] <= 10^4
#

# @lc code=start

import math

class Solution:
    def maxProductDifference(self, nums: list[int]) -> int:

        big1, big2 = 0, 0
        small1, small2 = math.inf, math.inf

        for x in nums:

            if x > big1:
                big2 = big1
                big1 = x
            elif x > big2:
                big2 = x

            if x < small1:
                small2 = small1
                small1 = x
            elif x < small2:
                small2 = x

        return (big1 * big2) - (small1 * small2)

# @lc code=end
