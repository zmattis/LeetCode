/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 *
 * Two strings are considered close if you can attain one from the other using
 * the following operations:
 *
 * - Operation 1: Swap any two existing characters.
 *       For example, abcde -> aecdb
 * - Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
 *       For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
 *
 * You can use the operations on either string as many times as necessary.
 *
 * Given two strings, word1 and word2, return true if word1 and word2 are
 * close, and false otherwise.
 */

// @lc code=start

#include <string>
#include <vector>
#include <set>
#include <algorithm>

class Solution
{
public:
	bool closeStrings(const std::string &word1, const std::string &word2)
	{
		// 1. consistent unique characters
		// 2. equal frequency distribution of characters

		std::set<char> s1, s2;
		std::vector<int32_t> v1(26), v2(26);

		std::for_each(word1.begin(), word1.end(),[&s1,&v1](char c) { s1.insert(c); v1[c-'a']++; });
		std::for_each(word2.begin(), word2.end(),[&s2,&v2](char c) { s2.insert(c); v2[c-'a']++; });

		std::sort(v1.begin(),v1.end());
		std::sort(v2.begin(),v2.end());

		return s1==s2 && v1==v2;
	}
};

// @lc code=end
