/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 *
 * You are given an m x n matrix maze (0-indexed) with empty cells (represented
 * as '.') and walls (represented as '+'). You are also given the entrance of
 * the maze, where entrance = [entrancerow, entrancecol] denotes the row and
 * column of the cell you are initially standing at.
 *
 * In one step, you can move one cell up, down, left, or right. You cannot step
 * into a cell with a wall, and you cannot step outside the maze. Your goal is
 * to find the nearest exit from the entrance. An exit is defined as an empty
 * cell that is at the border of the maze. The entrance does not count as an
 * exit.
 *
 * Return the number of steps in the shortest path from the entrance to the
 * nearest exit, or -1 if no such path exists.
 */

// @lc code=start

#include <stdint.h>

#include <vector>
#include <unordered_set>
#include <queue>

class Maze
{
private:
	int32_t num_rows;
	int32_t num_cols;
	std::vector<std::vector<char>> maze;

	int32_t i;
	int32_t j;

	void setEntrance(int32_t row, int32_t col)
	{
		this->i = row;
		this->j = col;
	}

	bool isValidNode(int32_t row, int32_t col) const
	{
		return (row >= 0 && row < this->num_rows) && (col >= 0 && col < this->num_cols);
	}

	bool isPath(int32_t row, int32_t col) const
	{
		if (!isValidNode(row, col)) { return false; }
		return maze[row][col] == '.';
	}

	bool isExit(int32_t row, int32_t col) const
	{
		if (!isValidNode(row, col)) { return false; }
		if (row == i && col == j) { return false; }
		return (row == 0) || row == (this->num_rows-1) || (col == 0) || (col == this->num_cols-1);
	}

	struct hash
	{
		size_t operator()(const std::pair<int32_t, int32_t> &pair) const
		{
			return pair.first * 1024 + pair.second;
		}
	};

public:
	Maze(std::vector<std::vector<char>> &maze)
	{
		size_t m = maze.size();
		size_t n = maze[0].size();

		this->num_rows = static_cast<int32_t>(m);
		this->num_cols = static_cast<int32_t>(n);

		this->maze = maze;
	}

	int32_t NearestExit(std::vector<int32_t> &entrance)
	{
		if (entrance.size() != 2) { throw std::runtime_error("misconfigured maze entrance"); }

		int32_t row = entrance[0];
		int32_t col = entrance[1];

		if (!isValidNode(row, col)) { throw std::runtime_error("maze entrance bounds not valid"); }
		this->setEntrance(row, col);

		std::unordered_set<std::pair<int32_t, int32_t>, Maze::hash> ht;
		std::queue<std::tuple<int32_t, int32_t, int32_t>> nodes;

		nodes.push({row, col, 0});
		while (!nodes.empty())
		{
			auto [ r, c, distance ] = nodes.front();
			nodes.pop();

			if (!this->isValidNode(r, c)) { continue; }
			if (!this->isPath(r, c)) { continue; }
			if (ht.find({r, c}) != ht.end()) { continue; }
			if (this->isExit(r, c)) { return distance; }

			ht.insert({r, c});

			nodes.push({r-1, c, distance+1});
			nodes.push({r+1, c, distance+1});
			nodes.push({r, c-1, distance+1});
			nodes.push({r, c+1, distance+1});
		}

		return -1;
	}
};

class Solution
{
public:
	int32_t nearestExit(std::vector<std::vector<char>> &maze, std::vector<int32_t> &entrance)
	{
		Maze labyrinth = Maze(maze);
		return labyrinth.NearestExit(entrance);
	}
};

// @lc code=end
