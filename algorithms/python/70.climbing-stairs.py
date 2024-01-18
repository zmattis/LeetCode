#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#
# You are climbing a staircase. It takes n steps to reach the top.
#
# Each time you can either climb 1 or 2 steps. In how many distinct ways can
# you climb to the top?
#
# Constraints:
#   • 1 <= n <= 45
#

# @lc code=start

class Solution:
    def climbStairs(self, n: int) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        dp = [0] * max(n, 2)
        dp[0] = 1
        dp[1] = 2

        for i in range(2, n):
            dp[i] = dp[i-1] + dp[i-2]

        return dp[n-1]

# @lc code=end
