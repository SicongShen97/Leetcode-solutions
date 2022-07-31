/*
动态规划：
1.dp及其含义：dp[i]表示以nums[i]为结尾的子序列的最大和
2.递推公式：dp[i] = max(nums[i], dp[i-1] + nums[i])
3.初始化：dp[0] = nums[0]
4.遍历顺序：从前往后
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

/*
贪心：当前连续和为负时，立刻放弃，从下一个元素开始计算连续和
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
};