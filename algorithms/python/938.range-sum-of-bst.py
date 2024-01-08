#
# @lc app=leetcode id=938 lang=python3
#
# [938] Range Sum of BST
#
# Given the root node of a binary search tree and two integers low and high,
# return the sum of values of all nodes with a value in the inclusive range
# [low, high].
#
# Constraints:
#   • The number of nodes in the tree is in the range [1, 2 * 10^4].
#   • 1 <= Node.val <= 10^5
#   • 1 <= low <= high <= 10^5
#   • All Node.val are unique.
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

class Solution:
    def rangeSumBST(self, root: TreeNode | None, low: int, high: int) -> int:

        # Complexity:
        #   • Time: O(n)
        #   • Space: O(h)

        if not root:
            return 0

        ret = root.val if root.val >= low and root.val <= high else 0
        return ret + self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high)

# @lc code=end
