/*
动态规划：
1.确定dp及其含义：
dp[i][0]:第i天持有股票时的最大现金
dp[i][1]:第i天，度过冷冻期的卖出股票状态，这时的最大现金
dp[i][2]:第i天，刚好这天卖出股票，这时的最大现金
dp[i][3]:第i天刚好为冷冻期，这时的最大现金
2.递推公式：
dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3])-prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][3])
dp[i][2] = dp[i-1][0] + prices[i]
dp[i][3] = dp[i-1][2]
3.初始化：
dp[0][0] = -prices[0]
dp[0][1] = 0
dp[0][2] = 0
dp[0][3] = 0
4.遍历顺序：从前往后
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 1) return 0;
        vector<vector<int>> dp(len, vector<int>(4));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[len - 1][3], max(dp[len - 1][1], dp[len - 1][2]));
    }
};