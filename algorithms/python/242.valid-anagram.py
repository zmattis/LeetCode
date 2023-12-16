#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#
# Given two strings s and t, return true if t is an anagram of s, and false
# otherwise.
#
# An Anagram is a word or phrase formed by rearranging the letters of a
# different word or phrase, typically using all the original letters exactly
# once.
#
# Constraints:
#   • 1 <= s.length, t.length <= 5 * 10^4
#   • s and t consist of lowercase English letters.
#

# @lc code=start

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        # Complexity:
        #   • Time: O(n*log(n))
        #   • Space: O(n)

        return sorted(s) == sorted(t)

# @lc code=end
