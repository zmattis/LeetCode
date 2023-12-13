/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 *
 * Constraints:
 *   • 1 <= intervals.length <= 10^5
 *   • intervals[i].length == 2
 *   • -5 * 10^4 <= starti < endi <= 5 * 10^4
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
 public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {

    // Complexity:
    //   • Time: O(n*log(n))
    //   • Space: O(1)

    int ret = -1;

    auto fn_vcomp = [](const std::vector<int> &a, const std::vector<int> &b) { return a[1] < b[1]; };
    std::sort(intervals.begin(), intervals.end(), fn_vcomp);

    int iprev = intervals[0][1];
    for (const std::vector<int>& icurr: intervals)
    {
        if (iprev > icurr[0])
        {
            ret += 1;
            continue;
        }

        iprev = icurr[1];
    }

    return ret;
  }
};

// @lc code=end
