'''
动态规划
1.确定dp数组：dp[i]表示到达第i阶有dp[i]种方法
2.确定递推公式：dp[i] = dp[i-1] + dp[i-2]
3.如何初始化：dp[1] = 1, dp[2] = 2
4.遍历顺序：从前往后
时间复杂度：O(n)
空间复杂度：O(1)
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        if n<=2:
            return n
        dp = [1, 2]
        for i in range(3, n+1):
            sum = dp[0] + dp[1]
            dp[0] = dp[1]
            dp[1] = sum
        return dp[1]