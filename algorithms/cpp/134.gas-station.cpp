/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 *
 * There are n gas stations along a circular route, where the amount of gas at
 * the i^th station is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from the i^th station to its next (i + 1)^th station. You begin the
 * journey with an empty tank at one of the gas stations.
 *
 * Given two integer arrays gas and cost, return the starting gas station's
 * index if you can travel around the circuit once in the clockwise direction,
 * otherwise return -1. If there exists a solution, it is guaranteed to be
 * unique
 */

// @lc code=start

#include <vector>

class Solution
{
public:
	int canCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost)
	{
		int totalGas = 0;
		int totalCost = 0;

		int currGas = 0;
		int startingPoint = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			totalGas += gas[i];
			totalCost += cost[i];

			currGas += gas[i] - cost[i];

			if (currGas < 0)
			{
				startingPoint = i + 1;
				currGas = 0;
			}
		}

		if (totalGas < totalCost)
		{
			return -1;
		}

		return startingPoint;
	}
};

// @lc code=end
