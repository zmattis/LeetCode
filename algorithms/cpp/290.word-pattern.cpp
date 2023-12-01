/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * Given a pattern and a string s, find if s follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in s.
 */

// @lc code=start

#include <string>
#include <unordered_map>
#include <sstream>

class Solution
{
private:
	std::string standardizePattern(const std::string &pattern)
	{
		std::stringstream ss;

		int i = 0;
		std::unordered_map<char, int> hm;
		for (char c : pattern)
		{
			if (hm.find(c) == hm.end())
			{
				hm[c] = i;
				i += 1;
			}

			ss << hm[c];
		}

		return ss.str();
	}

	std::string standardizeWord(const std::string &str)
	{
		std::stringstream ss;

		int i = 0;
		std::unordered_map<std::string, uint32_t> hm;


		std::string word;
		std::stringstream streamer(str);
		while (streamer >> word)
		{
			if (hm.find(word) == hm.end())
			{
				hm[word] = i++;
			}

			ss << hm[word];
		}

		return ss.str();
	}

public:
	bool wordPattern(const std::string &pattern, const std::string &str)
	{
		std::string standardPattern = this->standardizePattern(pattern);
		std::string standardWord = this->standardizeWord(str);

		return standardPattern == standardWord;
	}
};

// @lc code=end

