/*
��̬�滮��01��������
�����У����ּȱ�ʾ�����ֱ�ʾ��ֵ����������ҵ�����Ϊ�ܺ�һ��ı�����ʹ������װ����ֵҲΪ�ܺ�һ�룬�򷵻�true
1.ȷ��dp���壺dp[i]��ʾ��������Ϊi���ܽ�����Ʒ������ֵ
2.���ƹ�ʽ��dp[i] = max(dp[i], dp[i-weight[j]]+value[j])
3.��ʼ����dp[0] = 0
4.����˳���ȱ�����Ʒ���ٴӺ���ǰ��������
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % 2 == 1) return false;
        vector<int> dp(sum / 2 + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum / 2; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum / 2] == sum / 2;
    }
};