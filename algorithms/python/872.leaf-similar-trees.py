#
# @lc app=leetcode id=872 lang=python3
#
# [872] Leaf-Similar Trees
#
# Consider all the leaves of a binary tree, from left to right order, the
# values of those leaves form a leaf value sequence.
#
# Two binary trees are considered leaf-similar if their leaf value sequence is
# the same.
#
# Return true if and only if the two given trees with head nodes root1 and
# root2 are leaf-similar.
#
# Constraints:
#   • The number of nodes in each tree will be in the range [1, 200].
#   • Both of the given trees will have values in the range [0, 200].
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

from collections import deque

class Solution:

    def tree2leaves(self, root: TreeNode | None) -> list[int]:

        if not root:
            return []

        seq = []

        stack = deque([root])
        while stack:
            node = stack.pop()

            if not node.right and not node.left:
                seq.append(node.val)
                continue

            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return seq

    def leafSimilar(self, root1: TreeNode | None, root2: TreeNode | None) -> bool:

        seq1 = self.tree2leaves(root1)
        seq2 = self.tree2leaves(root2)

        return seq1 == seq2

# @lc code=end
