/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, and /. Each operand may be an integer or
 * another expression.
 *
 * Note that division between two integers should truncate toward zero.
 *
 * It is guaranteed that the given RPN expression is always valid. That means
 * the expression would always evaluate to a result, and there will not be any
 * division by zero operation.
 */

// @lc code=start

#include <string>
#include <vector>
#include <stack>

class Solution {
public:
	int evalRPN(const std::vector<std::string> &tokens)
	{
		std::stack<int64_t> stack;

		for (const std::string &str : tokens)
		{
			if (str == "+" || str == "-" || str == "*" || str == "/")
			{
				int64_t val2 = stack.top();
				stack.pop();

				int64_t val1 = stack.top();
				stack.pop();

				int64_t ret = 0;
				if      (str == "+") ret = val1 + val2;
				else if (str == "-") ret = val1 - val2;
				else if (str == "*") ret = val1 * val2;
				else if (str == "/") ret = val1 / val2;

				stack.push(ret);
				continue;
			}

			stack.push(std::stoi(str));
		}

		return stack.top();
	}
};

// @lc code=end
