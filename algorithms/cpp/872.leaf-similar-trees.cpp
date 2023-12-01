/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * Consider all the leaves of a binary tree, from left to right order, the
 * values of those leaves form a leaf value sequence.
 *       3
 *      / \
 *     5   1
 *    /|   |\
 *   6 2   9 8
 *     /\
 *    7 4
 *
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
 * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
 * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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

#include <vector>

class Solution
{
private:
	void leafSequence(TreeNode* pNode, std::vector<int> &seq)
	{
		if (!pNode) return;

		if (!pNode->left && !pNode->right)
		{
			seq.push_back(pNode->val);
			return;
		}

		this->leafSequence(pNode->left, seq);
		this->leafSequence(pNode->right, seq);
	}

public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2)
	{
		std::vector<int> leafSequence1, leafSequence2;
		this->leafSequence(root1, leafSequence1);
		this->leafSequence(root2, leafSequence2);

		return leafSequence1 == leafSequence2;
	}
};

// @lc code=end
