#
# @lc app=leetcode id=376 lang=python3
#
# [376] Wiggle Subsequence
#
# A wiggle sequence is a sequence where the differences between successive
# numbers strictly alternate between positive and negative. The first
# difference (if one exists) may be either positive or negative. A sequence
# with one element and a sequence with two non-equal elements are trivially
# wiggle sequences.
#
#   • For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences
#     (6, -3, 5, -7, 3) alternate between positive and negative.
#   • In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences.
#     The first is not because its first two differences are positive, and the
#     second is not because its last difference is zero.
#
# A subsequence is obtained by deleting some elements (possibly zero) from the
# original sequence, leaving the remaining elements in their original order.
#
# Given an integer array nums, return the length of the longest wiggle
# subsequence of nums.
#
# Constraints:
# • 1 <= nums.length <= 1000
# • 0 <= nums[i] <= 1000
#

# @lc code=start

class Solution:
    def wiggleMaxLength(self, nums: list[int]) -> int:

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(n)

        n = len(nums)
        l = [1] * n
        g = [1] * n

        for i in range(n):
            for j in range(i+1):

                if nums[i] < nums[j]:
                    l[i] = max(g[j] + 1, l[i])

                if nums[i] > nums[j]:
                    g[i] = max(l[j] + 1, g[i])

        return max(max(l), max(g))

# @lc code=end
