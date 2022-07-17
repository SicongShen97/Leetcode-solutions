/*
动态规划：完全背包
1.确定dp及其含义：dp[i]表示容量刚好为i的所有组合情况
2.递推公式：dp[i] += dp[i - coins[i]]
3.初始化：dp[0]=1, 其余为0
4.遍历顺序：若为组合问题，先物品，再容量从小到大；若为排列问题，先容量从小到大，再物品
本题为排列问题
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= i && dp[i] < INT_MAX - dp[i - nums[j]]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};