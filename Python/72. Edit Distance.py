'''
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
'''
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m+1):
            dp[i][0] = i
        for j in range(n+1):
            dp[0][j] = j
        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    add = dp[i][j-1] + 1
                    dele = dp[i-1][j] + 1
                    rep = dp[i-1][j-1] + 1
                    dp[i][j] = min(add, dele, rep)
        return dp[-1][-1]