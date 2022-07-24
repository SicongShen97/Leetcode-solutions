/*
动态规划：
1. 确定dp及其含义：dp[i][j]表示以nums1[i-1]以及nums2[j-1]为底的最长公共子序列
2. 递推公式：
if (nums1[i-1] == nums2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}else{
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
3. 初始化：dp[i][0] = 0, dp[0][j] = 0
4.遍历顺序：先nums1, 再nums2
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};