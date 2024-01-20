#
# @lc app=leetcode id=907 lang=python3
#
# [907] Sum of Subarray Minimums
#
# Given an array of integers arr, find the sum of min(b), where b ranges over
# every (contiguous) subarray of arr. Since the answer may be large, return the
# answer modulo 10^9 + 7.
#
# Constraints:
#   • 1 <= arr.length <= 3 * 10^4
#   • 1 <= arr[i] <= 3 * 10^4
#

# @lc code=start

class Solution:
    def sumSubarrayMins(self, arr: list[int]) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        n = len(arr)
        dp = [0] * n
        s = []

        ret = 0
        for i in range(n):

            while len(s) > 0 and arr[i] <= arr[s[-1]]:
                s.pop()

            if len(s) > 0:
                j = s[-1]
                dp[i] = dp[j] + arr[i] * (i - j)
            else:
                dp[i] = arr[i] * (i + 1)

            s.append(i)
            ret += dp[i]

        return ret % (10**9 + 7)

# @lc code=end
