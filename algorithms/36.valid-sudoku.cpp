/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * Note:
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable. Only the filled cells need to be validated according to the
 * mentioned rules.
 */

// @lc code=start

#include <vector>
#include <unordered_set>

class SudokuBoard
{
private:
	std::vector<std::vector<char>> board;

	bool validateRows()
	{
		std::unordered_set<char> ht;

		for (uint32_t row = 0; row < 9; row++)
		{
			for (uint32_t col = 0; col < 9; col++)
			{
				char digit = this->board[row][col];
				if (digit == '.') continue;
				if (ht.find(digit) != ht.end()) return false;
				ht.insert(digit);
			}

			ht.clear();
		}

		return true;
	}

	bool validateCols()
	{
		std::unordered_set<char> ht;

		for (uint32_t col = 0; col < 9; col++)
		{
			for (uint32_t row = 0; row < 9; row++)
			{
				char digit = this->board[row][col];
				if (digit == '.') continue;
				if (ht.find(digit) != ht.end()) return false;
				ht.insert(digit);
			}

			ht.clear();
		}

		return true;
	}

	bool validateGrids()
	{
		std::unordered_set<char> ht;

		for (uint32_t grid = 0; grid < 9; grid++)
		{
			uint32_t rowBase = (grid / 3) * 3;
			for (uint32_t row = rowBase; row < rowBase + 3; row++)
			{
				uint32_t colBase = (grid % 3) * 3;
				for (uint32_t col = colBase; col < colBase + 3; col++)
				{
					char digit = this->board[row][col];
					if (digit == '.') continue;
					if (ht.find(digit) != ht.end()) return false;
					ht.insert(digit);
				}
			}

			ht.clear();
		}

		return true;
	}


public:
	SudokuBoard(const std::vector<std::vector<char>> &board)
	{
		this->board = board;
	}

	bool Validate()
	{
		return this->validateRows() && this->validateCols() && this->validateGrids();
	}

};

class Solution
{
public:
	bool isValidSudoku(const std::vector<std::vector<char>> &board)
	{
		SudokuBoard sudoku = SudokuBoard(board);
		return sudoku.Validate();
	}
};

// @lc code=end
