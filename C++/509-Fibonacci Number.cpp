//动态规划
//1.确定dp数组以及下标的含义: 第i个数的斐波那契数值是dp[i]
//2.确定递推公式: dp[i] = dp[i - 1] + dp[i - 2]
//3.dp数组如何初始化: dp[0] = 0, dp[1] = 1
//4.确定遍历顺序：从前到后遍历
//5.举例推导dp数组
//时间复杂度：O(n)
//空间复杂度：O(1)

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

//递归
// 1.递归关系
// 2.终止条件
// 时间复杂度：O(2^n)
// 空间复杂度：O(n)，算上了编程语言中实现递归的系统栈所占空间
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};