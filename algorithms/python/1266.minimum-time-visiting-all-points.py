#
# @lc app=leetcode id=1266 lang=python3
#
# [1266] Minimum Time Visiting All Points
#
# On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi].
# Return the minimum time in seconds to visit all the points in the order given by points.
#
# You can move according to these rules:
#   • In 1 second, you can either:
#     • move vertically by one unit.
#     • move horizontally by one unit.
#     • move diagonally sqrt(2) units (1x horizontal & 1x vertical).
#   • You have to visit the points in the same order as they appear in the array.
#   • You are allowed to pass through points that appear later in the order, but these do not count as visits.
#
# Constraints:
#   • points.length == n
#   • 1 <= n <= 100
#   • points[i].length == 2
#   • -1000 <= points[i][0], points[i][1] <= 1000
#

# @lc code=start

class Solution:
    def minTimeToVisitAllPoints(self, points: list[list[int]]) -> int:

        distance = 0

        loc = points[0]
        for pt in points[1:]:

            # dx, dy = abs(pt[0]- loc[0]), abs(pt[1] - loc[1])
            # ddiag = min(dx, dy)
            # dperp = max(dx - ddiag, dy - ddiag)
            # distance += ddiag + dperp

            # Chebyshev Distance
            dx, dy = abs(pt[0]- loc[0]), abs(pt[1] - loc[1])
            distance += max(dx, dy)

            loc = pt

        return distance

# @lc code=end
