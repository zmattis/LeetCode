#
# @lc app=leetcode id=1026 lang=python3
#
# [1026] Maximum Difference Between Node and Ancestor
#
# Given the root of a binary tree, find the maximum value v for which there
# exist different nodes a and b where v = |a.val - b.val| and a is an ancestor
# of b.
#
# A node a is an ancestor of b if either: any child of a is equal to b or any
# child of a is an ancestor of b.
#
# Constraints:
#   • The number of nodes in the tree is in the range [2, 5000].
#   • 0 <= Node.val <= 10^5
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

class Solution:

    def recurse(self, root: TreeNode | None, val_min: int, val_max: int) -> int:

        if not root:
            return 0

        val_left = self.recurse(root.left, min(root.val, val_min), max(root.val, val_max))
        val_right = self.recurse(root.right, min(root.val, val_min), max(root.val, val_max))
        val_root = max(abs(val_min - root.val), abs(val_max - root.val))

        return max(val_root, val_right, val_left)

    def maxAncestorDiff(self, root: TreeNode) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(h)

        return self.recurse(root, root.val, root.val)

# @lc code=end

