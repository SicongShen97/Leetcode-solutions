'''
动态规划
1.确定dp的含义：dp[i]表示到达第i个台阶花费的最小体力
2.确定递推公式：dp[i] = min(dp[i-2] + cost[i-3], dp[i-1] + cost[i-2])
3.dp初始化：dp[1] = 0, dp[2] = 0
4.遍历顺序：从前往后
'''
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0, 0]
        for i in range(3, n+2):
            res = min(dp[0] + cost[i-3], dp[1] + cost[i-2])
            dp[0] = dp[1]
            dp[1] = res
        return dp[1]