/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * You are given an integer array coins representing coins of different
 * denominations and an integer amount representing a total amount of money.
 *
 * Return the fewest number of coins that you need to make up that amount. If
 * that amount of money cannot be made up by any combination of the coins,
 * return -1.
 *
 * You may assume that you have an infinite number of each kind of coin.
 *
 * Constraints:
 *   • 1 <= coins.length <= 12
 *   • 1 <= coins[i] <= 2^31 - 1
 *   • 0 <= amount <= 10^4
 */

// @lc code=start

#include <cstring>
#include <vector>

class Solution {
 public:
  int coinChange(const std::vector<int> &coins, int amount) {

    // Complexity:
    //   • Time: O(n*B)
    //   • Space: O(B)

    if (amount == 0) { return 0; }

    int n = amount + 1;
    int dp[n];
    std::memset(dp, 0x00, sizeof(dp));

    for (int i = 0; i < n; ++i) {
      for (int c : coins) {

        if (c > amount) { continue; }

        if (i - c < 0) {
          dp[c] = 1;
          continue;
        }

        if (dp[i - c]) {
          int cnt = dp[i - c] + 1;
          dp[i] = !dp[i] ? cnt : std::min(cnt, dp[i]);
        }
      }
    }

    if (!dp[amount]) { return -1; }
    return dp[amount];
  }
};

// @lc code=end
