#
# @lc app=leetcode id=1239 lang=python3
#
# [1239] Maximum Length of a Concatenated String with Unique Characters
#
# You are given an array of strings arr. A string s is formed by the
# concatenation of a subsequence of arr that has unique characters.
#
# Return the maximum possible length of s.
#
# A subsequence is an array that can be derived from another array by deleting
# some or no elements without changing the order of the remaining elements.
#
# Constraints:
#   • 1 <= arr.length <= 16
#   • 1 <= arr[i].length <= 26
#   • arr[i] contains only lowercase English letters.
#

# @lc code=start

class Solution:
    def maxLength(self, arr: list[str]) -> int:

        # Complexity:
        #   • Time: O(2^n)
        #   • Space: O(2^n)

        n = len(arr)
        ht = [0x00] * n
        for i, s in enumerate(arr):
            for c in s:
                mask = 1 << (ord(c) - ord("a"))
                if ht[i] & mask:
                    ht[i] = 0x00
                    break
                ht[i] |= mask

        dp = [x for x in ht]
        for i in range(n):
            for j in range(len(dp) - 1, -1, -1):
                if ht[i] & dp[j]:
                    continue
                dp.append(ht[i] | dp[j])

        return max(x.bit_count() for x in dp)

# @lc code=end
