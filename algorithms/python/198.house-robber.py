#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#
# You are a professional robber planning to rob houses along a street. Each
# house has a certain amount of money stashed, the only constraint stopping you
# from robbing each of them is that adjacent houses have security systems
# connected and it will automatically contact the police if two adjacent houses
# were broken into on the same night.
#
# Given an integer array nums representing the amount of money of each house,
# return the maximum amount of money you can rob tonight without alerting the
# police.
#
# Constraints:
#   • 1 <= nums.length <= 100
#   • 0 <= nums[i] <= 400
#

# @lc code=start

class Solution:
    def rob(self, nums: list[int]) -> int:

        # Complexity:
        #   • Time: O(n^2)
        #   • Space: O(n)

        n = len(nums)
        if n == 1:
            return nums[-1]
        elif n == 2:
            return max(nums)

        dp = [0] * n
        dp[0] = nums[0]
        dp[1] = nums[1]

        for i in range(n):
            for j in range(i-1):
                dp[i] = max(nums[i] + dp[j], dp[i])

        return max(dp)

# @lc code=end

nums = [1,2,3,1]
nums = [2,7,9,3,1]
sol = Solution()
ret = sol.rob(nums)
print(f'ret={ret}')
