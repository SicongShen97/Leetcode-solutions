/*
动态规划：01背包
每个字符串为一物品，cost为"0","1"各自的含量，valus为1
1.确定dp及含义：dp[i][j]表示"0","1"最大容量分别为i，j的最多能容纳字符串的数量
2.确定递推关系: dp[i][j] = max(dp[i][j], dp[i-numZero][j-numOne]+1)
3.初始化：dp[i][j] = 0
4.遍历顺序：先遍历字符串，再遍历背包容量，从大到小
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int numZero = 0;
            int numOne = 0;
            for (char c : str) {
                if (c == '0') numZero += 1;
                else numOne += 1;
            }
            for (int i = m; i >= numZero; i--) {
                for (int j = n; j >= numOne; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - numZero][j - numOne] + 1);
                }
            }
        }
        return dp[m][n];
    }
};