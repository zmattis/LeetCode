#
# @lc app=leetcode id=1637 lang=python3
#
# [1637] Widest Vertical Area Between Two Points Containing No Points
#
# Given n points on a 2D plane where points[i] = [xi, yi], Return the widest
# vertical area between two points such that no points are inside the area.
#
# A vertical area is an area of fixed-width extending infinitely along the
# y-axis (i.e., infinite height). The widest vertical area is the one with the
# maximum width.
#
# Note that points on the edge of a vertical area are not considered included
# in the area.
#
# Constraints:
#   • n == points.length
#   • 2 <= n <= 10^5
#   • points[i].length == 2
#   • 0 <= xi, yi <= 10^9
#

# @lc code=start

class Solution:
    def maxWidthOfVerticalArea(self, points: list[list[int]]) -> int:

        # Complexity:
        #   • Time: O(n*log(n))
        #   • Space: O(1)

        ret = 0

        points.sort(key=lambda pt: pt[0])
        for i in range(len(points) - 1):
            delta = points[i+1][0] - points[i][0]
            if delta > ret:
                ret = delta

        return ret

# @lc code=end
