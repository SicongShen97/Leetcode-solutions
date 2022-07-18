/*
动态规划：完全背包
1.确定dp及其含义：dp[i]表示相加等于数字i的最小平方数数目
2.递推关系：dp[i] = min(dp[i], dp[i-nums[j]]+1)
3.初始化：dp[0] = 0, 其余为INT_MAX
4.遍历顺序：完全背包：容量从小到大，先数字在容量
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                if (dp[j - i * i] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};