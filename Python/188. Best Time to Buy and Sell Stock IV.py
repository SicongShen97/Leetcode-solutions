'''
动态规划：
1.确定dp及其含义:
dp[i][0]:第i天无操作
dp[i][2*j - 1]：第i天第j次持有所剩的最大现金
dp[i][2*j]：第i天第j次出售所剩的最大现金
2.递推公式：
dp[i][0] = dp[i-1][0]
for j in range(1, k+1):
    dp[i][2*j - 1] = max(dp[i-1][2*j - 1], dp[i-1][2*j - 2] - prices[i])
    dp[i][2*j] = max(dp[i-1][2*j], dp[i-1][2*j - 1] + prices[i])
3.初始化：
dp[0][0] = 0
for j in range(1, k+1):
    dp[0][2*j - 1] = -prices[0]
    dp[0][2*j] = 0
4.遍历顺序：从前往后
'''
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        days = len(prices)
        if days<=1: return 0
        dp = [[0 for _ in range(2*k + 1)] for _ in range(days)]
        for j in range(1, k+1):
            dp[0][2*j - 1] = -prices[0]
            dp[0][2*j] = 0
        for i in range(1, days):
            for j in range(1, k+1):
                dp[i][2*j - 1] = max(dp[i-1][2*j - 1], dp[i-1][2*j - 2] - prices[i])
                dp[i][2*j] = max(dp[i-1][2*j], dp[i-1][2*j - 1] + prices[i])
        return dp[-1][-1]