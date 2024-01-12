#
# @lc app=leetcode id=1704 lang=python3
#
# [1704] Determine if String Halves Are Alike
#
# You are given a string s of even length. Split this string into two halves of
# equal lengths, and let a be the first half and b be the second half.
#
# Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
# 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
# lowercase letters.
#
# Return true if a and b are alike. Otherwise, return false.
#
# Constraints:
#   • 2 <= s.length <= 1000
#   • s.length is even.
#   • s consists of uppercase and lowercase letters.
#

# @lc code=start

class Solution:
    def halvesAreAlike(self, s: str) -> bool:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(1)

        cnt = 0
        for i, char in enumerate(s):
            if char.lower() in ('a', 'e', 'i', 'o', 'u'):
                cnt = cnt+1 if i < len(s) / 2 else cnt-1

        return cnt == 0

# @lc code=end
