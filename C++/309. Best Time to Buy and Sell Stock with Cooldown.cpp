/*
��̬�滮��
1.ȷ��dp���京�壺
dp[i][0]:��i����й�Ʊʱ������ֽ�
dp[i][1]:��i�죬�ȹ��䶳�ڵ�������Ʊ״̬����ʱ������ֽ�
dp[i][2]:��i�죬�պ�����������Ʊ����ʱ������ֽ�
dp[i][3]:��i��պ�Ϊ�䶳�ڣ���ʱ������ֽ�
2.���ƹ�ʽ��
dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3])-prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][3])
dp[i][2] = dp[i-1][0] + prices[i]
dp[i][3] = dp[i-1][2]
3.��ʼ����
dp[0][0] = -prices[0]
dp[0][1] = 0
dp[0][2] = 0
dp[0][3] = 0
4.����˳�򣺴�ǰ����
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