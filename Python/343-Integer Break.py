'''
动态规划
1.确定dp含义：dp[i]表示整数i的最大整数分解积
2.递推公式：for (int j=2; j<i; j++){
                dp[i] = max(max(j*(i-j), j*dp[i-j]), dp[i]);
            }
3.dp初始化：dp[2] = 1, dp[3] = 2
4.递推顺序：从前往后
'''
class Solution:
    def integerBreak(self, n: int) -> int:
        if n<=3:
            return n-1
        dp = [0]*(n+1)
        dp[2] = 1
        dp[3] = 2
        for i in range(4, n+1):
            res = 0
            for j in range(2, i):
                res = max(res, j*(i-j), j*dp[i-j])
            dp[i] = res
        return dp[n]