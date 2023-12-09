#
# @lc app=leetcode id=513 lang=python3
#
# [513] Find Bottom Left Tree Value
#
# Given the root of a binary tree, return the leftmost value in the last row of
# the tree.
#
# Constraints:
#   • The number of nodes in the tree is in the range [1, 10^4].
#   • -2^31 <= Node.val <= 2^31 - 1
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

from collections import deque

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:

        ret = root.val
        depth = 0

        q = deque([(root, depth)])
        while q:
            root, level = q.popleft()
            if root:

                if level > depth:
                    ret = root.val
                    depth = level

                q.append((root.left, level + 1))
                q.append((root.right, level + 1))

        return ret

# @lc code=end
