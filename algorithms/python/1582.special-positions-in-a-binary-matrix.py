#
# @lc app=leetcode id=1582 lang=python3
#
# [1582] Special Positions in a Binary Matrix
#
# Given an m x n binary matrix mat, return the number of special positions in
# mat.
#
# A position (i, j) is called special if mat[i][j] == 1 and all other elements
# in row i and column j are 0 (rows and columns are 0-indexed).
#
# Constraints:
#   • m == mat.length
#   • n == mat[i].length
#   • 1 <= m, n <= 100
#   • mat[i][j] is either 0 or 1.
#

# @lc code=start

from collections import defaultdict

class Solution:
    def numSpecial(self, mat: list[list[int]]) -> int:

        # Complexity:
        #   • Time: O(m*n)
        #   • Space: O(m+n)

        rows = defaultdict(int)
        cols = defaultdict(int)

        for i in range(len(mat)):
            for j in range(len(mat[i])):
                rows[i] += mat[i][j]
                cols[j] += mat[i][j]

        ret = 0
        for i in range(len(mat)):
            for j in range(len(mat[i])):
                if mat[i][j] and rows[i] == 1 and cols[j] == 1:
                    ret += 1

        return ret

# @lc code=end
