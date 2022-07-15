/*
��̬�滮
1.ȷ��dp���飺dp[i]��ʾ�����i����dp[i]�ַ���
2.ȷ�����ƹ�ʽ��dp[i] = dp[i-1] + dp[i-2]
3.��γ�ʼ����dp[1] = 1, dp[2] = 2
4.����˳�򣺴�ǰ����
ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷȣ�O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

