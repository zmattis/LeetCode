/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters. For example, "ace" is a subsequence of "abcde".
 *
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 */

// @lc code=start

#include <cstring>
#include <string>

class Solution
{
public:
	int longestCommonSubsequence(const std::string &text1, const std::string &text2)
	{
		int m=text1.size(),n=text2.size();
		int dp[m+1][n+1];
		std::memset(dp, 0x00, sizeof(dp));

		for(int i=1;i<m+1;i++)
		{
			for(int j=1;j<n+1;j++)
			{
				if(text1[i-1]==text2[j-1])
				{
					dp[i][j]= dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}

		return dp[m][n];
	}
};

// @lc code=end
