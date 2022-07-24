/*
动态规划：
1.dp及其含义：dp[i]表示i之前（包括i）且以nums[i]结尾的最长递增子序列
2.递推公式:
for (int j=0; j<i; j++){
    if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
}
3.初始化：dp[i] = 1
4.遍历顺序：从前往后
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1; 
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};