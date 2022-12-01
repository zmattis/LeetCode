/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 *
 * You are given a string s of even length. Split this string into two halves
 * of equal lengths, and let a be the first half and b be the second half.
 *
 * Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
 * 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
 * lowercase letters.
 *
 * Return true if a and b are alike. Otherwise, return false.
 */

// @lc code=start

#include <string>
#include <algorithm>

class Solution
{
private:
	bool isVowel(char c)
	{
		c = std::tolower(c);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

public:
	bool halvesAreAlike(const std::string &str)
	{
		std::string strFront = str.substr(0, str.size() / 2);
		std::string strBack  = str.substr(str.size() / 2);

		uint32_t vowelsFront = 0, vowelsBack = 0;
		std::for_each(strFront.begin(), strFront.end(), [&] (char c) { if (this->isVowel(c)) vowelsFront++; });
		std::for_each(strBack.begin(),  strBack.end(),  [&] (char c) { if (this->isVowel(c)) vowelsBack++;  });

		return vowelsFront == vowelsBack;
	}
};

// @lc code=end
