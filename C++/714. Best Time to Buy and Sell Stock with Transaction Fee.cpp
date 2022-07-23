/*
��̬�滮��
1.ȷ��dp���京�壺
dp[i][0]:��i��Ϊ���й�Ʊ״̬ʱ����������ֽ�
dp[i][1]:��i��Ϊ������Ʊ״̬ʱ����������ֽ�
2.���ƹ�ʽ��
dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee)
3.��ʼ����
dp[0][0] = -prices[0]
dp[0][1] = 0
4.����˳�򣺴�ǰ����
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