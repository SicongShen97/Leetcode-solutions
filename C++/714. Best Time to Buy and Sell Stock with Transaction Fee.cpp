/*
动态规划：
1.确定dp及其含义：
dp[i][0]:第i天为持有股票状态时的手上最大现金
dp[i][1]:第i天为卖出股票状态时的手上最大现金
2.递推公式：
dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee)
3.初始化：
dp[0][0] = -prices[0]
dp[0][1] = 0
4.遍历顺序：从前往后
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};