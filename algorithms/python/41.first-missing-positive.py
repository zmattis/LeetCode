#
# @lc app=leetcode id=41 lang=python3
#
# [41] First Missing Positive
#
# Given an unsorted integer array nums, return the smallest missing positive
# integer.
#
# You must implement an algorithm that runs in O(n) time and uses O(1)
# auxiliary space.
#
# Constraints:
#   • 1 <= nums.length <= 10^5
#   • -2^31 <= nums[i] <= 2^31 - 1
#

# @lc code=start

class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:

        # Complexity:
        #   • Time: O(nlogn)
        #   • Space: O(1)

        # ret = 1
        # for n in sorted(nums):
        #     if n <= 0:
        #         continue
        #     if n != ret:
        #         break
        #     ret += 1
        # return ret

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(1)

        nums.append(0)
        n = len(nums)

        for i,x in enumerate(nums):
            if x < 0 or x >= n:
                nums[i] = 0

        for x in nums:
            nums[x % n] += n

        for i in range(1, len(nums)):
            if nums[i] < n:
                return i

        return n

# @lc code=end
