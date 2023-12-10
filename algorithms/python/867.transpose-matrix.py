#
# @lc app=leetcode id=867 lang=python3
#
# [867] Transpose Matrix
#
# Given a 2D integer array matrix, return the transpose of matrix.
#
# The transpose of a matrix is the matrix flipped over its main diagonal,
# switching the matrix's row and column indices.
#
# Constraints:
#   • m == matrix.length
#   • n == matrix[i].length
#   • 1 <= m, n <= 1000
#   • 1 <= m * n <= 10^5
#   • -10^9 <= matrix[i][j] <= 10^9
#

# @lc code=start

class Solution:
    def transpose(self, matrix: list[list[int]]) -> list[list[int]]:
        return list(map(list, zip(*matrix)))

# @lc code=end
