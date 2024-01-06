#
# @lc app=leetcode id=1235 lang=python3
#
# [1235] Maximum Profit in Job Scheduling
#
# We have n jobs, where every job is scheduled to be done from startTime[i] to
# endTime[i], obtaining a profit of profit[i].
#
# You're given the startTime, endTime and profit arrays, return the maximum
# profit you can take such that there are no two jobs in the subset with
# overlapping time range.
#
# If you choose a job that ends at time X you will be able to start another job
# that starts at time X.
#
# Constraints:
#   • 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
#   • 1 <= startTime[i] < endTime[i] <= 10^9
#   • 1 <= profit[i] <= 10^4
#

# @lc code=start

import bisect

class Solution:
    def jobScheduling(self, startTime: list[int], endTime: list[int], profit: list[int]) -> int:

        # Complexity:
        #   • Time: O(n*log(n))
        #   • Space: O(n)

        n = len(profit)
        jobs = sorted(zip(endTime, startTime, profit))

        dp = [0] * (n + 1)
        for i, (e, s, p) in enumerate(jobs):
            index = bisect.bisect_right(jobs, s, hi=i, key=lambda x: x[0])
            dp[i + 1] = max(dp[i], dp[index] + p)

        return dp[n]

# @lc code=end
