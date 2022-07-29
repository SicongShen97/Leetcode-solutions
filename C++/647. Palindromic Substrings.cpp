/*
动态规划：
1. dp及其含义：dp[i][j]表示字符串在区间[i,j]的子字符串是否为回文
2. 递推公式：
if (s[i] == s[j]){
    if(j-i <= 1){
        dp[i][j] = true;
        result++;
    }
    else if(dp[i+1][j-1]){
        dp[i][j] = true;
        result++;
    }
}
3. 初始化：dp[i][j] = false
4. 遍历顺序：从下到上，从左至右
*/
class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 1) return 1;
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        result++;
                    }
                    else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    }
};