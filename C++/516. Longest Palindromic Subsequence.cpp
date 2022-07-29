/*
动态规划：
1. dp及其含义：dp[i][j]表示[i,j]区间的字符串的最长回文子串
2. 递推公式：
if (s[i] == s[j]){
    if (j-i <= 1){
        dp[i][j] = j-i+1;
    }else{
        dp[i][j] = dp[i+1][j-1] + 2;
    }
}else{
    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
}
3. 初始化：dp[i][j] = 0;
4.遍历顺序：从下到上，从左到右
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = j - i + 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};