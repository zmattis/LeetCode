#
# @lc app=leetcode id=931 lang=python3
#
# [931] Minimum Falling Path Sum
#
# Given an n x n array of integers matrix, return the minimum sum of any
# falling path through matrix.
#
# A falling path starts at any element in the first row and chooses the element
# in the next row that is either directly below or diagonally left/right.
# Specifically, the next element from position (row, col) will be (row + 1, col
# - 1), (row + 1, col), or (row + 1, col + 1).
#
# Constraints:
# • n == matrix.length == matrix[i].length
# • 1 <= n <= 100
# • -100 <= matrix[i][j] <= 100
#

# @lc code=start

class Solution:
    def minFallingPathSum(self, matrix: list[list[int]]) -> int:

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(n^2)

        n = len(matrix)
        dp = [[0] * n for _ in range(n)]
        dp[0] = matrix[0]

        for i in range(1, n):
            for j in range(n):
                dp[i][j] = min(dp[i-1][max(j-1, 0)], dp[i-1][j], dp[i-1][min(n-1, j+1)]) + matrix[i][j]

        return min(dp[-1])

# @lc code=end
