/*
��̬�滮
1.ȷ��dp�����壺dp[i]��ʾ����Ϊi�ı����պ�װ�������п������
2.���ƹ�ʽ��dp[i] += dp[i-nums[j]](nums[j]��ʾ����һ����ѡ��Ʒnums[j])
3.��ʼ�������κ����ѡʱ��dp[0] = 1, ������Ϊ0
4.����˳�������Ʒ���ڲ������Ӵ�С
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if ((target + sum) % 2 != 0) return 0;
        if (abs(target) > sum) return 0;

        int pos = (target + sum) / 2;
        vector<int> dp(pos + 1, 0);
        dp[0] = 1;

        for (int j = 0; j < nums.size(); j++) {
            for (int i = pos; i >= nums[j]; i--) {
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[pos];
    }
};