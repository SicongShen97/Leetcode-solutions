/*
动态规划：01背包问题
此题中，数字既表示容量又表示价值，因此若能找到容量为总和一半的背包，使其所能装最大价值也为总和一半，则返回true
1.确定dp含义：dp[i]表示背包容量为i所能接收物品的最大价值
2.递推公式：dp[i] = max(dp[i], dp[i-weight[j]]+value[j])
3.初始化：dp[0] = 0
4.遍历顺序：先遍历物品，再从后往前遍历容量
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % 2 == 1) return false;
        vector<int> dp(sum / 2 + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum / 2; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum / 2] == sum / 2;
    }
};