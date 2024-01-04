#
# @lc app=leetcode id=2870 lang=python3
#
# [2870] Minimum Number of Operations to Make Array Empty
#
# You are given a 0-indexed array nums consisting of positive integers.
#
# There are two types of operations that you can apply on the array any number
# of times:
#
#   • Choose two elements with equal values and delete them from the array.
#   • Choose three elements with equal values and delete them from the array.
#
# Return the minimum number of operations required to make the array empty, or
# -1 if it is not possible.
#
# Constraints:
#   • 2 <= nums.length <= 105
#   • 1 <= nums[i] <= 106
#

# @lc code=start

from collections import Counter
import math

class Solution:
    def minOperations(self, nums: list[int]) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        ret = 0
        count = Counter(nums)
        for n in count.values():
            if n == 1:
                return -1
            ret += math.ceil(n / 3)

        return ret

# @lc code=end
