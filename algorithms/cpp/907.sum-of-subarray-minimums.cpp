/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over
 * every (contiguous) subarray of arr. Since the answer may be large, return
 * the answer modulo 10^9 + 7.
 */

// @lc code=start

#include <vector>
#include <stack>

class Solution
{
public:
	int sumSubarrayMins(const std::vector<int> &arr)
	{
		int MOD = 1000000007;

		std::stack<int32_t> stack;
		int64_t sumOfMinimums = 0;

		for (int32_t i = 0; i <= arr.size(); i++)
		{
			while (!stack.empty() && (i == arr.size() || arr[stack.top()] >= arr[i]))
			{
				int32_t mid = stack.top(); stack.pop();
				int32_t leftBoundary = stack.empty() ? -1 : stack.top();
				int32_t rightBoundary = i;

				int64_t count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;

				sumOfMinimums += (count * arr[mid]) % MOD;
				sumOfMinimums %= MOD;
			}

			stack.push(i);
		}

		return (int32_t)sumOfMinimums;
	}
};

// @lc code=end
