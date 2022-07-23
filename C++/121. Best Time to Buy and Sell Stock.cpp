/*
动态规划：
1.确定dp及其含义:dp[i][0]表示第i天持有股票所得的最多现金，dp[i][1]表示第i天不持有股票所得的最多现金
2.确定递推公式：dp[i][0] = max(dp[i-1][0], -price[i]),
dp[i][1] = max(dp[i-1][1], dp[i-1][0] + price[i])
3.初始化：dp[0] = {-price[0], 0}
4.遍历顺序：从前往后
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 1) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};