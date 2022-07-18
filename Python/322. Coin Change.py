'''
动态规划：完全背包（组合）
1.确定dp及其含义：dp[i]表示刚好凑满i元所需的最少硬币数
2.递推公式：dp[i] = min(dp[i], dp[i-coins[j]] + 1)
3.初始化：dp[0] = 0，其余为INT_MAX
4.遍历顺序：完全背包：容量从小到大， 组合：先硬币再容量
'''
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount+1]*(amount+1)
        dp[0] = 0
        for coin in (coins):
            for j in range(coin, amount+1):
                dp[j] = min(dp[j], dp[j-coin] + 1)
        return dp[-1] if dp[-1] != amount+1 else -1