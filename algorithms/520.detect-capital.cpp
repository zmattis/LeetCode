/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 *     - All letters in this word are capitals, like "USA".
 *     - All letters in this word are not capitals, like "leetcode".
 *     - Only the first letter in this word is capital, like "Google".
 *
 * Given a string word, return true if the usage of capitals in it is right.
 */

// @lc code=start

#include <string>
#include <cctype>

class Solution
{
public:
	bool detectCapitalUse(const std::string &word)
	{
		if (word.size() <= 1) return true;

		bool upper1 = (bool)std::isupper((int)word[0]);
		bool upper2 = (bool)std::isupper((int)word[1]);

		if (!upper1 && upper2) return false;

		for (uint32_t i = 2; i < word.size(); i++)
		{
			if ((bool)std::isupper((int)word[i]) != upper2)
			{
				return false;
			}
		}

		return true;
	}
};

// @lc code=end
