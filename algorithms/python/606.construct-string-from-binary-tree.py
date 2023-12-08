#
# @lc app=leetcode id=606 lang=python3
#
# [606] Construct String from Binary Tree
#
# Given the root of a binary tree, construct a string consisting of parenthesis
# and integers from a binary tree with the preorder traversal way, and return
# it.
#
# Omit all the empty parenthesis pairs that do not affect the one-to-one
# mapping relationship between the string and the original binary tree.
#
# Constraints:
#   • The number of nodes in the tree is in the range [1, 10^4].
#   • -1000 <= Node.val <= 1000
#

# Binary Tree Traversal
#   • pre-order  = root, left, right
#   • in-order   = left, root, right
#   • post-order = left, right, root

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

class Solution:
    def tree2str(self, root: TreeNode | None) -> str:

        if not root:
            return ""

        ret = f"{root.val}"
        if root.left or root.right:
            ret += f"({self.tree2str(root.left)})"
        if root.right:
            ret += f"({self.tree2str(root.right)})"

        return ret

# @lc code=end
