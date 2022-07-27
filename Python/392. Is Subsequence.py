'''
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
'''
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        m = len(s)
        if m == 0: return True
        n = len(t)
        if n == 0: return False
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[m][n] == m