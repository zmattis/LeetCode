/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 *
 * You are given the array paths, where paths[i] = [cityAi, cityBi] means there
 * exists a direct path going from cityAi to cityBi. Return the destination
 * city, that is, the city without any path outgoing to another city.
 *
 * It is guaranteed that the graph of paths forms a line without any loop,
 * therefore, there will be exactly one destination city.
 *
 * Constraints:
 *   • 1 <= paths.length <= 100
 *   • paths[i].length == 2
 *   • 1 <= cityAi.length, cityBi.length <= 10
 *   • cityAi != cityBi
 *   • All strings consist of lowercase and uppercase English letters and the space character.
 */

// @lc code=start

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::string destCity(const std::vector<std::vector<std::string>> &paths) {

    // Complexity:
    //   • Time: O(n)
    //   • Space: O(n)

    std::unordered_set<std::string> ht_src;
    std::unordered_set<std::string> ht_dst;

    for (const std::vector<std::string> &path : paths) {
      ht_src.insert(path[0]);
      ht_dst.insert(path[1]);
    }

    for (const std::string &key : ht_dst) {
      if (!ht_src.contains(key)) {
        return key;
      }
    }

    return "";
  }
};

// @lc code=end
