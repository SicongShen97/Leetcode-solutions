/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ��s[i-1], t[j-1]Ϊ�׵�������Ӵ�
2. ���ƹ�ʽ��
if (s[i-1] == t[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}else{
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
3. ��ʼ����dp[i][0] = 0, dp[0][j] = 0
4. ����˳����s��t����ǰ����
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        if (m == 0) return true;
        int n = t.size();
        if (n == 0) return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n] == m;
    }
};