/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 *
 * Implement a first in first out (FIFO) queue using only two stacks. The
 * implemented queue should support all the functions of a normal queue (push,
 * peek, pop, and empty).
 *
 * Implement the MyQueue class:
 *
 *     void push(int x) - Pushes element x to the back of the queue.
 *     int pop()        - Removes the element from the front of the queue and returns it.
 *     int peek()       - Returns the element at the front of the queue.
 *     bool empty()     - Returns true if the queue is empty, false otherwise.
 *
 * Notes:
 * You must use only standard operations of a stack, which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, the stack may not be supported natively. You may
 * simulate a stack using a list or deque (double-ended queue) as long as you
 * use only a stack's standard operations.
 */

// @lc code=start

#include <stack>

class MyQueue
{
private:
	std::stack<int> in, out;

public:
	MyQueue() { };

	void push(int x)
	{
		in.push(x);
	}

	int pop()
	{
		int x = this->peek();
		this->out.pop();
		return x;
	}

	int peek()
	{
		if (this->out.empty())
		{
			while (!this->in.empty())
			{
				this->out.push(this->in.top());
				in.pop();
			}
		}

		return out.top();
	}

	bool empty()
	{
		return this->out.empty() && this->in.empty();
	}
};

// @lc code=end
