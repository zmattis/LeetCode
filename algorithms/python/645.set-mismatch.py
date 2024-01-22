#
# @lc app=leetcode id=645 lang=python3
#
# [645] Set Mismatch
#
# You have a set of integers s, which originally contains all the numbers from
# 1 to n. Unfortunately, due to some error, one of the numbers in s got
# duplicated to another number in the set, which results in repetition of one
# number and loss of another number.
#
# You are given an integer array nums representing the data status of this set
# after the error.
#
# Find the number that occurs twice and the number that is missing and return
# them in the form of an array.
#
# Constraints:
#   • 2 <= nums.length <= 10^4
#   • 1 <= nums[i] <= 10^4
#

# @lc code=start

from collections import Counter

class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        duplicate = 0
        missing = 0

        count = Counter(nums)
        for i in range(1, len(nums)+1):
            if i not in count:
                missing = i
            elif count[i] != 1:
                duplicate = i

        return [duplicate, missing]

# @lc code=end
