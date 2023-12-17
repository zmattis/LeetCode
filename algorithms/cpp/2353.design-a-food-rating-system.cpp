/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 *
 * Design a food rating system that can do the following:
 *
 *   • Modify the rating of a food item listed in the system.
 *   • Return the highest-rated food item for a type of cuisine in the system.
 *
 * Implement the FoodRatings class:
 *
 *   • FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes
 *     the system. The food items are described by foods, cuisines and ratings,
 *     all of which have a length of n.
 *
 *     • foods[i] is the name of the i^th food,
 *     • cuisines[i] is the type of cuisine of the i^th food, and
 *     • ratings[i] is the initial rating of the i^th food.
 *
 *   • void changeRating(String food, int newRating) Changes the rating of the
 *     food item with the name food.
 *
 *   • String highestRated(String cuisine) Returns the name of the food item
 *     that has the highest rating for the given type of cuisine. If there is a
 *     tie, return the item with the lexicographically smaller name.
 *
 * Note that a string x is lexicographically smaller than string y if x comes
 * before y in dictionary order, that is, either x is a prefix of y, or if i is
 * the first position such that x[i] != y[i], then x[i] comes before y[i] in
 * alphabetic order.
 *
 * Constraints:
 *   • 1 <= n <= 2 * 10^4
 *   • n == foods.length == cuisines.length == ratings.length
 *   • 1 <= foods[i].length, cuisines[i].length <= 10
 *   • foods[i], cuisines[i] consist of lowercase English letters.
 *   • 1 <= ratings[i] <= 10^8
 *   • All the strings in foods are distinct.
 *   • food will be the name of a food item in the system across all calls to changeRating.
 *   • cuisine will be a type of cuisine of at least one food item in the system across all calls to highestRated.
 *   • At most 2 * 10^4 calls in total will be made to changeRating and highestRated.
 */

// @lc code=start

#include <map>
#include <string>
#include <vector>

class FoodRatings {
 public:
  FoodRatings(const std::vector<std::string> &foods,
              const std::vector<std::string> &cuisines,
              const std::vector<int> &ratings) {
    for (int i = 0; i < foods.size(); i++) {
      food2cuisine_.insert({foods[i], cuisines[i]});
      food2rating_.insert({foods[i], ratings[i]});
    }
  }

  void changeRating(const std::string &food, int newRating) {
    food2rating_[food] = newRating;
  }

  std::string highestRated(const std::string &cuisine) {
    std::map<std::string, int>::const_iterator max = food2rating_.cend();

    for (const auto &f : food2cuisine_) {
      if (f.second != cuisine) {
        continue;
      }

      auto it = food2rating_.find(f.first);
      if (max == food2rating_.end() || it->second > max->second) {
        max = it;
      }
    }

    return max->first;
  }

 private:
  std::map<std::string, std::string> food2cuisine_;
  std::map<std::string, int> food2rating_;
};

// @lc code=end
