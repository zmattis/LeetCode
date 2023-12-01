/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 *
 * Given the head of a singly linked list, return the middle node of the linked
 * list.
 *
 * If there are two middle nodes, return the second middle node.
 */

// @lc code=start

/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
	ListNode *middleNode(ListNode *pHead)
	{
		if (!pHead) return nullptr;

		uint32_t i = 0;
		ListNode *pMid = pHead;

		for (ListNode *pIt = pHead; pIt != nullptr; pIt = pIt->next)
		{
			if (i % 2) { pMid = pMid->next; }
			i += 1;
		}

		return pMid;
	}
};

// @lc code=end
