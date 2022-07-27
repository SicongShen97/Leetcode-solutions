'''
动态规划：
1. dp及其含义：dp[i][j]表示以word1[i-1]为底及以word2[j-1]为底的俩字符串的最长公共子串
2. 递推公式：
if (word1[i-1] == word2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}else{
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
3. 初始化：dp[i][0] = 0, dp[0][j] = 0
4. 遍历顺序：先word1再word2，从前往后
'''
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return m + n - 2*dp[-1][-1]