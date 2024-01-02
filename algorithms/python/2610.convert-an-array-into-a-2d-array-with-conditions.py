#
# @lc app=leetcode id=2610 lang=python3
#
# [2610] Convert an Array Into a 2D Array With Conditions
#
# You are given an integer array nums. You need to create a 2D array from nums
# satisfying the following conditions:
#
#   • The 2D array should contain only the elements of the array nums.
#   • Each row in the 2D array contains distinct integers.
#   • The number of rows in the 2D array should be minimal.
#
# Return the resulting array. If there are multiple answers, return any of them.
#
# Note that the 2D array can have a different number of elements on each row.
#
# Constraints:
#   • 1 <= nums.length <= 200
#   • 1 <= nums[i] <= nums.length
#

# @lc code=start

# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:

#         # Complexity:
#         #   • Time: O(n*log(n))
#         #   • Space: O(n)

#         return sorted(s) == sorted(t)

from collections import Counter

class Solution:
    def findMatrix(self, nums: list[int]) -> list[list[int]]:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        hm = Counter(nums)
        max_val, max_cnt = hm.most_common(n=1)[-1]

        ret = [[] for _ in range(max_cnt)]
        for k, v in hm.items():
            for i in range(v):
                ret[i].append(k)

        return ret

# @lc code=end
