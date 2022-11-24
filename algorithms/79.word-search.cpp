/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 */

// @lc code=start

#include <string>
#include <vector>

class Solution
{
private:
	bool findWord(int32_t m, int32_t n,
		std::vector<std::vector<char>>& board, const std::pair<int32_t, int32_t> &loc,
		const std::string &word, int32_t charId)
	{
		auto [row, col] = loc;
		if (row < 0 || row >= m | col < 0 || col >= n)
		{
			return false;
		}

		if (board[row][col] != word[charId])
		{
			return false;
		}

		if (charId == word.size() - 1)
		{
			return true;
		}

		char letter = board[row][col];
		board[row][col] = '\0';

		if (this->findWord(m, n, board, {row-1, col}, word, charId+1) ||
			this->findWord(m, n, board, {row+1, col}, word, charId+1) ||
			this->findWord(m, n, board, {row, col-1}, word, charId+1) ||
			this->findWord(m, n, board, {row, col+1}, word, charId+1))
		{
			return true;
		}

		board[row][col] = letter;
		return false;
	}

public:
	bool exist(std::vector<std::vector<char>>& board, const std::string &word)
	{
		int32_t m = board.size();
		int32_t n = board[0].size();

		for (int32_t i = 0; i < m; i++)
		{
			for (int32_t j = 0; j < n; j++)
			{
				if (this->findWord(m, n, board, {i,j}, word, 0))
				{
					return true;
				}
			}
		}

		return false;
	}
};

// @lc code=end
