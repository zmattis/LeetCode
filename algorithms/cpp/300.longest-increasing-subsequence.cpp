/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 * Constraints:
 *   • 1 <= nums.length <= 2500
 *   • -10^4 <= nums[i] <= 10^4
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
 public:
  int lengthOfLIS(const std::vector<int> &nums) {

    // Complexity:
    //   • Time: O(n^2)
    //   • Space: O(n)

    size_t n = nums.size();
    std::vector<int> dp(n, 1);

    for (size_t i = 1; i < n; ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i] = std::max(dp[j] + 1, dp[i]);
        }
      }
    }

    return *std::max_element(dp.begin(), dp.end());
  }
};

// @lc code=end
