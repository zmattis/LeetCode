/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * Given an array of integers temperatures representing the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 */

// @lc code=start

#include <vector>
#include <stack>

class Solution
{
public:
	std::vector<int> dailyTemperatures(const std::vector<int> &temperatures)
	{
		std::vector<int> ans(temperatures.size());

		std::stack<int> s;
		for(int cur = 0; cur < temperatures.size(); cur++)
		{
			while(s.size() && temperatures[cur] > temperatures[s.top()])
			{
				ans[s.top()] = cur - s.top();
				s.pop();
			}

			s.push(cur);
		}

		return ans;
	}
};

// @lc code=end
