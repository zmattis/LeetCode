/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 *
 * Given the root node of a binary search tree and two integers low and high,
 * return the sum of values of all nodes with a value in the inclusive range
 * [low, high].
 */

// @lc code=start

/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
	int recursiveSum(TreeNode const *pNode, int lo, int hi)
	{
		if (!pNode) return 0;

		if (pNode->val < lo) return recursiveSum(pNode->right, lo, hi);
		if (pNode->val > hi) return recursiveSum(pNode->left, lo, hi);

		return pNode->val + recursiveSum(pNode->left, lo, hi) + recursiveSum(pNode->right, lo, hi);
	}

public:
	int rangeSumBST(TreeNode *root, int low, int high)
	{
		return this->recursiveSum(root, low, high);
	}
};

// @lc code=end
