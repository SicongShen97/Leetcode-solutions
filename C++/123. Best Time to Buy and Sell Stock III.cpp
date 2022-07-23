/*
��̬�滮��
1.ȷ��dp���京��:
dp[i][0]:��i���޲���
dp[i][1]����i���һ�γ�����ʣ������ֽ�
dp[i][2]����i���һ�γ�����ʣ������ֽ�
dp[i][3]����i��ڶ��γ�����ʣ������ֽ�
dp[i][4]����i��ڶ��γ�����ʣ������ֽ�
2.���ƹ�ʽ��
dp[i][0] = dp[i-1][0]
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
3.��ʼ����
dp[0][0] = 0
dp[0][1] = -prices[0]
dp[0][2] = 0
dp[0][3] = -prices[0]
dp[0][4] = 0
4.����˳��
��ǰ����
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 1) return 0;
        vector<vector<int>> dp(len, vector<int>(5));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[len - 1][4];
    }
};