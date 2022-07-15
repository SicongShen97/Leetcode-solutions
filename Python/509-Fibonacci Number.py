"""
动态规划
1.确定dp数组以及下标的含义: 第i个数的斐波那契数值是dp[i]
2.确定递推公式: dp[i] = dp[i - 1] + dp[i - 2]
3.dp数组如何初始化: dp[0] = 0, dp[1] = 1
4.确定遍历顺序：从前到后遍历
5.举例推导dp数组
时间复杂度：O(n)
空间复杂度：O(1)
"""
class Solution:
    def fib(self, n: int) -> int:
        if n<=1: return n
        dp = [0, 1]
        for i in range(2, n+1):
            sum = dp[0] + dp[1]
            dp[0] = dp[1]
            dp[1] = sum
        return dp[1]


"""
递归
1.递归关系
2.终止条件
时间复杂度：O(2^n)
空间复杂度：O(n)，算上了编程语言中实现递归的系统栈所占空间
"""
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1: return n
        return self.fib(n - 1) + self.fib(n - 2)
