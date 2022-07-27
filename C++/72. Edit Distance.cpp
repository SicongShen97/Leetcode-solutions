/*
动态规划：
1. dp及其含义：dp[i][j]表示以word1[i-1]为底的字符串和以word2[j-1]为底的字符串的最小编辑距离
2. 递推公式：
if (word1[i-1] == word2[j-1]){
    dp[i][j] = dp[i-1][j-1];
}else{
    //删
    int del = dp[i-1][j] + 1;
    //增,相当于word2删
    int add = dp[i][j-1] + 1;
    //改
    int rep = dp[i-1][j-1] + 1;
    //取min
    dp[i][j] = min({del, add, rep});
}
3. 初始化：dp[i][0] = i, dp[0][j] = j
4. 遍历顺序：先word1再word2，从前往后
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int add = dp[i][j - 1] + 1;
                    int del = dp[i - 1][j] + 1;
                    int rep = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min({ add, del, rep });
                }
            }
        }
        return dp[m][n];
    }
};