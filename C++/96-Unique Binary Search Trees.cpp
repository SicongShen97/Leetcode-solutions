/*
��̬�滮
1.ȷ��dp���壺dp[i]��ʾi����������BST�������
2.���ƹ�ʽ��
���ݸ��ڵ㲻ͬ��Ϊi�����������ӣ�dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] + ... + dp[i-1]*dp[0]
3.��ʼ����dp[0] = 1
4.����˳�򣺴�ǰ���
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            int res = 0;
            for (int j = 0; j < i; j++) {
                res += dp[j] * dp[i - j - 1];
            }
            dp[i] = res;
        }
        return dp[n];
    }
};