/*
动态规划
1.确定dp及含义：dp[i]表示容量为i的背包刚好装满的所有可能情况
2.递推公式：dp[i] += dp[i-nums[j]](nums[j]表示新增一个可选物品nums[j])
3.初始化：无任何物可选时，dp[0] = 1, 其他均为0
4.遍历顺序：外层物品，内层容量从大到小
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if ((target + sum) % 2 != 0) return 0;
        if (abs(target) > sum) return 0;

        int pos = (target + sum) / 2;
        vector<int> dp(pos + 1, 0);
        dp[0] = 1;

        for (int j = 0; j < nums.size(); j++) {
            for (int i = pos; i >= nums[j]; i--) {
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[pos];
    }
};