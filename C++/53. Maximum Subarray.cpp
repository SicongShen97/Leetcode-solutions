/*
��̬�滮��
1.dp���京�壺dp[i]��ʾ��nums[i]Ϊ��β�������е�����
2.���ƹ�ʽ��dp[i] = max(nums[i], dp[i-1] + nums[i])
3.��ʼ����dp[0] = nums[0]
4.����˳�򣺴�ǰ����
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