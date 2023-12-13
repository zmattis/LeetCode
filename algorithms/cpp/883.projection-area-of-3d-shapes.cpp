/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 *
 * You are given an n x n grid where we place some 1 x 1 x 1 cubes that are
 * axis-aligned with the x, y, and z axes.
 *
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of the
 * cell (i, j).
 *
 * We view the projection of these cubes onto the xy, yz, and zx planes.
 *
 * A projection is like a shadow, that maps our 3-dimensional figure to a
 * 2-dimensional plane. We are viewing the "shadow" when looking at the cubes
 * from the top, the front, and the side.
 *
 * Return the total area of all three projections.
 *
 * Constraints:
 *   • n == grid.length == grid[i].length
 *   • 1 <= n <= 50
 *   • 0 <= grid[i][j] <= 50
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
 public:
  int projectionArea(std::vector<std::vector<int>>& grid) {

    // Complexity:
    //   • Time: O(n^2)
    //   • Space: O(1)

    int cnt = 0;

    for (int i = 0; i < grid.size(); ++i) {

      int max_row = 0;
      int max_col = 0;

      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j]) { cnt += 1;}
        max_row = std::max(max_row, grid[j][i]);
        max_col = std::max(max_col, grid[i][j]);
      }

      cnt += max_row;
      cnt += max_col;
    }

    return cnt;
  }
};

// @lc code=end
