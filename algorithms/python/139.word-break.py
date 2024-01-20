#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
#
# Given a string s and a dictionary of strings wordDict, return true if s can
# be segmented into a space-separated sequence of one or more dictionary
# words.
#
# Note that the same word in the dictionary may be reused multiple times in the
# segmentation.
#
# Constraints:
#   • 1 <= s.length <= 300
#   • 1 <= wordDict.length <= 1000
#   • 1 <= wordDict[i].length <= 20
#   • s and wordDict[i] consist of only lowercase English letters.
#   • All the strings of wordDict are unique.
#

# @lc code=start

class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(n)

        n = len(s)
        ht = set(wordDict)
        dp = [False] * n

        for i in range(n):
            for j in range(0, i+1):

                if s[j:i+1] in ht:

                    if j == 0:
                        dp[i] = True
                        continue

                    dp[i] |= dp[j-1]

        return dp[-1]

# @lc code=end
