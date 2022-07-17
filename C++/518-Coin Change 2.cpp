/*
动态规划：完全背包
1.确定dp及其含义：dp[i]表示容量刚好为i的所有组合情况
2.递推公式：dp[i] += dp[i - coins[i]]
3.初始化：dp[0]=1, 其余为0
4.遍历顺序：若为组合问题，先物品，再容量从小到大；若为排列问题，先容量从小到大，再物品
本题为组合问题
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};