#
# @lc app=leetcode id=2264 lang=python3
#
# [2264] Largest 3-Same-Digit Number in String
#
# You are given a string num representing a large integer. An integer is good
# if it meets the following conditions:
#
#   • It is a substring of num with length 3.
#   • It consists of only one unique digit.
#
# Return the maximum good integer as a string or an empty string "" if no such
# integer exists.
#
# Note:
#   • A substring is a contiguous sequence of characters within a string..
#   • There may be leading zeroes in num or a good integer.
#
# Constraints:
#   • 3 <= num.length <= 1000
#   • num only consists of digits.
#

# @lc code=start

class Solution:
    def largestGoodInteger(self, num: str) -> str:
        for digit in [str(x) * 3 for x in reversed(range(10))]:
            if digit in num:
                return digit
        return ""

# @lc code=end
