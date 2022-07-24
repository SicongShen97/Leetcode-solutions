/*
动态规划：
1.dp及其含义：dp[i]表示i之前（包括i）且以nums[i]为结尾的最长连续递增子序列的长度
2.递推公式：
if (nums[i] > nums[i-1]){
    dp[i] = dp[i-1] + 1;
}
3.初始化：dp[i] = 1;
4.遍历顺序：从前往后
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};