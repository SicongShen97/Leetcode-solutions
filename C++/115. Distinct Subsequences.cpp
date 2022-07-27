/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ��s[i-1]Ϊ�׵��ַ������������г�����t[j-1]Ϊ�׵��ַ����ĸ���
2. ���ƹ�ʽ��
s[i-1]==t[j-1]ʱ���������s[i-1]ƥ��t[j-1]��s[i-1]֮ǰ��ƥ��
if (s[i-1] == t[j-1]){
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
}else{
    dp[i][j] = dp[i-1][j];
}
3. ��ʼ����dp[i][0] = 1, dp[0][j] = 0
4. ����˳����s��t����ǰ����
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};