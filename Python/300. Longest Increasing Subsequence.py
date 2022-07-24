'''
动态规划：
1.dp及其含义：dp[i]表示i之前（包括i）且以nums[i]结尾的最长递增子序列
2.递推公式:
for j in range(i):
    if nums[i] > nums[j]:
        dp[i] = max(dp[i], dp[j] + 1)
3.初始化：dp[i] = 1
4.遍历顺序：从前往后
'''
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1: return 1
        dp = [1 for _ in range(n)]
        res = 1
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
            res = max(res, dp[i])
        return res