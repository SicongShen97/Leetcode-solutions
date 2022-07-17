/*
��̬�滮
1.ȷ��dp���壺dp[i]��ʾ����i����������ֽ��
2.���ƹ�ʽ��for (int j=2; j<=i/2; j++){
                dp[i] = max(max(j*(i-j), j*dp[i-j]), dp[i]);
            }
3.dp��ʼ����dp[2] = 1, dp[3] = 2
4.����˳�򣺴�ǰ����
*/
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        vector<int> dp(n + 1);
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            int res = 0;
            for (int j = 2; j <= i / 2; j++) {
                res = max(max(j * (i - j), j * dp[i - j]), res);
            }
            dp[i] = res;
        }
        return dp[n];
    }
};