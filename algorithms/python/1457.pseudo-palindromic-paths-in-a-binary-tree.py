#
# @lc app=leetcode id=1457 lang=python3
#
# [1457] Pseudo-Palindromic Paths in a Binary Tree
#
# Given a binary tree where node values are digits from 1 to 9. A path in the
# binary tree is said to be pseudo-palindromic if at least one permutation of
# the node values in the path is a palindrome.
#
# Return the number of pseudo-palindromic paths going from the root node to
# leaf nodes.
#
# Constraints:
# • The number of nodes in the tree is in the range [1, 10^5].
# • 1 <= Node.val <= 9
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

from collections import Counter

class Solution:

    def dfs(self, node: TreeNode | None, path: int) -> int:

        if not node:
            return 0

        mask = path ^ (1 << node.val)
        if not node.left and not node.right:
            return int(mask.bit_count() <= 1)

        return self.dfs(node.left, mask) + self.dfs(node.right, mask)

    def pseudoPalindromicPaths (self, root: TreeNode) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(h)

        return self.dfs(root, 0)

# @lc code=end
