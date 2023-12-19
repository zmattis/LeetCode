#
# @lc app=leetcode id=2363 lang=python3
#
# [2363] Merge Similar Items
#
# You are given two 2D integer arrays, items1 and items2, representing two sets
# of items. Each array items has the following properties:
#
#   • items[i] = [value_i, weight_i] where value_i represents the value and weight_i
#     represents the weight of the i^th item.
#   • The value of each item in items is unique.
#
# Return a 2D integer array ret where ret[i] = [value_i, weight_i], with weight_i
# being the sum of weights of all items with value value_i.
#
# Note: ret should be returned in ascending order by value.
#
# Constraints:
#   • 1 <= items1.length, items2.length <= 1000
#   • items1[i].length == items2[i].length == 2
#   • 1 <= value_i, weight_i <= 1000
#   • Each value_i in items1 is unique.
#   • Each value_i in items2 is unique.
#

# @lc code=start

from collections import defaultdict

class Solution:
    def mergeSimilarItems(self, items1: list[list[int]], items2: list[list[int]]) -> list[list[int]]:

        # Complexity:
        #   • Time: O(n*log(n))
        #   • Space: O(n)

        ret = defaultdict(int)
        for items in (items1, items2):
            for value, weight in items:
                ret[value] += weight

        return sorted(list(map(list, ret.items())))

# @lc code=end

sol = Solution()
ret = sol.mergeSimilarItems([[1,1],[4,5],[3,8]], [[3,1],[1,5]])
print(ret)

