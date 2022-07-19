/*
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
        int dp1 = nums[0];
        int dp2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int temp = max(dp2, dp1 + nums[i]);
            dp1 = dp2;
            dp2 = temp;
        }
        return dp2;
    }
};