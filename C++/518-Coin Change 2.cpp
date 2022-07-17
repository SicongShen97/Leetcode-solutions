/*
��̬�滮����ȫ����
1.ȷ��dp���京�壺dp[i]��ʾ�����պ�Ϊi������������
2.���ƹ�ʽ��dp[i] += dp[i - coins[i]]
3.��ʼ����dp[0]=1, ����Ϊ0
4.����˳����Ϊ������⣬����Ʒ����������С������Ϊ�������⣬��������С��������Ʒ
����Ϊ�������
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};