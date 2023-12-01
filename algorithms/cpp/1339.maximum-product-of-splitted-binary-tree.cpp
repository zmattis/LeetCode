/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * Given the root of a binary tree, split the binary tree into two subtrees by
 * removing one edge such that the product of the sums of the subtrees is
 * maximized.
 *
 * Return the maximum product of the sums of the two subtrees. Since the answer
 * may be too large, return it modulo 10^9 + 7.
 *
 * Note that you need to maximize the answer before taking the mod and not
 * after taking it.
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
	int64_t treeSum(const TreeNode *pNode)
	{
		if (!pNode) return 0;
		return this->treeSum(pNode->left) + this->treeSum(pNode->right) + pNode->val;
	}

	int64_t subtreeSum(int64_t treeSum, const TreeNode *pNode, int64_t &maxProduct)
	{
		if (!pNode) return 0;
		int valLeft = this->subtreeSum(treeSum, pNode->left, maxProduct), valRight = this->subtreeSum(treeSum, pNode->right, maxProduct);
		maxProduct = std::max({maxProduct, (treeSum - valLeft) * valLeft, (treeSum - valRight) * valRight});
		return valLeft + valRight + pNode->val;
	}

public:
	int maxProduct(const TreeNode *root)
	{
		int64_t treeSum = this->treeSum(root);

		int64_t product = 0;
		this->subtreeSum(treeSum, root, product);
		return (int)(product %  (int64_t)(1e9 + 7));
	}
};

// @lc code=end
