/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 *
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 */

// @lc code=start

#include <vector>
#include <algorithm>

class Solution
{
public:
	int minFallingPathSum(std::vector<std::vector<int>> &matrix)
	{
		int numRows = matrix.size();
		int numCols = matrix[0].size();

		for (int row = numRows - 1; row >= 0; row--)
		{
			if (row < numRows - 1)
			{
				for (int col = 0; col < numCols; col++)
				{
					matrix[row][col] += std::min({
						matrix[row+1][col],
						matrix[row+1][std::max(col-1, 0)],
						matrix[row+1][std::min(col+1, numCols-1)]
						});
				}
			}
		}

		return *std::min_element(matrix[0].begin(), matrix[0].end());;
	}
};

// @lc code=end
