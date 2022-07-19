/*
本题只需考虑[0, end-1]及[1, end]两种情况，分别用动态规划
动态规划：
1.确定dp及其含义：dp[i]表示下标i以内(包括i)的房屋最多能偷的钱
2.确定递推公式：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
3.初始化：dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
4.遍历顺序：从前往后
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int res1 = robRange(nums, 0, nums.size() - 2);
        int res2 = robRange(nums, 1, nums.size() - 1);
        return max(res1, res2);
    }
    int robRange(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        int dp1 = nums[start];
        int dp2 = max(nums[start + 1], nums[start]);
        for (int i = start + 2; i <= end; i++) {
            int temp = max(dp2, dp1 + nums[i]);
            dp1 = dp2;
            dp2 = temp;
        }
        return dp2;
    }
};