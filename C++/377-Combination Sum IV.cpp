/*
��̬�滮����ȫ����
1.ȷ��dp���京�壺dp[i]��ʾ�����պ�Ϊi������������
2.���ƹ�ʽ��dp[i] += dp[i - coins[i]]
3.��ʼ����dp[0]=1, ����Ϊ0
4.����˳����Ϊ������⣬����Ʒ����������С������Ϊ�������⣬��������С��������Ʒ
����Ϊ��������
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= i && dp[i] < INT_MAX - dp[i - nums[j]]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};