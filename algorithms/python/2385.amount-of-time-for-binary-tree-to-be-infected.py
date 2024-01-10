#
# @lc app=leetcode id=2385 lang=python3
#
# [2385] Amount of Time for Binary Tree to Be Infected
#
# You are given the root of a binary tree with unique values, and an integer
# start. At minute 0, an infection starts from the node with value start.
#
# Each minute, a node becomes infected if:
#   • The node is currently uninfected.
#   • The node is adjacent to an infected node.
#
# Return the number of minutes needed for the entire tree to be infected.
#
# Constraints:
#   • The number of nodes in the tree is in the range [1, 10^5].
#   • 1 <= Node.val <= 10^5
#   • Each node has a unique value.
#   • A node with a value of start exists in the tree.
#

# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# @lc code=start

from collections import deque

class Solution:
    def amountOfTime(self, root: TreeNode, start: int) -> int:

        graph: dict[int, set[int]] = {}

        q = deque([(root, None)])
        while q:
            child, parent = q.pop()
            neighbors = set()
            if parent:
                neighbors.add(parent.val)
            if child.left:
                neighbors.add(child.left.val)
                q.appendleft((child.left, child))
            if child.right:
                neighbors.add(child.right.val)
                q.appendleft((child.right, child))

            graph[child.val] = neighbors

        delta = 0

        q = deque([(start, 0)])
        visited = { start }
        while q:
            val, level = q.pop()

            delta = max(level, delta)
            visited.add(val)

            neighbors = graph[val]
            for n in neighbors:
                if n in visited:
                    continue
                q.appendleft((n, level + 1))

        return delta

# @lc code=end

