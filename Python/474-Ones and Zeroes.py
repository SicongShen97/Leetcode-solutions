'''
动态规划：01背包
每个字符串为一物品，cost为"0","1"各自的含量，valus为1
1.确定dp及含义：dp[i][j]表示"0","1"最大容量分别为i，j的最多能容纳字符串的数量
2.确定递推关系: dp[i][j] = max(dp[i][j], dp[i-numZero][j-numOne]+1)
3.初始化：dp[i][j] = 0
4.遍历顺序：先遍历字符串，再遍历背包容量，从大到小
'''
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for str in strs:
            numZero = str.count('0')
            numOne = str.count('1')
            for i in range(m, numZero-1, -1):
                for j in range(n, numOne-1, -1):
                    dp[i][j] = max(dp[i][j], dp[i-numZero][j-numOne] + 1)
        return dp[m][n]