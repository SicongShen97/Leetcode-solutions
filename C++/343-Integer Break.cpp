/*
动态规划
1.确定dp含义：dp[i]表示整数i的最大整数分解积
2.递推公式：for (int j=2; j<=i/2; j++){
                dp[i] = max(max(j*(i-j), j*dp[i-j]), dp[i]);
            }
3.dp初始化：dp[2] = 1, dp[3] = 2
4.递推顺序：从前往后
*/
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        vector<int> dp(n + 1);
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i <= n; i++) {
            int res = 0;
            for (int j = 2; j <= i / 2; j++) {
                res = max(max(j * (i - j), j * dp[i - j]), res);
            }
            dp[i] = res;
        }
        return dp[n];
    }
};