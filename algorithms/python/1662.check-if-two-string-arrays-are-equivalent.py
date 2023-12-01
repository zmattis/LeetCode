#
# @lc app=leetcode id=1662 lang=python3
#
# [1662] Check If Two String Arrays are Equivalent
#
# Given two string arrays word1 and word2, return true if the two arrays
# represent the same string, and false otherwise.
#
# A string is represented by an array if the array elements concatenated in
# order forms the string.
#
# Constraints:
#   • 1 <= word1.length, word2.length <= 103
#   • 1 <= word1[i].length, word2[i].length <= 103
#   • 1 <= sum(word1[i].length), sum(word2[i].length) <= 103
#   • word1[i] and word2[i] consist of lowercase letters.
#

# @lc code=start

class Solution:
    def arrayStringsAreEqual(self, word1: list[str], word2: list[str]) -> bool:
        str1, str2 = "".join(word1), "".join(word2)
        return str1 == str2

# @lc code=end
