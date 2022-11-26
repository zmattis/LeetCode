/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to
 * endTime[i], obtaining a profit of profit[i].
 *
 * You're given the startTime, endTime and profit arrays, return the maximum
 * profit you can take such that there are no two jobs in the subset with
 * overlapping time range.
 *
 * If you choose a job that ends at time X you will be able to start another
 * job that starts at time X.
 */

// @lc code=start

#include <vector>
#include <map>
#include <algorithm>

class Solution
{
public:
	int32_t jobScheduling(const std::vector<int32_t> &startTime, const std::vector<int32_t> &endTime, const std::vector<int32_t> &profit)
	{
		int32_t n = profit.size();

		std::vector<std::vector<int32_t>> jobs;
		for (uint32_t i = 0; i < n; i++)
		{
			jobs.push_back({endTime[i], startTime[i], profit[i]});
		}

		std::sort(jobs.begin(), jobs.end());

		std::map<int32_t, int32_t> dp = {{0, 0}};
		for (auto& job : jobs)
		{
			int32_t cur = std::prev(dp.upper_bound(job[1]))->second + job[2];
			if (cur > dp.rbegin()->second)
			{
				dp[job[0]] = cur;
			}
		}

		return dp.rbegin()->second;
	}
};

// @lc code=end
