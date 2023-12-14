#
# @lc app=leetcode id=2482 lang=python3
#
# [2482] Difference Between Ones and Zeros in Row and Column
#
# You are given a 0-indexed m x n binary matrix grid.
#
# A 0-indexed m x n difference matrix diff is created with the following
# procedure:
#
#   • Let the number of ones in the i^th row be onesRow_i.
#   • Let the number of ones in the j^th column be onesCol_j.
#   • Let the number of zeros in the i^th row be zerosRow_i.
#   • Let the number of zeros in the j^th column be zerosCol_j.
#   • diff[i][j] = onesRow_i + onesCol_j - zerosRow_i - zerosCol_j
#
# Return the difference matrix diff.
#
# Constraints:
#   • m == grid.length
#   • n == grid[i].length
#   • 1 <= m, n <= 10^5
#   • 1 <= m * n <= 10^5
#   • grid[i][j] is either 0 or 1.
#

# @lc code=start

class Solution:
    def onesMinusZeros(self, grid: list[list[int]]) -> list[list[int]]:

        # Complexity:
        #   • Time: O(m*n)
        #   • Space: O(m+n)

        m = len(grid)
        n = len(grid[-1])

        rows = [0] * m
        cols = [0] * n

        for i in range(m):
            for j in range(n):
                rows[i] += grid[i][j]
                cols[j] += grid[i][j]

        for i in range(m):
            for j in range(n):
                grid[i][j] = 2*rows[i] + 2*cols[j] - m - n

        return grid

# @lc code=end
