#
# @lc app=leetcode id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#
# Given the root of a binary tree, return the inorder traversal of its nodes'
# values.
#
# Constraints:
#   • The number of nodes in the tree is in the range [0, 100].
#   • -100 <= Node.val <= 100
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

from collections import deque

class Solution:
    def inorderTraversal(self, root: TreeNode | None) -> list[int]:

        # Recursive
        # if not root:
        #     return []
        # return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)

        # Iterative
        ret = []
        stack = deque()
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            node = stack.pop()
            ret.append(node.val)
            root = node.right
        return ret

# @lc code=end
