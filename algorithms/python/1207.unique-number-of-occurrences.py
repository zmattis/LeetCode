#
# @lc app=leetcode id=1207 lang=python3
#
# [1207] Unique Number of Occurrences
#
# Given an array of integers arr, return true if the number of occurrences of
# each value in the array is unique or false otherwise.
#
# Constraints:
# • 1 <= arr.length <= 1000
# • -1000 <= arr[i] <= 1000
#

# @lc code=start

from collections import Counter

class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        ht = set()

        count = Counter(arr)
        for c in count.values():

            if c in ht:
                return False

            ht.add(c)

        return True

# @lc code=end

