/*
动态规划
1.确定dp含义：dp[i][j]表示到达(i, j)处的所有不同路径
2.递推公式：dp[i][j] = dp[i-1][j] + dp[i][j-1]
3.初始化：dp[0][:] = 1 dp[:][0] = 1
4.遍历顺序：层序遍历，从左至右
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int j = 0; j < m; j++) dp[j][0] = 1;
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};