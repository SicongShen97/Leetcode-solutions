/*
动态规划：完全背包（组合）
1.确定dp及其含义：dp[i]表示刚好凑满i元所需的最少硬币数
2.递推公式：dp[i] = min(dp[i], dp[i-coins[j]] + 1)
3.初始化：dp[0] = 0，其余为INT_MAX
4.遍历顺序：完全背包：容量从小到大， 组合：先硬币再容量
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] == INT_MAX) continue;
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};