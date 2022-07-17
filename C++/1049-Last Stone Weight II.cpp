/*
��̬�滮��01��������
�����У����ּȱ�ʾ�����ֱ�ʾ��ֵ����������ҵ�����Ϊ�ܺ�һ��ı�������������װ����ֵ����
1.ȷ��dp���壺dp[i]��ʾ��������Ϊi���ܽ�����Ʒ������ֵ
2.���ƹ�ʽ��dp[i] = max(dp[i], dp[i-weight[j]]+value[j])
3.��ʼ����dp[0] = 0
4.����˳���ȱ�����Ʒ���ٴӺ���ǰ��������
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[target];
    }
};