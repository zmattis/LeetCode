#
# @lc app=leetcode id=1688 lang=python3
#
# [1688] Count of Matches in Tournament
#
# You are given an integer n, the number of teams in a tournament that has
# strange rules:
#   • If the current number of teams is even, each team gets paired with another
#     team. A total of n / 2 matches are played, and n / 2 teams advance to the
#     next round.
#   • If the current number of teams is odd, one team randomly advances in the
#     tournament, and the rest gets paired. A total of (n - 1) / 2 matches are
#     played, and (n - 1) / 2 + 1 teams advance to the next round.
#
# Return the number of matches played in the tournament until a winner is
# decided.
#
# Constraints:
#   • 1 <= n <= 200
#

# @lc code=start

class Solution:
    def numberOfMatches(self, n: int) -> int:

        # Logic
        # return n - 1

        # Recursion
        # if n == 1:
        #     return 0
        # num_matches = n // 2
        # num_advances = num_matches + (n % 2)
        # return num_matches + self.numberOfMatches(num_advances)

        # Dynamic Programming
        dp = [0] * (n + 1)
        for i in range(2, n + 1):
            dp[i] = i//2 + dp[(i//2) + (i%2)]
        return dp[n]

# @lc code=end
