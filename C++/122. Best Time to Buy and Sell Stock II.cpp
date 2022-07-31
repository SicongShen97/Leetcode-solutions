/*
��̬�滮��
1.ȷ��dp���京��:dp[i][0]��ʾ��i����й�Ʊ���õ�����ֽ�dp[i][1]��ʾ��i�첻���й�Ʊ���õ�����ֽ�
2.ȷ�����ƹ�ʽ��dp[i][0] = max(dp[i-1][0], dp[i-1][1]-price[i]),
dp[i][1] = max(dp[i-1][1], dp[i-1][0] + price[i])
3.��ʼ����dp[0] = {-price[0], 0}
4.����˳�򣺴�ǰ����
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 1) return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};

/*
̰���㷨���ռ�ÿ���������
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};