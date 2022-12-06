/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 *
 * The first node is considered odd, and the second node is even, and so on.
 *
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 *
 * You must solve the problem in O(1) extra space complexity and O(n) time
 * complexity.
 */

// @lc code=start

/**
 * Definition for singly-linked list.
 * struct ListNode {
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
	ListNode *oddEvenList(ListNode* pHead)
	{
		if (!pHead) return nullptr;

		ListNode *pEven = nullptr, *pOdd = nullptr;
		ListNode *pEvenHead = nullptr, *pOddHead = nullptr;

		ListNode *pIterator = pHead;

		pEvenHead = pIterator;
		pEven = pEvenHead;
		pIterator = pIterator->next;
		if (!pIterator) { return pHead; }
		pOddHead = pIterator;
		pOdd = pOddHead;
		pIterator = pIterator->next;
		if (!pIterator) { return pHead; }

		uint32_t i = 0;
		while (pIterator)
		{
			// even
			if (i % 2 == 0)
			{
				pEven->next = pIterator;
				pEven = pIterator;
			}

			// odd
			if (i % 2 == 1)
			{
				pOdd->next = pIterator;
				pOdd = pIterator;
			}

			pIterator = pIterator->next;
			i += 1;
		}

		pEven->next = pOddHead;
		pOdd->next = nullptr;

		return pEvenHead;
	}
};

// @lc code=end
