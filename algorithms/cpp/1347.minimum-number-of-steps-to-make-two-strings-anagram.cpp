/*
 * @lc app=leetcode id=1347 lang=cpp
 *
 * [1347] Minimum Number of Steps to Make Two Strings Anagram
 *
 * You are given two strings of the same length s and t. In one step you can
 * choose any character of t and replace it with another character.
 *
 * Return the minimum number of steps to make t an anagram of s.
 *
 * An Anagram of a string is a string that contains the same characters with a
 * different (or the same) ordering.
 *
 * Constraints:
 *   • 1 <= s.length <= 5 * 10^4
 *   • s.length == t.length
 *   • s and t consist of lowercase English letters only.
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
 public:
  int minSteps(const std::string &s, const std::string &t) {

    // Complexity:
    //   • Time: O(n)
    //   • Space: O(n)

    std::unordered_map<char, int> hm_source, hm_target;
    std::for_each(s.begin(), s.end(), [&hm_source](char c) { hm_source[c] += 1; });
    std::for_each(t.begin(), t.end(), [&hm_target](char c) { hm_target[c] += 1; });

    int ret = 0;
    for (const auto &[key, count] : hm_source) {
      if (!hm_target.contains(key)) {
        ret += count;
        continue;
      }

      ret += std::max(count - hm_target[key], 0);
    }

    return ret;
  }
};

// @lc code=end
