/*
动态规划：01背包问题
此题中，数字既表示容量又表示价值，因此若能找到容量为总和一半的背包，求其所能装最大价值即可
1.确定dp含义：dp[i]表示背包容量为i所能接收物品的最大价值
2.递推公式：dp[i] = max(dp[i], dp[i-weight[j]]+value[j])
3.初始化：dp[0] = 0
4.遍历顺序：先遍历物品，再从后往前遍历容量
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[target];
    }
};