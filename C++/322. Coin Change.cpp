/*
��̬�滮����ȫ��������ϣ�
1.ȷ��dp���京�壺dp[i]��ʾ�պô���iԪ���������Ӳ����
2.���ƹ�ʽ��dp[i] = min(dp[i], dp[i-coins[j]] + 1)
3.��ʼ����dp[0] = 0������ΪINT_MAX
4.����˳����ȫ������������С���� ��ϣ���Ӳ��������
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};