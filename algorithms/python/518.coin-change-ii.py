#
# @lc app=leetcode id=518 lang=python3
#
# [518] Coin Change II
#
#
# You are given an integer array coins representing coins of different
# denominations and an integer amount representing a total amount of money.
#
# Return the number of combinations that make up that amount. If that amount of
# money cannot be made up by any combination of the coins, return 0.
#
# You may assume that you have an infinite number of each kind of coin.
#
# The answer is guaranteed to fit into a signed 32-bit integer.
#
# Constraints:
#   • 1 <= coins.length <= 300
#   • 1 <= coins[i] <= 5000
#   • All the values of coins are unique.
#   • 0 <= amount <= 5000
#

# @lc code=start

class Solution:
    def change(self, amount: int, coins: list[int]) -> int:


        # Complexity:
        #   • Time: O(n*B)
        #   • Space: O(B)

        n = amount + 1
        dp = [0] * n
        dp[0] = 1

        for c in coins:
            for i in range(1, n):
                if i - c >= 0:
                    dp[i] += dp[i-c]

        return dp[amount]

# @lc code=end
