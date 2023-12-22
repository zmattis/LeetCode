#
# @lc app=leetcode id=1422 lang=python3
#
# [1422] Maximum Score After Splitting a String
#
# Given a string s of zeros and ones, return the maximum score after splitting
# the string into two non-empty substrings (i.e. left substring and right
# substring).
#
# The score after splitting a string is the number of zeros in the left
# substring plus the number of ones in the right substring.
#
# Constraints:
#   • 2 <= s.length <= 500
#   • The string s consists of characters '0' and '1' only.
#

# @lc code=start

class Solution:
    def maxScore(self, s: str) -> int:

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(1)

        ret = 0
        for n in range(1, len(s)):
            left = s[:n]
            right = s[n:]
            sum = left.count("0") + right.count("1")
            if sum > ret:
                ret = sum

        return ret

# @lc code=end
