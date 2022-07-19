/*
����ֻ�迼��[0, end-1]��[1, end]����������ֱ��ö�̬�滮
��̬�滮��
1.ȷ��dp���京�壺dp[i]��ʾ�±�i����(����i)�ķ��������͵��Ǯ
2.ȷ�����ƹ�ʽ��dp[i] = max(dp[i-1], dp[i-2]+nums[i])
3.��ʼ����dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
4.����˳�򣺴�ǰ����
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