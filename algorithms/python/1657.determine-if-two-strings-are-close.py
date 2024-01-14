#
# @lc app=leetcode id=1657 lang=python3
#
# [1657] Determine if Two Strings Are Close
#
# Two strings are considered close if you can attain one from the other using
# the following operations:
#
# • Operation 1: Swap any two existing characters: abcde -> aecdb
# • Operation 2: Transform every occurrence of one existing character into
#   another existing character, and do the same with the other
#   character: aacabb -> bbcbaa
#
# You can use the operations on either string as many times as necessary.
#
# Given two strings, word1 and word2, return true if word1 and word2 are close,
# and false otherwise.
#
# Constraints:
#   • 1 <= word1.length, word2.length <= 10^5
#   • word1 and word2 contain only lowercase English letters.
#

# @lc code=start

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(n)

        s1, s2 = set(), set()
        hm1, hm2 = [0] * 26, [0] * 26
        for c1 in word1:
            s1.add(c1)
            hm1[ord(c1) - ord('a')] += 1
        for c2 in word2:
            s2.add(c2)
            hm2[ord(c2) - ord('a')] += 1

        return s1 == s2 and sorted(hm1) == sorted(hm2)

# @lc code=end
