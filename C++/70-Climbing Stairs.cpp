/*
��̬�滮
1.ȷ��dp���飺dp[i]��ʾ�����i����dp[i]�ַ���
2.ȷ�����ƹ�ʽ��dp[i] = dp[i-1] + dp[i-2]
3.��γ�ʼ����dp[1] = 1, dp[2] = 2
4.����˳�򣺴�ǰ����
ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷȣ�O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp[2];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 3; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

/*
��̬�滮����ȫ����(����)
1.ȷ��dp�����壺dp[i]��ʾ�պ�����i��¥��������
2.���ƹ�ʽ��dp[i] += dp[i - nums[j]]
3.��ʼ����dp[0] = 1, ����Ϊ0
4.����˳����ȫ������������С�������У��������ٲ���
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2; j++) {
                if (i >= j) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
