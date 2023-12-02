#
# @lc app=leetcode id=1160 lang=python3
#
# [1160] Find Words That Can Be Formed by Characters
#
# You are given an array of strings words and a string chars.
#
# A string is good if it can be formed by characters from chars (each character
# can only be used once).
#
# Return the sum of lengths of all good strings in words.
#
# Constraints:
#   • 1 <= words.length <= 1000
#   • 1 <= words[i].length, chars.length <= 100
#   • words[i] and chars consist of lowercase English letters.
#

# @lc code=start

from collections import defaultdict

class Solution:
    def countCharacters(self, words: list[str], chars: str) -> int:
        vocab = defaultdict(int)
        for c in chars:
            vocab[c] += 1

        cnt = 0
        for word in words:
            builder = defaultdict(int)
            for w in word:
                builder[w] += 1

            valid = True
            for letter, frequency in builder.items():
                if frequency > vocab[letter]:
                    valid = False
                    break

            if valid:
                cnt += len(word)

        return cnt

# @lc code=end
