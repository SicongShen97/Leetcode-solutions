/*
��̬�滮��
1.dp���京�壺dp[i]��ʾi֮ǰ������i������nums[i]Ϊ��β����������������еĳ���
2.���ƹ�ʽ��
if (nums[i] > nums[i-1]){
    dp[i] = dp[i-1] + 1;
}
3.��ʼ����dp[i] = 1;
4.����˳�򣺴�ǰ����
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