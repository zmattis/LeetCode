#
# @lc app=leetcode id=1903 lang=python3
#
# [1903] Largest Odd Number in String
#
# You are given a string num, representing a large integer. Return the
# largest-valued odd integer (as a string) that is a non-empty substring of
# num, or an empty string "" if no odd integer exists.
#
# A substring is a contiguous sequence of characters within a string.
#
# Constraints:
#   • 1 <= num.length <= 10^5
#   • num only consists of digits and does not contain any leading zeros.
#

# @lc code=start

class Solution:
    def largestOddNumber(self, num: str) -> str:

        for i, digit in enumerate(num[::-1]):
            if int(digit) % 2:
                return num[:len(num)-i]

        return ""

# @lc code=end
