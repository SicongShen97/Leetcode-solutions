/*
��̬�滮��
1.ȷ��dp���京��:
dp[i][0]:��i���޲���
dp[i][2*j - 1]����i���j�γ�����ʣ������ֽ�
dp[i][2*j]����i���j�γ�����ʣ������ֽ�
2.���ƹ�ʽ��
dp[i][0] = dp[i-1][0]
for (int j=1; j<=k; j++){
    dp[i][2*j - 1] = max(dp[i-1][2*j - 1], dp[i-1][2*j - 2] - prices[i])
    dp[i][2*j] = max(dp[i-1][2*j], dp[i-1][2*j - 1] + prices[i])
}
3.��ʼ����
dp[0][0] = 0
for (int j=1; j<=k; j++){
    dp[0][2*j - 1] = -prices[0]
    dp[0][2*j] = 0
}
4.����˳�򣺴�ǰ����
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) return 0;
        vector<vector<int>> dp(len, vector<int>(2 * k + 1));
        for (int j = 1; j <= k; j++) {
            dp[0][2 * j - 1] = -prices[0];
        }
        for (int i = 1; i < len; i++) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= k; j++) {
                dp[i][2 * j - 1] = max(dp[i - 1][2 * j - 1], dp[i - 1][2 * j - 2] - prices[i]);
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] + prices[i]);
            }
        }
        return dp[len - 1][2 * k];
    }
};