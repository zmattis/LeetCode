#
# @lc app=leetcode id=1464 lang=python3
#
# [1464] Maximum Product of Two Elements in an Array
#
# Given the array of integers nums, you will choose two different indices i and
# j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
#
# Constraints:
#   • 2 <= nums.length <= 500
#   • 1 <= nums[i] <= 10^3
#

# @lc code=start

class Solution:
    def maxProduct(self, nums: list[int]) -> int:

        #
        # Approach: Brute Force
        #

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(1)

        # val = -1
        # for i in range(len(nums)- 1):
        #     for j in range(i+1, len(nums)):
        #         prod = (nums[i]-1) * (nums[j]-1)
        #         if prod > val:
        #             val = prod
        # return val

        #
        # Approach: Sorting
        #

        # Complexity:
        #   • Time: O(n*log(n))
        #   • Space: O(1)

        # nums.sort()
        # val = (nums[-1]-1) * (nums[-2]-1)
        # return val

        #
        # Approach: Tracking
        #

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(1)

        big1 = 0
        big2 = 0
        for x in nums:
            if x > big1:
                big2 = big1
                big1 = x
            elif x > big2:
                big2 = x
        return (big1-1) * (big2-1)

# @lc code=end
