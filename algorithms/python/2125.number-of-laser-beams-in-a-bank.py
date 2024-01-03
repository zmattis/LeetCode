#
# @lc app=leetcode id=2125 lang=python3
#
# [2125] Number of Laser Beams in a Bank
#
# Anti-theft security devices are activated inside a bank. You are given a
# 0-indexed binary string array bank representing the floor plan of the bank,
# which is an m x n 2D matrix. bank[i] represents the i^th row, consisting of
# '0's and '1's. '0' means the cell is empty, while'1' means the cell has a
# security device.
#
# There is one laser beam between any two security devices if both conditions
# are met:
#
#   • The two devices are located on two different rows: r1 and r2, where r1 < r2.
#   • For each row i where r1 < i < r2, there are no security devices in the i^th row.
#
# Laser beams are independent, i.e., one beam does not interfere nor join with
# another.
#
# Return the total number of laser beams in the bank.
#
# Constraints:
#   • m == bank.length
#   • n == bank[i].length
#   • 1 <= m, n <= 500
#   • bank[i][j] is either '0' or '1'.
#

# @lc code=start

class Solution:
    def numberOfBeams(self, bank: list[str]) -> int:

        # Complexity:
        #   • Time: O(m*n)
        #   • Space: O(m)

        ret = 0
        count = [ int(row, base=2).bit_count() for row in bank ]

        prev, curr = 0, 1
        while curr < len(count):

            ret += count[prev] * count[curr]

            if count[curr]:
                prev = curr

            curr += 1

        return ret

# @lc code=end
