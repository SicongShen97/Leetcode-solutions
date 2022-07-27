/*
动态规划：
1. dp及其含义：dp[i][j]表示以s[i-1]为底的字符串的子序列中出现以t[j-1]为底的字符串的个数
2. 递推公式：
s[i-1]==t[j-1]时分俩情况，s[i-1]匹配t[j-1]或s[i-1]之前的匹配
if (s[i-1] == t[j-1]){
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
}else{
    dp[i][j] = dp[i-1][j];
}
3. 初始化：dp[i][0] = 1, dp[0][j] = 0
4. 遍历顺序：先s再t，从前往后
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