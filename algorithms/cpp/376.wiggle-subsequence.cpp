/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * A wiggle sequence is a sequence where the differences between successive
 * numbers strictly alternate between positive and negative. The first
 * difference (if one exists) may be either positive or negative. A sequence
 * with one element and a sequence with two non-equal elements are trivially
 * wiggle sequences.
 *
 *   • For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences
 *    (6, -3, 5, -7, 3) alternate between positive and negative.
 *   • In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences.
 *     The first is not because its first two differences are positive, and the
 *     second is not because its last difference is zero.
 *
 * A subsequence is obtained by deleting some elements (possibly zero) from the
 * original sequence, leaving the remaining elements in their original order.
 *
 * Given an integer array nums, return the length of the longest wiggle
 * subsequence of nums.
 *
 * Constraints:
 *   • 1 <= nums.length <= 1000
 *   • 0 <= nums[i] <= 1000
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
 public:
  int wiggleMaxLength(const std::vector<int> &nums) {

    // Complexity:
    //   • Time: O(n)
    //   • Space: O(n)

    int n = nums.size();
    std::vector<int> l(n, 1);
    std::vector<int> g(n, 1);

    for (int i = 1; i < n; ++i) {
      l[i] = l[i-1];
      g[i] = g[i-1];
      if (nums[i] > nums[i-1]) {
        g[i] = 1 + l[i-1];
      }
      if (nums[i] < nums[i-1]) {
        l[i] = 1 + g[i-1];
      }
    }

    return std::max(l[n-1], g[n-1]);
  }
};

// @lc code=end
