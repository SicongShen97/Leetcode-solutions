/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ��word1[i-1]Ϊ�׼���word2[j-1]Ϊ�׵����ַ�����������Ӵ�
2. ���ƹ�ʽ��
if (word1[i-1] == word2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}else{
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
3. ��ʼ����dp[i][0] = 0, dp[0][j] = 0
4. ����˳����word1��word2����ǰ����
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};