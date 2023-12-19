#
# @lc app=leetcode id=661 lang=python3
#
# [661] Image Smoother
#
# An image smoother is a filter of the size 3 x 3 that can be applied to each
# cell of an image by rounding down the average of the cell and the eight
# surrounding cells (i.e., the average of the nine cells in the blue smoother).
# If one or more of the surrounding cells of a cell is not present, we do not
# consider it in the average (i.e., the average of the four cells in the red
# smoother).
#
# Given an m x n integer matrix img representing the grayscale of an image,
# return the image after applying the smoother on each cell of it.
#
# Constraints:
#   • m == img.length
#   • n == img[i].length
#   • 1 <= m, n <= 200
#   • 0 <= img[i][j] <= 255
#

# @lc code=start

class Solution:
    def imageSmoother(self, img: list[list[int]]) -> list[list[int]]:

        # Complexity:
        #   • Time: O(m*n)
        #   • Space: O(m*n)

        m, n = len(img), len(img[-1])
        ret = [[0] * n for _ in range(m)]

        for m in range(len(img)):
            for n in range(len(img[m])):

                sum = 0
                cnt = 0

                for i in (m-1, m, m+1):
                    for j in (n-1, n, n+1):
                        if i < 0 or i >= len(img) or j < 0 or j >= len(img[i]):
                            continue
                        sum += img[i][j]
                        cnt += 1

                ret[m][n] = sum // cnt

        return ret

# @lc code=end
