'''
动态规划：
1.确定dp及其含义:dp[i][0]表示第i天持有股票所得的最多现金，dp[i][1]表示第i天不持有股票所得的最多现金
2.确定递推公式：dp[i][0] = max(dp[i-1][0], dp[i-1][1] - price[i]),
dp[i][1] = max(dp[i-1][1], dp[i-1][0] + price[i])
3.初始化：dp[0] = {-price[0], 0}
4.遍历顺序：从前往后
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        size = len(prices)
        if size == 1: return 0
        dp = [[0 for _ in range(2)] for _ in range(size)]
        dp[0][0] = -prices[0]
        for i in range(1, size):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])
        return max(dp[-1][0], dp[-1][1])
