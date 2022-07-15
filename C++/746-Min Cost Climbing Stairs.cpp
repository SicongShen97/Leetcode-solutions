/*
��̬�滮
1.ȷ��dp�ĺ��壺dp[i]��ʾ�����i��̨�׻��ѵ���С����
2.ȷ�����ƹ�ʽ��dp[i] = min(dp[i-2] + cost[i-3], dp[i-1] + cost[i-2])
3.dp��ʼ����dp[1] = 0, dp[2] = 0
4.����˳�򣺴�ǰ����
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[2] = { 0, 0 };
        for (int i = 3; i <= n + 1; i++) {
            int res = min(dp[0] + cost[i - 3], dp[1] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = res;
        }
        return dp[1];
    }
};