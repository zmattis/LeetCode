#
# @lc app=leetcode id=455 lang=python3
#
# [455] Assign Cookies
#
# Assume you are an awesome parent and want to give your children some cookies.
# But, you should give each child at most one cookie.
#
# Each child i has a greed factor g[i], which is the minimum size of a cookie
# that the child will be content with; and each cookie j has a size s[j]. If
# s[j] >= g[i], we can assign the cookie j to the child i, and the child i will
# be content. Your goal is to maximize the number of your content children and
# output the maximum number.
#
# Constraints:
#   • 1 <= g.length <= 3 * 10^4
#   • 0 <= s.length <= 3 * 10^4
#   • 1 <= g[i], s[j] <= 2^31 - 1
#

# @lc code=start

class Solution:
    def findContentChildren(self, g: list[int], s: list[int]) -> int:

        # Complexity:
        #   • Time: O(n*log(n))
        #   • Space: O(1)

        g.sort()
        s.sort()

        cnt = 0

        ptr = 0
        for greed in g:

            for idx in range(ptr, len(s)):

                ptr += 1
                if s[idx] >= greed:
                    cnt += 1
                    break

        return cnt

# @lc code=end
