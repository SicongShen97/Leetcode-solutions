/*
动态规划：
1.dp及其含义：
dp[i][0]:以nums[i]为底且nums[i]为谷的最长摆动子序列
dp[i][1]:以nums[i]为底且nums[i]为峰的最长摆动子序列
2.递推公式：
for (int j=0; j<i; j++){
    if (nums[i] > nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
    if (nums[i] < nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
}
3.初始化：dp[i][0] = 1, dp[i][1] = 1
4.遍历顺序：从前往后
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                if (nums[i] < nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            res = max(dp[i][0], dp[i][1]);
        }
        return res;
    }
};

/*
贪心算法：
局部最优：删除单调坡上的节点，不包括两端，则得到两个极值
*/
/*
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int pre = 0;
        int cur = 0;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            cur = nums[i] - nums[i - 1];
            if ((cur > 0 && pre <= 0) || (cur < 0 && pre >= 0)) {
                res += 1;
                pre = cur;
            }
        }
        return res;
    }
};
*/