/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 *
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 */

// @lc code=start

#include <stdint.h>
#include <vector>

class Solution
{
public:
	int32_t numSquares(int32_t n)
	{
		std::vector<int32_t> dp(n+1,INT32_MAX);
		dp[0]=0;

		int32_t count = 1;
		while(count*count <= n)
		{
			int32_t sq = count*count;
			for(int32_t i = sq; i <= n; i++)
			{
				dp[i] = std::min(dp[i-sq] + 1,dp[i]);
			}

			count++;
		}

		return dp[n];
	}
};

// @lc code=end
