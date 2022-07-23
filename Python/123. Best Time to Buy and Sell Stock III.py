'''
动态规划：
1.确定dp及其含义:
dp[i][0]:第i天无操作
dp[i][1]：第i天第一次持有所剩的最大现金
dp[i][2]：第i天第一次出售所剩的最大现金
dp[i][3]：第i天第二次持有所剩的最大现金
dp[i][4]：第i天第二次出售所剩的最大现金
2.递推公式：
dp[i][0] = dp[i-1][0]
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
3.初始化：
dp[0][0] = 0
dp[0][1] = -prices[0]
dp[0][2] = 0
dp[0][3] = -prices[0]
dp[0][4] = 0
4.遍历顺序：从前往后
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        size = len(prices)
        if size==1: return 0
        dp = [[0 for _ in range(5)] for _ in range(size)]
        dp[0][1] = -prices[0]
        dp[0][3] = -prices[0]
        for i in range(1, size):
            dp[i][0] = dp[i-1][0]
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
        return dp[-1][-1]