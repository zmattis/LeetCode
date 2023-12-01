/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only appear in
 * the sequence at most once. Note that the path does not need to pass through
 * the root.
 *
 * The path sum of a path is the sum of the node's values in the path.
 *
 * Given the root of a binary tree, return the maximum path sum of any
 * non-empty path.
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
	void maxPathValue(TreeNode *pNode, int &pathValue, int &pathMax)
	{
		if (!pNode) return;

		if (!pNode->left && !pNode->right)
		{
			pathValue = pNode->val;
			pathMax   = pNode->val;
			return;
		}


		int lValue = 0, lMax = INT32_MIN;
		if (pNode->left)
		{
			this->maxPathValue(pNode->left, lValue, lMax);
		}

		int rValue = 0, rMax = INT32_MIN;
		if (pNode->right)
		{
			this->maxPathValue(pNode->right, rValue, rMax);
		}

		lValue = std::max({lValue, 0});
		rValue = std::max({rValue, 0});

		int currMax = pNode->val + lValue + rValue;

		pathMax   = std::max({currMax, lMax, rMax});
		pathValue = std::max({lValue, rValue}) + pNode->val;
	}

public:
	int maxPathSum(TreeNode* root)
	{
		int pathValue, pathMax;
		this->maxPathValue(root, pathValue, pathMax);

		return pathMax;
	}
};

// @lc code=end
