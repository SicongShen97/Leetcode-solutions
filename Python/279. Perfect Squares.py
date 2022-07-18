'''
动态规划：完全背包
1.确定dp及其含义：dp[i]表示相加等于数字i的最小平方数数目
2.递推关系：dp[i] = min(dp[i], dp[i-nums[j]]+1)
3.初始化：dp[0] = 0, 其余为INT_MAX
4.遍历顺序：完全背包：容量从小到大，先数字在容量
'''
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [n+1]*(n+1)
        dp[0] = 0
        nums = [i**2 for i in range(1, 101) if i**2<=n]
        for num in nums:
            for i in range(num, n+1):
                dp[i] = min(dp[i], dp[i-num] + 1)
        return dp[-1]