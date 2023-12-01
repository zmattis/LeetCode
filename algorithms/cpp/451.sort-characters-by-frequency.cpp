/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * Given a string s, sort it in decreasing order based on the frequency of the
 * characters. The frequency of a character is the number of times it appears
 * in the string.
 *
 * Return the sorted string. If there are multiple answers, return any of
 * them.
 */

// @lc code=start

#include <string>
#include <sstream>
#include <map>
#include <algorithm>

class Solution
{
private:
	template <class K, class V>
	std::multimap<V,K> flipMap(const std::map<K,V> &map)
	{
		std::multimap<V,K> flipped;
		std::transform(std::begin(map), std::end(map), std::inserter(flipped, flipped.begin()),
			[](const std::pair<K,V> &kv) { return std::pair<V,K>(kv.second, kv.first); });

		return flipped;
	}

public:
	std::string frequencySort(const std::string &s)
	{
		std::map<char,int32_t> hm;
		std::for_each(std::begin(s), std::end(s), [&hm](char c) { hm[c]++; });

		std::multimap<int32_t,char> mm = this->flipMap(hm);

		std::stringstream ss;
		std::for_each(std::rbegin(mm), std::rend(mm), [&ss](const std::pair<int32_t,char> &kv) { for (uint32_t i=0;i<kv.first;i++) ss << kv.second; });

		return ss.str();
	}
};

// @lc code=end
