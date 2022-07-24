/*
��̬�滮��
1.dp���京�壺dp[i]��ʾi֮ǰ������i������nums[i]��β�������������
2.���ƹ�ʽ:
for (int j=0; j<i; j++){
    if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
}
3.��ʼ����dp[i] = 1
4.����˳�򣺴�ǰ����
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