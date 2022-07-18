/*
��̬�滮����ȫ����
1.ȷ��dp���京�壺dp[i]��ʾ��ӵ�������i����Сƽ������Ŀ
2.���ƹ�ϵ��dp[i] = min(dp[i], dp[i-nums[j]]+1)
3.��ʼ����dp[0] = 0, ����ΪINT_MAX
4.����˳����ȫ������������С����������������
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i * i; j <= n; j++) {
                if (dp[j - i * i] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};