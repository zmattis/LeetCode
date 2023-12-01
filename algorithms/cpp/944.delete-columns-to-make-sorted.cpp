/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 *
 * You are given an array of n strings strs, all of the same length.
 *
 * The strings can be arranged such that there is one on each line, making a
 * grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:
 *
 *     abc
 *     bce
 *     cae
 *
 * You want to delete the columns that are not sorted lexicographically. In the
 * above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e')
 * are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.
 *
 * Return the number of columns that you will delete.
 */

// @lc code=start

#include <string>
#include <vector>

class Solution
{
public:
	int minDeletionSize(const std::vector<std::string> &strs)
	{
		if (strs.size() <= 1) return 0;

		uint32_t count = 0;
		for (uint32_t col = 0; col < strs[0].size(); col++)
		{
			for (uint32_t row = 0; row < strs.size() - 1; row++)
			{
				char c2 = strs[row+1][col];
				char c1 = strs[row][col];

				if (c2 - c1 < 0)
				{
					count += 1;
					break;
				}
			}
		}

		return count;
	}
};

// @lc code=end
