#
# @lc app=leetcode id=1347 lang=python3
#
# [1347] Minimum Number of Steps to Make Two Strings Anagram
#
# You are given two strings of the same length s and t. In one step you can
# choose any character of t and replace it with another character.
#
# Return the minimum number of steps to make t an anagram of s.
#
# An Anagram of a string is a string that contains the same characters with a
# different (or the same) ordering.
#
# Constraints:
#   • 1 <= s.length <= 5 * 10^4
#   • s.length == t.length
#   • s and t consist of lowercase English letters only.
#

# @lc code=start

class Solution:
    def minSteps(self, s: str, t: str) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(1)

        n = len(s)
        hm = [0] * 26

        for i in range(n):
            hm[ord(s[i]) - ord('a')] += 1
            hm[ord(t[i]) - ord('a')] -= 1

        return sum([x for x in hm if x > 0])

# @lc code=end
