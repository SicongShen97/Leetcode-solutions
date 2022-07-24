/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ��text1[i-1], text2[j-1]��β��������Ӵ�����
2. ���ƹ�ʽ��
if (text1[i-1] == text2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}else{
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
3. ��ʼ����dp[i][0] = 0, dp[0][j] = 0
4. ����˳����text1��text2����ǰ����
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};