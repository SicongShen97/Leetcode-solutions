'''
动态规划
1.确定dp含义：dp[i][j]表示到达(i, j)处的所有不同路径
2.递推公式：dp[i][j] = dp[i-1][j] + dp[i][j-1]
3.初始化：dp[0][:] = 1 dp[:][0] = 1
4.遍历顺序：层序遍历，从左至右
'''
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]