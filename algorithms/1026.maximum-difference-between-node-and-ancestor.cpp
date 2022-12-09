/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * Given the root of a binary tree, find the maximum value v for which there
 * exist different nodes a and b where v = |a.val - b.val| and a is an ancestor
 * of b.
 *
 * A node a is an ancestor of b if either: any child of a is equal to b or any
 * child of a is an ancestor of b.
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

#include <algorithm>

class Solution
{
private:
	int maxDiff(TreeNode* pNode, int max, int min)
	{
		if (!pNode) return -1;

		if (pNode->val > max) max = pNode->val;
		if (pNode->val < min) min = pNode->val;

		return std::max({abs(max-min), this->maxDiff(pNode->left, max, min), this->maxDiff(pNode->right, max, min)});
	}

public:
	int maxAncestorDiff(TreeNode* root)
	{
		return this->maxDiff(root, root->val, root->val);
	}
};

// @lc code=end

