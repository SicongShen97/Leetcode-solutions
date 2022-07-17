/*
动态规划
1.确定dp含义：dp[i]表示i个整数所有BST可能情况
2.递推公式：
根据根节点不同分为i种情况，都想加：dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] + ... + dp[i-1]*dp[0]
3.初始化：dp[0] = 1
4.递推顺序：从前向后
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            int res = 0;
            for (int j = 0; j < i; j++) {
                res += dp[j] * dp[i - j - 1];
            }
            dp[i] = res;
        }
        return dp[n];
    }
};