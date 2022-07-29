'''
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
'''
class Solution:
    def countSubstrings(self, s: str) -> int:
        dp = [[False for _ in range(len(s))] for _ in range(len(s))]
        result = 0
        for i in range(len(s)-1, -1, -1):
            for j in range(i, len(s)):
                if s[i] == s[j]:
                    if j-i <= 1:
                        dp[i][j] = True
                        result += 1
                    elif dp[i+1][j-1]:
                        dp[i][j] = True
                        result += 1
        return result