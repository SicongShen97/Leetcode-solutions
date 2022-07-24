/*
动态规划：
1. dp及其含义：dp[i][j]表示以nums1[i-1], nums2[j-1]结尾的最长重复子串
2. 递推公式：
if (nums1[i-1] == nums2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}
3. 初始化：dp[0][j] = 0, dp[i][0] = 0
4. 遍历顺序：先nums1再nums2, 从前往后
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};