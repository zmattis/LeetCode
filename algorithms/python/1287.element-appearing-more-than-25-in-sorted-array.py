#
# @lc app=leetcode id=1287 lang=python3
#
# [1287] Element Appearing More Than 25% In Sorted Array
#
# Given an integer array sorted in non-decreasing order, there is exactly one
# integer in the array that occurs more than 25% of the time, return that
# integer.
#
# Constraints:
#   • 1 <= arr.length <= 10^4
#   • 0 <= arr[i] <= 10^5
#

# @lc code=start

class Solution:
    def findSpecialInteger(self, arr: list[int]) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(1)

        max_val = -1
        max_cnt = 0

        curr_cnt = 0
        curr_val = -1

        for x in arr + [-1]:

            if x != curr_val:

                if curr_cnt > max_cnt:
                    max_val = curr_val
                    max_cnt = curr_cnt

                curr_val = x
                curr_cnt = 1
                continue

            curr_cnt += 1

        return max_val

# @lc code=end
