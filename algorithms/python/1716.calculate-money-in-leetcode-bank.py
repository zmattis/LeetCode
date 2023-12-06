#
# @lc app=leetcode id=1716 lang=python3
#
# [1716] Calculate Money in Leetcode Bank
#
# Hercy wants to save money for his first car. He puts money in the Leetcode
# bank every day.
#
# He starts by putting in $1 on Monday, the first day. Every day from Tuesday
# to Sunday, he will put in $1 more than the day before. On every subsequent
# Monday, he will put in $1 more than the previous Monday.
#
# Given n, return the total amount of money he will have in the Leetcode bank
# at the end of the n^th day.
#
# Constraints:
#   • 1 <= n <= 1000
#

# @lc code=start

class Solution:
    def totalMoney(self, n: int) -> int:
        dp = [((i % 7) + 1) + (i // 7) for i in range(n)]
        return sum(dp)

# @lc code=end
