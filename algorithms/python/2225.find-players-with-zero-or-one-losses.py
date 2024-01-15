#
# @lc app=leetcode id=2225 lang=python3
#
# [2225] Find Players With Zero or One Losses
#
# You are given an integer array matches where matches[i] = [winneri, loseri]
# indicates that the player winneri defeated player loseri in a match.
#
# Return a list answer of size 2 where:
#
#   • answer[0] is a list of all players that have not lost any matches.
#   • answer[1] is a list of all players that have lost exactly one match.
#
# The values in the two lists should be returned in increasing order.
#
# Note:
#   • You should only consider the players that have played at least one match.
#   • The testcases will be generated such that no two matches will have the same outcome.
#
# Constraints:
#   • 1 <= matches.length <= 10^5
#   • matches[i].length == 2
#   • 1 <= winneri, loseri <= 10^5
#   • winneri != loseri
#   • All matches[i] are unique.
#

# @lc code=start

from collections import defaultdict

class Solution:
    def findWinners(self, matches: list[list[int]]) -> list[list[int]]:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        hs = set()
        hm = defaultdict(int)
        for w, l in matches:
            hs.add(w)
            hs.add(l)
            hm[l] += 1

        loss_0 = sorted([k for k in hs if k not in hm])
        loss_1 = sorted([k for k, v in hm.items() if v == 1])
        return [loss_0, loss_1]

# @lc code=end
