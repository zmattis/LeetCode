/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 *
 * It is a sweltering summer day, and a boy wants to buy some ice cream bars.
 *
 * At the store, there are n ice cream bars. You are given an array costs of
 * length n, where costs[i] is the price of the i^th ice cream bar in coins.
 * The boy initially has coins coins to spend, and he wants to buy as many ice
 * cream bars as possible. 
 *
 * Return the maximum number of ice cream bars the boy can buy with coins
 * coins.
 *
 * Note: The boy can buy the ice cream bars in any order.
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution
{
public:
	int maxIceCream(std::vector<int> &costs, int coins)
	{
		std::sort(costs.begin(), costs.end());

		int count = 0;
		for (int cost : costs)
		{
			if (cost > coins)
			{
				break;
			}

			coins -= cost;
			count += 1;
		}

		return count;
	}
};

// @lc code=end
