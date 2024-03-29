'''
动态规划：
1.dp及其含义：dp[i]表示以nums[i]为结尾的子序列的最大和
2.递推公式：dp[i] = max(nums[i], dp[i-1] + nums[i])
3.初始化：dp[0] = nums[0]
4.遍历顺序：从前往后
'''
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return nums[0]
        dp = [0 for _ in range(n)]
        dp[0] = nums[0]
        res = dp[0]
        for i in range(1, n):
            dp[i] = max(nums[i], dp[i-1] + nums[i])
            res = max(res, dp[i])
        return res

'''
贪心：当前连续和为负时，立刻放弃，从下一个元素开始计算连续和
'''
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = -float('inf')
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            res = max(res, sum)
            if sum < 0:
                sum = 0
        return res