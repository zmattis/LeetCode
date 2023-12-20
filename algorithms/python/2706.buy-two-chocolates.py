#
# @lc app=leetcode id=2706 lang=python3
#
# [2706] Buy Two Chocolates
#
# You are given an integer array prices representing the prices of various
# chocolates in a store. You are also given a single integer money, which
# represents your initial amount of money.
#
# You must buy exactly two chocolates in such a way that you still have some
# non-negative leftover money. You would like to minimize the sum of the prices
# of the two chocolates you buy.
#
# Return the amount of money you will have leftover after buying the two
# chocolates. If there is no way for you to buy two chocolates without ending
# up in debt, return money. Note that the leftover must be non-negative.
#
# Constraints:
#   • 2 <= prices.length <= 50
#   • 1 <= prices[i] <= 100
#   • 1 <= money <= 100
#

# @lc code=start

class Solution:
    def buyChoco(self, prices: list[int], money: int) -> int:

        # Complexity:
        #   • Time: O(n*log(n))
        #   • Space: O(1)

        prices.sort()
        sum = prices[0] + prices[1]
        diff = money - sum

        if diff < 0:
            return money

        return diff

# @lc code=end
