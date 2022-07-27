/*
动态规划：
1. dp及其含义：dp[i][j]表示以s[i-1], t[j-1]为底的最长公共子串
2. 递推公式：
if (s[i-1] == t[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}else{
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
3. 初始化：dp[i][0] = 0, dp[0][j] = 0
4. 遍历顺序：先s再t，从前往后
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