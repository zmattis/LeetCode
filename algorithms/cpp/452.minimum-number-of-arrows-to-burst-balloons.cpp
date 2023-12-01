/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * There are some spherical balloons taped onto a flat wall that represents the
 * XY-plane. The balloons are represented as a 2D integer array points where
 * points[i] = [xstart, xend] denotes a balloon whose horizontal diameter
 * stretches between xstart and xend. You do not know the exact y-coordinates
 * of the balloons.
 *
 * Arrows can be shot up directly vertically (in the positive y-direction) from
 * different points along the x-axis. A balloon with xstart and xend is burst
 * by an arrow shot at x if xstart <= x <= xend. There is no limit to the
 * number of arrows that can be shot. A shot arrow keeps traveling up
 * infinitely, bursting any balloons in its path.
 *
 * Given the array points, return the minimum number of arrows that must be
 * shot to burst all balloons.
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution
{
public:
	int32_t findMinArrowShots(std::vector<std::vector<int32_t>> &points)
	{
		std::sort(points.begin(), points.end(), [](const std::vector<int32_t> &a, const std::vector<int32_t> &b) -> bool { return a[1] < b[1]; });

		int32_t count = 0, arrow = 0;
		for (size_t i = 0; i < points.size(); i++)
		{
			if (!count || points[i][0] > arrow)
			{
				count += 1;
				arrow = points[i][1];
			}
		}

		return count;
	}
};

// @lc code=end
